#include<cstdio>
typedef long long ll;
// m 是除数,a 是余数
ll m[15],a[15];
//扩展欧几里得算法 
ll exgcd(ll a,ll b,ll &x,ll &y){//ax+by=gcd(a,b)
    if(b==0){x=1,y=0;return a;}
    ll gcd=exgcd(b,a%b,x,y);
    ll tx=x;
    x=y;
    y=tx-(a/b)*y;
    return gcd;
}
//中国剩余定理 
ll China(int n,ll m[],ll a[])
{
    ll M=1,x,y,ans=0;
    //求出总乘积
    for(int i=1;i<=n;i++) M*=m[i]; 
    for(int i=1;i<=n;i++){
        ll w=M/m[i]; //其他数的乘积
        ll gcd = exgcd(w,m[i],x,y);
        ans = (ans + w *x * a[i]) % M;
    }
    //最小整数解
    return (ans % M +M )%M;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld%lld",&m[i],&a[i]);
    printf("%lld",China(n,m,a));
}
