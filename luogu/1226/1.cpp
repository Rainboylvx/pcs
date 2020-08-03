#include <cstdio>
typedef long long ll;
ll b,p,k;
//快速幂
ll quick_pow(ll a,ll n){
    ll base = a;
    ll i,s = 1;
    for( ; n ; n >>=1){
        if( n & 1 ){
            s = s * base % k;
        }
        base = base *base % k;
    }
    return s % k;
}
int main(){
    scanf("%lld%lld%lld",&b,&p,&k);
    ll ans=quick_pow(b,p);
    printf("%lld^%lld mod %lld=",b,p,k);
    printf("%lld\n",ans);
    return 0;
}

