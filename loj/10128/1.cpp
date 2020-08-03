/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 22日 星期五 07:49:34 CST
* problem: loj-10128
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 2e5+5;
const int maxe = 1e6+5;
typedef  long long ll;
int n,m;
    struct _ST {
        ll v; //值
        bool no; //不用根了
        _ST operator+(const _ST r){ // 合并
            return {v+r.v,r.no && no};
        }
    } st[maxn<<2];
/* ======= 全局变量 END =======*/

#ifdef DEBUG
#endif
int sqrt_n(int v,int n){
    for( int i=1;i<=n;i++){ v = (int)sqrt(v); }
    return v;
}

namespace SGT {

    inline int lson(int rt ){ return rt<<1;}
    inline int rson(int rt ){ return (rt<<1)|1;}

    void pushup(int rt){ st[rt] = st[lson(rt)] + st[rson(rt)]; }

    void pushdown(int rt){ }

    void build(int l,int r,int rt){
        if( l == r) {
            scanf("%lld",&st[rt].v);
            return;
        }
        int m =(l+r)>>1;
        build(l, m, lson(rt));
        build(m+1, r, rson(rt));
        pushup(rt);
    }

    void update(int L,int R,int l,int r,int rt){ //更新到叶子
        if(l == r){
            st[rt].v = (ll)sqrt(st[rt].v);
            if( st[rt].v < 2) { st[rt].no = 1; };
            return;
        }
        if( st[rt].no) return;
        int m = (l+r) >>1;
        if( L <=m) update(L,R,l,m,lson(rt));
        if( R > m) update(L,R,m+1,r,rson(rt));
        pushup(rt);
    }
    ll query(int L,int R,int l,int r,int rt){
        if( L <=l && r <= R){ return st[rt].v; }
        ll m=(l+r)>>1, ret = 0;
        if( L<=m) ret += query(L,R,l,m,lson(rt));
        if( R >m) ret +=query(L,R,m+1,r,rson(rt));
        return ret;
    }
}

using namespace SGT;
void init(){
    scanf("%d",&n);
    build(1,n,1);
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    scanf("%d",&m);
    int o,u,v;
    int i;
    For(i,1,m){
        scanf("%d%d%d",&o,&u,&v);
        if( o == 1){
            ll ans = query(u,v, 1, n, 1);
            printf("%lld\n",ans);
        }
        else {
            update(u,v,1,n,1);
        }
        //printf("======================\n");
        //print_sgt(3);
        //printf("======================\n\n\n");
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
