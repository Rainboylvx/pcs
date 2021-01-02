/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 01月 03日 星期日 00:11:36 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,mod;
int op;
/* 定义全局变量 */
template<typename T,int N = maxn>
struct sgt_range {
    T tr[N*4+5];
    T fx[N*4+5]; // x flag
    T fa[N*4+5]; // + flag

    inline int lp(int p){ return p<<1; }
    inline int rp(int p){ return (p<<1) |1; }
    inline int mid(int l,int r){ return (l+r) >>1; }

    sgt_range(){ for(int i=0;i<N*4+5;++i) fx[i] = 1; }


    inline void pushup(int p){
        tr[p] = tr[lp(p)] + tr[rp(p)];
        tr[p] %= mod;
    }

    // pushdown x flag
    inline void _pdx(int p,T v){
        //加法标记 乘上
        fa[p] *= v;
        fa[p] %= mod;

        fx[p] *= v;
        fx[p] %= mod;
        tr[p] *= v;
        tr[p] %= mod;
    }
    inline void pushdown(int p,int len){
        if( fx[p] != 1){
            _pdx(lp(p),fx[p]);
            _pdx(rp(p),fx[p]);
            fx[p] = 1;
        }
        if( fa[p] != 0){
            fa[lp(p)] += fa[p];
            fa[lp(p)] %=mod;
            tr[lp(p)] += (len-(len>>1))*fa[p];
            tr[lp(p)] %= mod;

            fa[rp(p)] += fa[p];
            fa[rp(p)] %=mod;
            tr[rp(p)] += (len>>1)*fa[p];
            tr[rp(p)] %= mod;

            fa[p] = 0;
        }
    }

    void build(int l,int r,int p){
        if(l == r){
            scanf("%lld",&tr[p]);
            tr[p] %= mod;
            return;
        }
        int m = mid(l,r);
        build(l, m, lp(p));
        build(m+1, r, rp(p));
        pushup(p);
    }

    void update(int L,int R,T v,int l,int r,int p){
        if( L <= l && r <= R){
            if( op == 1) {
                _pdx(p,v);
            }
            else {
                fa[p] += v;
                fa[p] %= mod;
                tr[p] += (r-l+1)*v;
                tr[p] %= mod;
            }
            return;
        }
        pushdown(p, r-l+1);
        int m = mid(l,r);
        if( L <=m ) update(L, R, v, l,m, lp(p));
        if( R >=m+1) update(L, R, v, m+1, r, rp(p));
        pushup(p);
    }

    T query(int L,int R,int l,int r,int p){
        if( L <= l && r <= R) return tr[p];
        pushdown(p, r-l+1);
        int m = mid(l,r);
        T ret= 0;
        if( L <=m ) {
            ret += query(L, R,l,m, lp(p));
            ret %= mod;
        }
        if( R >=m+1) ret += query(L, R,  m+1, r, rp(p));
        return ret % mod;
    }

};

sgt_range<ll> sgt;

int main(){
    scanf("%d%d%d",&n,&m,&mod);
    sgt.build(1, n, 1);
    for(int i=1;i<=m;++i){
        int o,x,y,z;
        scanf("%d",&o);
        if( o== 1 || o == 2) {
            scanf("%d%d%d",&x,&y,&z);
            op = o;
            sgt.update(x,y,z,1,n,1);
        }
        else {
            scanf("%d%d",&x,&y);
            ll ans =sgt.query(x,y,1,n,1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
