/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 04 Apr 2020 08:03:03 PM CST
* problem: loj-10130
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

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
using namespace xlx1;
/* ========= 向量星 1 END =========*/
/* ======= 全局变量 END =======*/

/* 初始化   LCA_JUMP::lca_init(点的数量)
 * 建立st表 LCA_JUMP::st_dfs(root,depth,father)
 * 查询lca  LCA_JUMP::find_lca(u,v)
 * 查询距离 LCA_JUMP::get_dis(u,v)
 * */
namespace LCA_JUMP {
    using namespace xlx1;
    const int DEPTH = 100;
    int d[maxn],f[maxn],p[maxn][30],MAX_DEPTH;
    void lca_init(int size=maxn){ MAX_DEPTH = int(log(size)/log(2));}

    void st_dfs(int u,int dep,int fa=0){
        p[u][0] = fa,d[u] = dep;
        for(int i = 1; i <= MAX_DEPTH ;i++) p[u][i] = p[ p[u][i-1]][i-1];
        for(int i= head[u]; ~i ;i = e[i].next) if( e[i].v != fa) st_dfs(e[i].v,dep+1,u);
    }

    int find_lca(int u,int v){
        if( d[u] > d[v]) std::swap(u,v); // 保证: v 是深度深的点
        for(int i = MAX_DEPTH;i>=0;i--) if( d[v] - (1<<i) >= d[u]) v = p[v][i];
        if( u == v) return u;
        for(int i = MAX_DEPTH;i>=0;i--) if( p[u][i] != p[v][i]) u = p[u][i], v= p[v][i];
        return p[v][0];
    }
    long long get_dis(int u,int v){
        long long sum = 0; if( d[u] > d[v]) std::swap(u,v); // 保证: v 是深度深的点
        for(int i = MAX_DEPTH;i>=0;i--) if( d[v] - (1<<i) >= d[u]) v = p[v][i],sum+=(1<<i);
        if( u == v) return sum;
        for(int i = MAX_DEPTH;i>=0;i--) if( p[u][i] != p[v][i]) u = p[u][i], v= p[v][i],sum+=(1<<i)<<1;
        return sum+2;
    }
}
using namespace LCA_JUMP;

void init(){
     xlx1::xlx_init(); 
     scanf("%d",&n);
     int i,u,v;
     For(i,1,n-1){
         scanf("%d%d",&u,&v);
         addEdge(u, v);
         addEdge(v, u);
     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    lca_init(n);
    st_dfs(1,1);
    scanf("%d",&m);
    int i,u,v;
    For(i,1,m){
        scanf("%d%d",&u,&v);
        printf("%d\n",find_lca(u,v));
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
