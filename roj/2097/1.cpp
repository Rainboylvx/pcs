/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 30日 星期三 11:11:24 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,mod;

template<typename T,int N = maxn>
struct sgt_range {
    T tr[N*4+5];
    T fx[N*4+5];
    sgt_range(){ for(int i=1;i<=N*4+5;++i) fx[i] = 1; }

    inline int lp(int p){return p<<1;}
    inline int rp(int p){return (p<<1)|1;}
    inline int mid(int l,int r){return (l+r)>>1;}

    inline void pushup(int p){
        tr[p] = tr[lp(p)] + tr[rp(p)];
        tr[p] %= mod;
    }

    inline void _pd(int p,int x){
        fx[p] *= x;
        fx[p] %= mod;
        tr[p] *= x;
        tr[p] %= mod;
    }
    inline void pushdown(int p){
        if( fx[p] != 1){
            _pd(lp(p),fx[p]); //left
            _pd(rp(p),fx[p]); //right
            fx[p] = 1;
        }
    }

    void build(int l,int r,int p){
        if( l==r) {
            scanf("%lld",&tr[p]);
            tr[p] %= mod;
            return;
        }
        int m = mid(l,r);
        build(l,m ,lp(p));
        build(m+1,r ,rp(p));
        pushup(p);
    }

    void update(int L,int R,T v,int l,int r,int p){
        if( L <= l && r <= R ) {
            _pd(p,v);
            return;
        }
        pushdown(p);
        int m = mid(l,r);
        if( L <= m)
            update(L,R,v,l,m,lp(p));
        if( R >= m+1)
            update(L,R,v,m+1,r,rp(p));
        pushup(p);
    }

    T query(int L,int R,int l,int r,int p){
        if( L <= l && r <= R ) { return tr[p]; }
        pushdown(p);
        int m = mid(l,r);
        T ret = 0;
        if( L <= m){
            ret += query(L,R,l,m,lp(p));
            ret %= mod;
        }
        if( R >= m+1)
            ret += query(L,R,m+1,r,rp(p));
        return ret % mod;
    }

};

sgt_range<ll> sgt;

int main(){
    scanf("%d%d%d",&n,&m,&mod);
    sgt.build(1, n,1);
    for(int i=1;i<=m;++i){
        int o,x,y,z; // o == operator
        scanf("%d",&o);
        if( o==1 ) {
            scanf("%d%d%d",&x,&y,&z);
            sgt.update(x, y, z, 1, n, 1);
        }
        else {
            scanf("%d%d",&x,&y);
            ll ans = sgt.query(x, y, 1, n, 1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
