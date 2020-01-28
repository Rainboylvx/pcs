#include <cstdio>
typedef long long ll;
ll A,B;
const int maxn = 10000;
const int mod = 9901;
ll p[maxn],c[maxn];
int k = 0; //计数用
void _div(ll A){
    // 分解整数A
    int i;
    for(i=2;i*i <=A;){
        if( A % i == 0){
            p[++k] = i;
            c[k] = 0;
            while( A%i == 0){
                c[k]++;
                A/=i;
            }
        }
        //奇偶
        if( i == 2) i++;
        else i+=2;
    }
    //特殊判断,A是质数
    if(A != 1){
        p[++k] = A;
        c[k] = 1;
    }
}

ll quick_pow(ll a,ll b){
    ll ans = 1; a %= mod;
    for( ; b ; b >>= 1){
        if ( b & 1) 
            ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}
int main(){
    scanf("%lld%lld",&A,&B);
    _div(A); //因数分解
    ll ans = 1;
    int i;
    for(i=1;i<=k;++i){
        if(( p[i] -1 ) % mod == 0){
            ans = (B*c[i] + 1) * ans % mod;
            continue;
        }
        ll x = quick_pow(p[i], B*c[i]+1);
        x =( x-1) %mod;
        ll y = quick_pow(p[i]-1, mod-2);
        ans = ans * x*y%mod;
    }
    printf("%lld\n",ans);
    return 0;
}

