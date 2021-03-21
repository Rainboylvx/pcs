/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 19日 星期五 14:05:06 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int cnt;
/* 定义全局变量 */
bool is_line = 0;

int read(){
    int a = 0,flag = 1;
    char c;
    scanf("%c",&c);
    while ( c< '0' || c>'9' ){
        if(c == '-') flag = -1;
        scanf("%c",&c);
    }
    int ret;
    while ( c>='0' && c<='9' ) {
        a = a*10 + c-'0';
        ret = scanf("%c",&c);
    }
    is_line = c == '\n' || ret == EOF;
    return a*flag;
}
struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){	//构造函数
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    void add(int u,int v,int w=0){
        e[edge_cnt] = {u,v,w,h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u,int v,int w=0){
        add(u,v,w);
        add(v,u,w);
    }
    edge& operator[](int i){
        return e[i];
    }
} e;

vector<int> h[501]; // 点i在哪条线上

struct Dijkstra {
    int dis[maxn];
    bool vis[maxn];
    typedef pair<int,int> P; //第一个存dis，第二个存点编号
    priority_queue<P,vector<P>,greater<P>> q; //优先队列
    Dijkstra(){ //格构函数
        memset(dis,0x7f,sizeof(dis)); //所有的点都是0x7f7f7f7f 代表无穷大
        memset(vis,0,sizeof(vis));    //所有点都是没有标记的
        //注意这里起点也未标记的
    }

    void work(int s){
        dis[s] = 0; 
        q.push(make_pair(0, s)); //把起点加入

        while ( !q.empty() ) { //当优先队列不空时
            int u = q.top().second;
            q.pop();
            if( vis[u] ) continue; //这个点已经标记过了，什么也不做
            vis[u] = 1; //标记这个点

            //用新标记的点去更新它周围的末标记点
            for(int i=e.h[u];~i;i=e[i].next){
                int &v = e[i].v, &w = e[i].w;
                if( vis[v] == 0 && dis[v] > dis[u]+w){
                    dis[v] = dis[u] + w;
                    q.push(make_pair(dis[v], v)); //新更新的点加入队列
                }
            }
        }
    }
} dijkstra;

int main(){
    m = read();
    n = read();
    cnt = n;
    vector<int> a;
    for(int i=1;i<=m;++i){
        a.clear();
        while ( 1 ) {
            is_line=0;
            int t = read();
            a.push_back(t);
            if( is_line ) break;
        }
        int pre = -1;
        for(int j =0;j<=a.size();j++){
            int ov = a[j],ev;
            if(h[ov].size()==0)
                ev = ov;
            else
                ev = ++cnt;
            for(int j = 0;j<h[ov].size();j++)
                e.add2(h[ov][j],ev,1);
            h[ov].push_back(ev);
            if( pre != -1)
                e.add(pre,ev,0);
            pre = ev;
        }
    }
    dijkstra.work(1);
    int ans = 0x7f7f7f7f;
    for(int i = 0;i<h[n].size();i++)
        ans = min(ans,dijkstra.dis[ h[n][i] ]);
    printf("%d",ans);
    return 0;
}
