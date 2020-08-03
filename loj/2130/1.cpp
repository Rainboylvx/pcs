/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 24日 星期日 21:10:57 CST
* problem: loj-2130
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;
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
     scanf("%d",&n);
     int i,t;
     For(i,2,n){
         scanf("%d",&t);
         t++;
         add(i,t); //所有的点+1
     }
     scanf("%d",&m);
}

namespace SGT {
    /* =====  线段树区间更新--lazy [区间加,区间求和] ====*/
    /* 区间加,区间求和 的线段树 */
    struct node {
        int v;
        int flag=-1;
    }t[maxn];

    inline void _merge(node &a,node &b,node &c){ //合并
        a.v = b.v+c.v;
    }

    inline int lc(int o ){ return o<<1;}
    inline int rc(int o ){ return (o<<1)|1;}
    /* 更新父亲 */
    inline void pushup(int o){
        _merge( t[o] , t[lc(o)] , t[rc(o)]);
    }

    /* 向下更新标记 */
    void pushdown(int o,int m){
        if(t[o].flag !=-1 ){
            t[lc(o)].flag += t[o].flag;   //[改]
            t[rc(o)].flag += t[o].flag;   //[改]
            //[改]
            t[lc(o)].v += t[o].flag*(m-(m>>1));  /* 左孩子的值改变,上面有标记 */
            //[改]
            t[rc(o)].v += t[o].flag*(m>>1);  /* 右孩子的值改变,上面有标记 */
            t[o].flag = 0;
        }
    }
    /* 区间更新 -- lazy */
    void update(int l1,int r1,int c,int l,int r,int o){
        if(l1 <=l && r<=r1){
            t[o].flag += c; //我们到达一个点 [改]
            t[o].v += (r-l+1)*c; //[改]
            return ;
        }
        pushdown(o,(r-l+1)); //查看当前点对应标记树是不是有标记,如果有就往下压
        int m = (l+r)>>1;
        if( l1 <= m) update(l1,r1,c,l,m,lc(o));
        if( r1 > m) update(l1,r1,c,m+1,r,rc(o));
        pushup(o);
    }

    /* 区间查询 */
    int query(int l1,int r1,int l,int r,int o){
        if(l1<=l && r <= r1){//包含
            return t[o].v;
        }

        //路过
        pushdown(o,(r-l+1));
        int ret = 0;
        int m = (l+r)>>1;
        if(l1 <= m) ret+= query(l1,r1,l,m,lc(o));
        if(r1 > m ) ret+= query(l1,r1,m+1,r,rc(o));
        return ret;
    }

    /* 建立线段树 */
    void build(int l,int r,int o){
        if( l==r){
            scanf("%d",&t[o].v);
            return ;
        }
        int m = (l+r)>>1;
        build(l,m,lc(o));
        build(m+1,r,rc(o));
        pushup(o);
    }
#ifdef DEBUG
    void _dfs_print(ll l,ll r,ll o,FILE *dot){
        if( o >>1) fprintf(dot,"%d--%d;\n",o>>1,o);
        fprintf(dot,"%d[label=\"%d\"]\n",o,t[o].v);
        if( l == r) return;
        ll m = (l+r)>>1;
        _dfs_print(l,m,lc(o),dot);
        _dfs_print(m+1,r,rc(o),dot);
    }
    void sgt_2_dot(ll size,string name){
        FILE *dot = fopen(name.c_str(),"w");
        fprintf(dot,"graph g {\n node[shape=circle fixedsize=true style=filled fillcolor=white colorscheme=accent8 ];\n");
        _dfs_print(1,size,1,dot);
        fprintf(dot,"}");
    }
#endif
}
/* ====== 线段树区间更新--lazy-- END ====*/

// 求两个点之间的距离,边长1： dep[u]+dep[v] - 2*dep[lca(u,a)]
// 求两个点之间的距离,边长w： 用len
/* ================= 树链剖分-点权 BEG ======*/
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
/* ================= 树链剖分-点权 END ======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    HPSN::hps_init();
    init();
    HPSN::dfs1(1, 1, 0);
    HPSN::dfs2(1, 1);
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
