/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 23日 星期六 22:37:21 CST
* problem: loj-10134
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/
using namespace xlx1;
void init(){
     xlx1::xlx_init(); 
     scanf("%d%d",&n,&m);
     int i;
     int u,v,w;
     For(i,1,n-1){
         scanf("%d%d%d",&u,&v,&w);
         add(u,v,w);
     }
}

namespace BZ_LCA {
    const int SIZ = 35;
    int f[maxn][SIZ+1],len[maxn][SIZ+1],dep[maxn];
    using namespace xlx1;
    void dfs_init(int u ,int d,int fa,int w){
        dep[u] = d; f[u][0] = fa; len[u][0] = w;
        for(int i= 1;i<=SIZ;++i){
            f[u][i] = f[f[u][i-1]][i-1];
            len[u][i] = len[u][i-1]+len[f[u][i-1]][i-1];
        }
        for(int i=head[u];~i;i=e[i].next){
            int v =e[i].v ,w = e[i].w;
            if( v == fa) continue;
            dfs_init(v,d+1,u,w);
        }
    }
    int find_lca(int u,int v){
        int sum = 0;
        if( dep[u] < dep[v]) swap(u,v); //保证u点的深度深
        for(int i=SIZ;i>=0;--i){
            if( dep[f[u][i]] < dep[v]) continue; //不跳的区域
            sum+=len[u][i];
            u = f[u][i];
        }
        if(u == v) return sum;
        for(int i=SIZ;i>=0;--i){
            if( f[u][i] == f[v][i] ) continue;
            sum+=len[u][i];
            sum+=len[v][i];
            u = f[u][i];
            v = f[v][i];
        }
        return sum+len[u][0]+len[v][0];
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    using namespace BZ_LCA;
    dfs_init(1,1,0,0);
    int i,u,v;
    For(i,1,m){
        scanf("%d%d",&u,&v);
        int ans = find_lca(u, v);
        printf("%d\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
