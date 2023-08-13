#include <bits/stdc++.h>
using namespace std;
int n,m;
int cow[100005]; 

bool check(int x){
	int i,cnt=1,pre =  1;
	for(i=2;i<=n;i++){
		if(cow[i] - cow[pre] >= x){
			pre = i;
			cnt++;
			if(cnt == m) return 1;
		}
	}
	return 0;
}

int bsearch(int l,int r){
	while( l < r ){
		int m = (l+r) / 2;
		if( check(m))
			l = m+1;
		else
			r=m;
	}
	return l;
} 


int main(){
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;i++)
		scanf("%d",&cow[i]);
	sort(cow+1,cow+n+1);
	int x = bsearch(1,1e9+1);
	printf("%d",x-1);
	
	return 0;
}
