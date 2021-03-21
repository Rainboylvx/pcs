/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 18日 星期四 14:23:36 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int s;
int h;
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

int dis[maxn];
bool vis[maxn];
int ans = 1;
void bfs(){
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    vis[s] = 1;
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        for(int i = e.h[u]; i!=-1 ;i = e[i].next){
            int v = e[i].v;
            if( vis[v] == 0){
                vis[v] = 1;
                dis[v] = dis[u] +1;
                q.push(v);
                ans = max(ans,dis[v]);
            }
        }
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&s);
    scanf("%d",&h);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e.add2(u,v);
    }
    bfs();
    /*
     *for(int i=1;i<=n;++i){
     *    printf("%d %d\n",i,dis[i]);
     *}
     */

    printf("%d",ans+h);
    return 0;
}
