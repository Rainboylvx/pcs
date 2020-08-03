#include<bits/stdc++.h>
using namespace std;

long long a,b,n,f[15][15][105];
long long cal(long long x)
{
	long long ans=0;
	int len=0,t[15];
	while(x)t[++len]=x%10,x/=10;
	for(int i=len,limit=0;i;--i)
	{
		for(int j=0;j<t[i];++j)ans+=f[i][j][(n-limit)%n];
		limit=(limit+t[i])%n;
	}
	return ans;
}

int main()
{
	while(~scanf("%lld%lld%lld",&a,&b,&n))
	{
		memset(f,0,sizeof(f));
		for(int i=0;i<=9;++i)f[1][i][i%n]=1;
		for(int i=2;i<=10;++i)
		{
			for(int j=0;j<=9;++j)
			for(int k=0;k<n;++k)
			for(int x=0;x<=9;++x)f[i][j][k]+=f[i-1][x][((k-j)%n+n)%n];
		}
		printf("%lld\n",cal(b+1)-cal(a));
	}	
	return 0;
}
