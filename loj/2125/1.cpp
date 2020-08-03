/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 24日 星期日 17:25:47 CST
* problem: loj-2125
*----------------*/
#include <bits/stdc++.h>
#define For(i,stao,end) for(i = stao ;i <= end; ++i)
#define Rof(i,stao,end) for(i = stao ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const ll maxn = 2e5+5;
const ll maxe = 1e6+5;
ll n,m;
ll a[maxn];
/* ========== 快读 ========== */
template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch < '0' || ch > '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}
/* ========== 快读 END ========== */

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    ll head[maxn],edge_cnt = 0;
    struct _e{ ll u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(ll u,ll v,ll w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(ll u,ll v,ll w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/
void init(){
     xlx1::xlx_init(); 
     read(n);read(m);
     ll i,u,v;
     For(i,1,n){
         read(a[i]);
     }
     using namespace xlx1;
     For(i,1,n-1){
         read(u);read(v);
         add(u,v);
     }
}

//dfs 序
namespace  DFS_SEQ {
    using namespace xlx1;
    ll st[maxn],ed[maxn],dep[maxn],dfn=0;
    void dfs(ll u,ll fa){
        st[u] = ++dfn;
        for(ll i=head[u];~i;i =e[i].next){
            ll v = e[i].v; if(v == fa) continue;
            dep[v] = dep[u]+1; //根的深度为0，如果从1，dep[root] = 1;
            dfs(v,u);
        }
        ed[u]=dfn;
    }
}
namespace SGT {
    /* =====  线段树区间更新--lazy [区间加,区间求和] ====*/
    /* 区间加,区间求和 的线段树 */
    struct node {
        ll v;
        ll flag;
        ll tag;
    }t[maxn<<2];

    inline void _merge(node &a,node &b,node &c){ //合并
        a.v = b.v+c.v;
    }

    inline ll lc(ll o ){ return o<<1;}
    inline ll rc(ll o ){ return (o<<1)|1;}
    /* 更新父亲 */
    inline void pushup(ll o){
        _merge( t[o] , t[lc(o)] , t[rc(o)]);
    }

    /* 向下更新标记 */
    void pushdown(ll o,ll m){
        if(t[o].flag){
            t[lc(o)].flag += t[o].flag;   //[改]
            t[rc(o)].flag += t[o].flag;   //[改]
            //[改]
            //t[lc(o)].v += t[o].flag*(m-(m>>1));  [> 左孩子的值改变,上面有标记 <]
            //[改]
            //t[rc(o)].v += t[o].flag*(m>>1);  [> 右孩子的值改变,上面有标记 <]
            t[o].flag = 0;
        }
        if(t[o].tag){
            t[lc(o)].tag += t[o].tag;   //[改]
            t[rc(o)].tag += t[o].tag;   //[改]
            t[o].tag = 0;
        }
    }
    /* 区间更新 -- lazy */
    void update(ll l1,ll r1,ll c,ll tag,ll l,ll r,ll o){
        if(l1 <=l && r<=r1){
            t[o].flag += c; //我们到达一个点 [改]
            t[o].tag += tag;
            t[o].v += (r-l+1)*c; //[改]
            return ;
        }
        pushdown(o,(r-l+1)); //查看当前点对应标记树是不是有标记,如果有就往下压
        ll m = (l+r)>>1;
        if( l1 <= m) update(l1,r1,c,tag,l,m,lc(o));
        if( r1 > m) update(l1,r1,c,tag,m+1,r,rc(o));
        //pushup(o);
    }

    /* 单点查询 */
    node query(ll pos,ll l,ll r,ll o){
        if( l == r){
            return t[o];
        }

        //路过
        pushdown(o,(r-l+1));
        ll m = (l+r)>>1;
        if(pos <=m)  return query(pos,l,m,lc(o));
        else return  query(pos ,m+1,r,rc(o));
    }

    /* 建立线段树 */
    void build(ll l,ll r,ll o){
        if( l==r){
            //scanf("%d",&t[o].v);
            return ;
        }
        ll m = (l+r)>>1;
        build(l,m,lc(o));
        build(m+1,r,rc(o));
        pushup(o);
    }
#ifdef DEBUG
    void _dfs_print(ll l,ll r,ll o,FILE *dot){
        if( o >>1) fprintf(dot,"%d--%d;\n",o>>1,o);
        fprintf(dot,"%d[label=\"%d,%d\"]\n",o,t[o].flag,t[o].tag);
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


int main(){
    string ttt;
    ttt.c_str();
    clock_t program_stao_clock = clock(); //开始记时
    //===================
    init();
    DFS_SEQ::dfs(1, 0);
    ll i;
    using namespace SGT;
    using namespace DFS_SEQ;
    For(i,1,n){
        update(st[i], ed[i], a[i],0,1,n,1);
        //printf("%d %d %d\n",i,st[i],ed[i]);
    }
    //printf("%d\n",ans);
    int cnt=0;
    For(i,1,m){
        ll o,l,r;
        read(o);
        if( o == 1){
            read(l);read(r);
            update(st[l], ed[l], r, 0, 1,n,1);
        }
        else if( o == 2){
            read(l);read(r);
            update(st[l], ed[l], -r*(dep[l]-1),r, 1,n,1);
            //sgt_2_dot(n,"x"+to_string(++cnt)+".dot");
        }
        else {
            read(l);
            node ans = query(st[l], 1 , n, 1);
            ll aans = dep[l]*ans.tag + ans.flag;
            printf("%lld\n",aans);
        }
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_stao_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
