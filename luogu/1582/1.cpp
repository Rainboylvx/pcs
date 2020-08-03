#include <cstdio>
typedef long long ll;
ll n,k;

inline ll num(ll n){
    ll cnt = 0;
    while( n ){
        cnt++;
        n = n & (n-1);
    }
    return cnt;
}

inline ll lowbit(ll n){ return n & - n; }

int main(){
    scanf("%lld%lld",&n,&k);
    ll org = n;
    while(num(n) > k){
        n += lowbit(n);
    }
    printf("%lld\n",n-org);
    return 0;
}

