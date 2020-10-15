#include <cstdio>

int main(){
	int l,r;
	scanf("%d%d",&l,&r);
	int i,j,cnt = 0;
	for(i=l;i<=r;i++){
		int t =i;
		while( t !=0){
			int g = t %10;
			if( g == 2)
				cnt++;
			t /= 10;
		}
	}
	printf("%d",cnt);

	return 0;
}
