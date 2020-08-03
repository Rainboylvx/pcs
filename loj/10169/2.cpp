#include<bits/stdc++.h>
using namespace std;

long long a,b,f[15][10][10];//i位 当前j 数字k的数目 
long long cal(long long x,int y)
{
	int t[15],len=0;
	long long ans=0;
	while(x)t[++len]=x%10,x/=10;
	for(int i=1;i<len;++i)
	for(int j=1;j<=9;++j)ans+=f[i][j][y];
	for(int i=1;i<t[len];++i)ans+=f[len][i][y];
	for(int i=len-1,limit=t[len]==y?1:0;i;--i)
	{
		for(int j=0;j<t[i];++j)ans+=f[i][j][y];
		ans+=limit*pow(10,i-1)*t[i];
		limit+=t[i]==y?1:0;
	}	
	return ans;
}

int main()
{
	for(int i=0;i<=9;++i)f[1][i][i]=1;
	for(int i=2;i<=13;++i)
	for(int j=0;j<=9;++j)
	{
		f[i][j][j]=pow(10,i-1);
		for(int k=0;k<=9;++k)
		for(int l=0;l<=9;++l)f[i][j][k]+=f[i-1][l][k];
	}
	scanf("%lld%lld",&a,&b);
	for(int i=0;i<=9;++i)printf("%lld ",cal(b+1,i)-cal(a,i));
	printf("\n");
	return 0;
}
