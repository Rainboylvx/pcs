#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,Max,i;
int a[10005],b[105];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if (a[i]<Max) Max=a[i]; //求出最大的值
	}

	if (n <= m){ //人比水龙头少
		printf("%d",Max); 
		return 0;
	}
	for (int i=1;i<=m;++i)
	  b[i]+=a[i];
	i=m+1;
	while (i<=n){
		sort(b+1,b+m+1);
		b[1]+=a[i]; //最少的那个加入一个新人
		i++;
	}
	Max=0;
	for (int i=1;i<=m;++i)
	  if (b[i]>Max) Max=b[i];
	printf("%d",Max);
}
