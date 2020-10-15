/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 08月 17日 星期一 19:37:12 CST
* problem: loj-146
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif


template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch < '0' || ch > '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m,r;
int a[maxn];
int st[maxn],ed[maxn];
int f[maxn],dep[maxn];
int g[maxn][30];

struct BIT {
    typedef long long ll;
    ll c[maxn],siz=maxn;
    void init(){ memset(c,0,sizeof(c)); }
    inline ll lowbit(ll x){ return x &-x;}
    void update(ll pos,ll val){while(pos<=siz) c[pos]+=val,pos+=this->lowbit(pos);}
    ll query(ll pos){ll sum=0;while(pos>0) sum+=c[pos],pos-=lowbit(pos); return sum;}
};
BIT bit1,bit2;

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/

/* ======= 全局变量 END =======*/
void init(){
    xlx1::xlx_init(); 
    read(n); read(m); read(r);
    for(int i =1;i<=n;++i) read(a[i]);
    int u,v,i;
    For(i,1,n-1){
        read(u);read(v);
        xlx1::add(u,v);
    }
}

//建立dfs序
int dfn = 0;
void dfs_seq(int u,int fa,int d){
    f[u] = fa;
    g[u][0] = fa;
    int i,j;
    st[u] = ++dfn;
    dep[u] = d;

    for(i=1;i<=20;i++)
        g[u][i] = g[ g[u][i-1]][i-1];

    for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
        int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
        if( v == fa) continue;
        dfs_seq(v,u,d+1);
    }
    ed[u] = dfn;
}

int lca(int u,int v){
    if( dep[u] < dep[v]) swap(u,v);
    if( st[v] <= st[u] && ed[v] >= ed[u]) return v;
    for(int i = 20;i>=0;i--){
        int t = g[u][i];
        if( t == 0) continue;
        if( st[t] <= st[v] && ed[t] >=ed[v]) continue;
        u = g[u][i];
    }
    return f[u];
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dfs_seq(r,0,1);
    int i,j,k;

    bit1.init();
    bit2.init();
    for(i=1;i<=n;++i){
        bit1.update(st[i],a[i]);
        if(i != r) bit1.update(f[i], -a[i]); 
        bit2.update(st[i],dep[i]*a[i]);
    }

    int opt,x,y,z;

    for(i=1;i<=m;++i){
        read(opt);
        if( opt == 1){
            read(x); read(y); read(z);
            //printf("%d %d %d\n",x,y,lca(x,y));
            int l = lca(x,y);
            bit1.update(st[x], z);
            bit1.update(st[y], z);
            bit1.update(st[l], -z);
            if( l != r) bit1.update(st[f[l]], -z);

            bit2.update(st[x], z*dep[x]);
            bit2.update(st[y], z*dep[y]);
            bit2.update(st[l], -z*dep[l]);
            if( l != r) bit1.update(st[f[l]], -z*dep[f[l]]);

        }
        else if (opt == 2){
            read(x);
            int ans = bit1.query(ed[x]) - bit1.query(st[x]);
            printf("%d\n",ans);
        }
        else {
            read(x);
        }
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
