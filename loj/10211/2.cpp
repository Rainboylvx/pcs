#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdlib>
#define ll long long
#define gc getchar()
using namespace std;
const int N=15;
const int mod=9901;
ll p[N];int c[N];
inline void qr(ll &x)
{
	x=0;int f=1;char c=gc;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=gc;}
	while(c>='0'&&c<='9'){x=x*10+(c^48);c=gc;}
	x*=f;
}
inline void mul(ll &a,ll b)
{
	ll c=a*b/mod;
	a=a*b-c*mod;
}
inline ll pow_mod(ll a,ll b)
{
	ll ans=1;a%=mod;
	while(b)
	{
		if(b&1)mul(ans,a);
		b>>=1;mul(a,a);
	}
	return ans;
}
inline void div(ll x)
{
	p[0]=0;
	for(int i=2;i*i<=x;i++)
	{
		if(x%i==0)
		{
			p[++p[0]]=i;
			c[p[0]]=0;
			while(x%i==0)x/=i,++c[p[0]];
		}
	}
	if(x>1)p[++p[0]]=x,c[p[0]]=1;
}
int main()
{
	ll a,b;qr(a),qr(b);
	div(a);ll ans=1;
	for(int i=1;i<=p[0];i++)
	{
		if((p[i]-1)%mod==0)
		{
			ans=(b*c[i]+1)*ans%mod;
			continue;
		}
		ll x=pow_mod(p[i],b*c[i]+1);
		x=(x-1+mod)%mod;
		ll y=p[i]-1;
		y=pow_mod(y,mod-2);
		ans=ans*x*y%mod; 
	}
	printf("%lld\n",ans);
	return 0;
}
