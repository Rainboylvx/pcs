/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 12日 星期六 21:21:10 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

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

int Zeng;
bool vis[maxn];
bool dfs(int u, int E){
    vis[u] = 1;
    if( u == n ){
        vis[u] =0;
        Zeng = E;
        return 1;
    }
    for(int i=e.h[u];~i;i=e[i].next){
        int &v = e[i].v, &w = e[i].w;
        if( w == 0) continue;
        if( vis[v] )continue;
        if( dfs(v,min(w,E)) ){
            if( i & 1 ) { //奇数，末尾为1，i就反向边
                e[i].w += Zeng;
                e[i^1].w -= Zeng;
            }
            else {
                e[i].w -= Zeng;
                e[i^1].w += Zeng;
            }
            return 1;
        }
    }
    vis[u] = 0;
    return 0;
}


int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.add(u,v,w);
        e.add(v,u,0);
    }
    memset(vis,0,sizeof(vis));
    while( dfs(1,0x7f7f7f7f) ) {
        memset(vis,0,sizeof(vis));
    }

    ll ans = 0;


    for(int i=e.h[n];~i;i=e[i].next){
        int &v = e[i].v, &w = e[i].w;
        if( i & 1)
            ans += w;
    }
    //for(int i=0;i<e.edge_cnt;++i){
        //printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
    //}
    printf("%lld\n",ans);

    return 0;
}
