/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 17日 星期四 16:42:18 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
vector<int> y;
/* 定义全局变量 */

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

/* ============ dinic 最大流 BEG ============ */
struct Dinic {
    int s,t,dep[maxn],cur[maxn]; //起点，终点
    inline void set(int a,int b){s =a , t = b;}
    queue<int> q;
    bool bfs(){
        memset(dep,0,sizeof(dep));
        while( !q.empty()) q.pop();
        dep[s] = 1;
        q.push(s);
        for(int i=s;i<=t;++i) cur[i] = e.h[i];
        
        while ( !q.empty() ) {
            int u = q.front(); q.pop();
            for(int i=e.h[u];~i;i=e[i].next){
                int &v = e[i].v, &w = e[i].w;
                if( dep[v] == 0 && w != 0 ){
                    dep[v] = dep[u]+1;
                    q.push(v);
                }
            }
        }
        return dep[t]!=0;
    }
    //多路增广,当前弧优化
    int dfs(int u,int c){
        if( u == t ) return c;
        int used = 0;
        for(int &i=cur[u];~i;i=e[i].next){
            int &v = e[i].v, &w = e[i].w;
            if( dep[v] == dep[u]+1 && w !=0 ) {
                int tmp = dfs(v,min(c-used,w));
                if( tmp == 0 ) continue;
                used += tmp;
                e[i].w   -= tmp;
                e[i^1].w += tmp;
                if( used == c) return c;
            }
        }
        //从这个出发没有找到任何增广路
        //那不要从这个点就出发了
        if( used == 0) dep[u] = 0;
        return used;
    }
    int work(){
        int ans = 0;
        while ( bfs() ) 
            ans += dfs(s,0x7f7f7f7f);
        return ans;
    }
} dinic;
/* ============ dinic 最大流 END ============ */

int main(){
    scanf("%d%d",&n,&m);
    for(;;){
        int u,v;
        if( scanf("%d%d",&u,&v) == EOF ) break;
        e.add(u,v,1);
        e.add(v,u,0);
    }
    for(int i=1;i<=m;++i){
        e.add(0,i,1);
        e.add(i,0,0);
    }
    for(int i=m+1;i<=n;++i){
        e.add(i,n+1,1);
        e.add(n+1,i,0);
    }
    dinic.set(0,n+1);
    int ans = dinic.work();
    printf("%d",ans);

    return 0;
}
