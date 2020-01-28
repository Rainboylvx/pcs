#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int s[15009],bit[15009];
int n,MAXN=32001;
int lowbit(int x)
{
	return  x&(-x);
}
void add(int i,int k)
{
	while(i<=MAXN)
	{
		bit[i]+=k;
		i+=lowbit(i);
	}
}
int gsum(int i)///前n项的和
{
    int s = 0;
    while(i > 0)
    {
        s += bit[i];
        i -= lowbit(i);
    }
    return s;
}
int main() 
{
	//freopen("t.txt","r",stdin);
	scanf("%d",&n);
	int x,y;
	memset(bit,0,sizeof(bit));
	memset(s,0,sizeof(s));
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		x++;
		s[gsum(x)]++;
		add(x,1);
	}
	for(int i=0;i<=n-1;i++)
	{
		printf("%d\n",s[i]);
	}
	return 0;
}
