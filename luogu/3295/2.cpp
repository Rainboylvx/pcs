#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define re register int
#define ll long long
#define MN 1000050
#define mod 1000000007
using namespace std;
int bcj[MN*22],f[MN][22],lc[MN*22],rc[MN*22],lg[MN];
int n,m,k,ltk,cnt;
int find(int x){
	if(x==bcj[x])return x;
	bcj[x]=find(bcj[x]);
	return bcj[x];
}
void merge(int x,int y){
	int t1=find(x),t2=find(y);
	if(t1!=t2)bcj[t2]=t1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(re i=2;i<=n;i++)
		lg[i]=lg[i/2]+1;	
	for(re j=lg[n];j>=0;j--)
		for(re i=1;i+(1<<j)-1<=n;i++){
				f[i][j]=++cnt;
				bcj[cnt]=cnt;
		}//给大区间编号
	for(re j=1;j<=lg[n];j++)
		for(re i=1;i+(1<<j)-1<=n;i++){
			lc[f[i][j]]=f[i][j-1];
			rc[f[i][j]]=f[i+(1<<(j-1))][j-1];
		}//统计左右儿子
	for(re i=1;i<=m;i++){
		int a1,a2,a3,a4;
		scanf("%d%d%d%d",&a1,&a2,&a3,&a4);
		int l=lg[a2-a1+1];
		merge(f[a1][l],f[a3][l]);
		merge(f[a2-(1<<l)+1][l],f[a4-(1<<l)+1][l]);
	}//像st表一样合并
	for(re i=1;i<=cnt;i++){
		if(!lc[i]||!rc[i])continue;
		int t1=find(i);
		if(t1!=i){
			merge(lc[t1],lc[i]);
			merge(rc[t1],rc[i]);
			//如果f[i][j]与f[a][b]同属一个联通块，那么他们左右儿子也同属一个联通块
		}
	}
	ltk=n;
	//先假设每个位置都是独立的联通块，如果联通再减
	for(re i=1;i<=n;i++){
		if(find(f[i][0])!=f[i][0])
			ltk--;
	}
	ll ans=9;
	for(re i=1;i<ltk;i++)
		ans=(ans%mod*10)%mod;
		printf("%lld",ans%mod);
	return 0;
}
