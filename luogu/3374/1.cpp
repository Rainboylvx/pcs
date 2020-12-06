/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 05日 星期六 21:59:55 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */


template<typename T,int N=maxn>
struct Bit {
    T c[N];
    //Bit(){}
    inline int lowbit(int x) { return x & -x;      }
    inline int fa(int p)     { return p+lowbit(p); }
    inline int left(int p)   { return p-lowbit(p); }

    void update(int p, T v){
        for( ; p <= N; p = fa(p) ) c[p] += v;
    }

    T query(int p){ //前缀合
        T sum=0;
        for( ;p > 0 ; p = left(p)) sum+= c[p];
        return sum;
    }
};
Bit<ll> bit;

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int t;
        scanf("%d",&t);
        bit.update(i,t);
    }
    for(int i=1;i<=m;++i){
        int o,x,y;
        scanf("%d%d%d",&o,&x,&y);
        if( o == 1 ) {
            bit.update(x, y);
        }
        else {
            ll ans = bit.query(y) - bit.query(x-1);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
