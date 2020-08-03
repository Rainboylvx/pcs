/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 22日 星期五 20:37:14 CST
* problem: loj-10129
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 2e5+5;
const int maxe = 1e6+5;
int n,m,p;


/* ======= 全局变量 END =======*/
namespace SGT {
    typedef long long ll;
    /* =====  线段树区间更新--lazy [区间加,区间求和] ====*/
    ll multt(ll a,ll b){
        return ((a%p)*(b%p))%p;
    }

    /* 区间加,区间求和 的线段树 */
    struct _ST {
        ll v;
        ll xflag=-1,aflag=0; //乘以与+ 标记
        _ST(){v=0,xflag=-1,aflag=0;}
        _ST(ll a,ll b,ll c):v(a),xflag(b),aflag(c){}
        _ST operator+(_ST b){
            ll t = (v % p +b.v % p) %p;
            return  _ST(t,-1,0);
        }
    }st[maxn<<2];

    inline int lson(int rt ){ return rt<<1;}
    inline int rson(int rt ){ return (rt<<1)|1;}
    /* 更新父亲 */
    void pushup(int rt){
        st[rt] = st[lson(rt)] + st[rson(rt)];
    }

    /* 向下更新标记 */
    void pushdown(int rt,int m){
        if( st[rt].xflag !=-1){
            if( st[lson(rt)].xflag !=-1) st[lson(rt)].xflag = multt(st[lson(rt)].xflag,st[rt].xflag ) %p ;
            else st[lson(rt)].xflag = st[rt].xflag;
            if( st[rson(rt)].xflag !=-1) st[rson(rt)].xflag = multt(st[rson(rt)].xflag,st[rt].xflag ) %p;
            else st[rson(rt)].xflag = st[rt].xflag;
            st[lson(rt)].aflag = multt(st[lson(rt)].aflag, st[rt].xflag)%p;
            st[rson(rt)].aflag =multt( st[rson(rt)].aflag ,st[rt].xflag)%p;
            st[lson(rt)].v = (st[lson(rt)].v * (st[rt].xflag %p)) %p;
            st[rson(rt)].v = (st[rson(rt)].v *(st[rt].xflag %p)) %p;
            st[rt].xflag = -1;
        }
        if( st[rt].aflag){
            st[lson(rt)].aflag += st[rt].aflag;
            st[lson(rt)].aflag %= p;
            st[rson(rt)].aflag += st[rt].aflag;
            st[rson(rt)].aflag %= p;
            st[lson(rt)].v = (st[lson(rt)].v + (m-(m>>1)) * st[rt].aflag) %p;
            st[rson(rt)].v = (st[rson(rt)].v + ((m>>1)) *st[rt].aflag) %p;
            st[rt].aflag = 0;
        }
    }
    /* 区间更新 -- lazy */
    void update_add(int l1,int r1,int c,int l,int r,int rt){
        if(l1 <=l && r<=r1){
            st[rt].aflag += c; 
            st[rt].aflag %= p; 
            st[rt].v = (st[rt].v + (r-l+1)*c) %p;
            return;
        }
        pushdown(rt,(r-l+1)); //查看当前点对应标记树是不是有标记,如果有就往下压
        int m = (l+r)>>1;
        if( l1 <= m) update_add(l1,r1,c,l,m,lson(rt));
        if( r1 > m) update_add(l1,r1,c,m+1,r,rson(rt));
        pushup(rt);
    }

    void update_mux(int l1,int r1,int c,int l,int r,int rt){
        if(l1 <=l && r<=r1){
            if( st[rt].xflag !=-1) st[rt].xflag *=c,st[rt].xflag %= p;
            else st[rt].xflag = c;
            st[rt].aflag *= c;
            st[rt].aflag %= p;
            st[rt].v = (st[rt].v * c) %p;
            return;
        }
        pushdown(rt,(r-l+1)); //查看当前点对应标记树是不是有标记,如果有就往下压
        int m = (l+r)>>1;
        if( l1 <= m) update_mux(l1,r1,c,l,m,lson(rt));
        if( r1 > m) update_mux(l1,r1,c,m+1,r,rson(rt));
        pushup(rt);
    }

    /* 区间查询 */
    ll query(int l1,int r1,int l,int r,int rt){
        if(l1<=l && r <= r1){//包含
            return st[rt].v;
        }

        //路过
        pushdown(rt,(r-l+1));
        ll ret = 0;
        int m = (l+r)>>1;
        if(l1 <= m) ret= (ret + query(l1,r1,l,m,lson(rt)) ) %p; 
        if(r1 > m ) ret= (ret + query(l1,r1,m+1,r,rson(rt)) ) %p;
        return ret % p ;
    }

    /* 建立线段树 */
    void build(int l,int r,int rt){
        if( l==r){
            scanf("%lld",&st[rt].v);
            return ;
        }
        int m = (l+r)>>1;
        build(l,m,lson(rt));
        build(m+1,r,rson(rt));
        pushup(rt);
    }

}
/* ====== 线段树区间更新--lazy-- END ====*/
using namespace SGT;
#ifdef DEBUG
    void p_leaf(int l,int r,int rt){
        if( l ==r){
            printf("%d ",st[rt].v);
            return;
        }
        pushdown(rt,r-l+1);
        int m = (l+r)>>1;
        p_leaf(l,m,lson(rt));
        p_leaf(m+1,r,rson(rt));
        pushup(rt);
    }
void print_line(int line){
    int i;
    For(i,1,line){
        printf("%d: %d %d %d\n",i,st[i].v,st[i].xflag,st[i].aflag);
    }
    printf("\n");
    printf("\n");
}
#endif

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d",&n,&p);
    build(1, n, 1);
    scanf("%d",&m);
    int op,l,r,v;
    int i;
    For(i,1,m){
        scanf("%d",&op);
        if( op == 1){
            scanf("%d%d%d",&l,&r,&v);
            update_mux(l, r, v, 1, n, 1);
        }
        else if( op ==2){
            scanf("%d%d%d",&l,&r,&v);
            update_add(l, r, v, 1, n, 1);
        }
        else {
            scanf("%d%d",&l,&r);
            ll ans = query(l, r, 1, n, 1);
            printf("%lld\n",ans);
        }
        //print_line(9);
        //p_leaf(1,n,1);
        //printf("\n\n");
    }


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
