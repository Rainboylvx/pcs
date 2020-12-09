/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 07日 星期一 20:12:48 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
template<typename T,int N=maxn>
struct Bit_range_point {
    T c[N+5]; // c[i] = a[i] - a[i-1]

    inline int lowbit(int x) { return x & -x;      }
    inline int fa(int p)     { return p+lowbit(p); }
    inline int left(int p)   { return p-lowbit(p); }

    void update(int p, T v){
        for( ; p <= N; p = fa(p) ) 
            c[p] += v;
    }

    inline void update_range(int l,int r,T v){
        update(l,v);
        update(r+1,-v);
    }

    T query(int p){ //前缀合,单点查询
        T sum=0;
        for( ;p > 0 ; p = left(p)) sum+= c[p];
        return sum;
    }
};
Bit_range_point<int,maxn> bit;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int t;
        scanf("%d",&t);
        bit.update_range(i, i, t);
    }
    for(int i=1;i<=m;++i){
        int o,x,y,z;
        scanf("%d",&o);
        if( o == 1) {
            scanf("%d%d%d",&x,&y,&z);
            bit.update_range(x, y, z);
        }
        else {
            scanf("%d",&x);
            ll ans = bit.query(x);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
