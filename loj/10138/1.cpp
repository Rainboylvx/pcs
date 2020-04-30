/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 10:49:37 AM CST
* problem: loj-10138
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
int val[maxn];

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
using namespace xlx1;
/* ========= 向量星 1 END =========*/

/* =====  线段树区间更新--lazy [区间加,区间求和] ====*/

/* 区间加,区间求和 的线段树 */
struct node {long long sum,v;
    node operator+(const node &b){
        return {sum+b.sum,max(v,b.v)};
    }
};
node st[maxn<<2]={0};    //线段树
int flag[maxn<<2]={0};  //标记树
//memeset(flag,0/-1,sizeof(flag))

inline int lson(int rt ){ return rt<<1;}
inline int rson(int rt ){ return (rt<<1)|1;}
/* 更新父亲 */
void pushup(int rt){
    st[rt] = st[lson(rt)] + st[rson(rt)];
}
/* 单点更新*/
void update(int p,int c,int l,int r,int rt){
    if(l == r){
        st[rt].sum = st[rt].v =  c;
        return ;
    }
    int m = (l+r)>>1;
    if( p <= m) update(p,c,l,m,lson(rt));
    else update(p,c,m+1,r,rson(rt));
    pushup(rt);
}

/* 区间查询 */
node query(int l1,int r1,int l,int r,int rt){
    if(l1<=l && r <= r1){//包含
        return st[rt];
    }

    node ret = {0,-0x7f7f7f7f};
    int m = (l+r)>>1;
    if(l1 <= m) ret= ret+ query(l1,r1,l,m,lson(rt));
    if(r1 > m ) ret= ret+ query(l1,r1,m+1,r,rson(rt));
    return ret;
}

/* ====== 线段树区间更新--lazy-- END ====*/

namespace HPSN {
    using namespace xlx1;
    int fa[maxn],son[maxn],dep[maxn],size[maxn],top[maxn],p[maxn],   fp[maxn],dfn=0;
    /*  点的父亲 重儿子    深度      子树大小   链顶      点的新编号 p相反*/

    void hps_init(){ memset(son,-1,sizeof(son)); dfn=0;}
    void dfs1(int u,int d,int f){
        dep[u] = d,fa[u] = f,size[u] = 1;
        for( int i = head[u];~i ; i = e[i].next){
            if( e[i].v != f ){
                dfs1(e[i].v, d+1, u);
                size[u] += size[e[i].v];
                if( son[u] == -1 || size[e[i].v] > size[son[u]]) son[u] = e[i].v;
            }
        }
    }

    void dfs2(int u,int sf){
        p[u] = ++dfn, fp[p[u]] = u;
        top[u] = sf;
        if ( son[u] == -1) return;
        dfs2( son[u],sf); //先访问重儿子
        for(int i = head[u]; ~i ; i =e[i].next) if( e[i].v != son[u] && e[i].v != fa[u]) dfs2(e[i].v,e[i].v);
    }

    node find_lca(int u,int v){
        int f1 = top[u],f2 = top[v] ,tmp=0;
        node ret = {0,-0x7f7f7f7f};
        while( f1 != f2){
            if( dep[f1] < dep[f2]) std::swap(f1,f2),std::swap(u,v); //u是支链
            // p[f1] -- p[u] 这条边要改变
            // //[改]
            ret = ret + query(p[f1], p[u], 1, n, 1);
            u = fa[f1];f1 = top[u];
        }
        if( dep[u] > dep[v] ) std::swap(u,v);
        // p[u]--p[v] 这条边要改变
        // //[改]
        ret = ret + query(p[u], p[v], 1, n, 1);
        return ret;
    }
}
using namespace HPSN;


/* 建立线段树 */
int sgt_idx = 0;
void build(int l,int r,int rt){
    if( l==r){
        st[rt].sum = st[rt].v = val[fp[++sgt_idx] ];
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,lson(rt));
    build(m+1,r,rson(rt));
    pushup(rt);
}


void init(){
     xlx1::xlx_init(); 
     scanf("%d",&n);
     int i,u,v;
     For(i,1,n-1){
         scanf("%d%d",&u,&v);
         add(u,v);
     }
     For(i,1,n){
         scanf("%d",&val[i]);
     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    hps_init();
    dfs1(1, 1, 0);
    dfs2(1,1);
    build(1, n, 1); //建立线段树
    int i,x,y;
    char str[10]; char &s = str[0];
    scanf("%d",&m);
    For(i,1,m){
        scanf("%s",str);
        scanf("%d%d",&x,&y);
        if( s == 'C'){
            update(p[x], y, 1, n, 1);
        }
        else if( s == 'Q' && str[1] == 'M'){
            printf("%lld\n",find_lca(x, y).v);
        }
        else {
            printf("%lld\n",find_lca(x, y).sum);
        }
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
