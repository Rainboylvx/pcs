#include <cstdio>
#include <algorithm>
using namespace std;
int n ,r,q;
struct ps {
	int id,f,w;
};
ps p[200005];
bool cmp(ps a,ps b){
	if( a.f == b.f) return a.id < b.id;
	return a.f > b.f;
}
ps win[200005],lose[200005];
void pk(){
	int i,j,win_cnt=0,lose_cnt=0;
	for(i=1;i<=n;i=i+2){
		if( p[i].w < p[i+1].w){
			win[++win_cnt] = p[i+1];
			lose[++lose_cnt] = p[i];
		}
		else {
			win[++win_cnt] = p[i];
			lose[++lose_cnt] = p[i+1];
		}
		win[win_cnt].f++;
	}
	i = 1;j=1;int k=1;
	while( i <= win_cnt && j <= lose_cnt ){
		if( win[i].f > lose[j].f ) p[k++] = win[i++];
		else if ( win[i].f == lose[j].f && win[i].id < lose[j].id ) p[k++] = win[i++];
		else p[k++] = lose[j++];
	}
	while( i <= win_cnt) p[k++] = win[i++];
	while( j <= lose_cnt)p[k++] = lose[j++];
    //for(i=1;i<=n;i++)
    //{
        //printf("%d %d %d\n",p[i].id,p[i].f,p[i].w);
    //}
    //printf("==============\n");
}

int main(){
	scanf("%d%d%d",&n,&r,&q);
	int i,j,t;
	n *= 2;
	for(i=1;i<=n;i++){
		scanf("%d",&p[i].f);
		p[i].id = i;
	}
	for(i=1;i<=n;i++){
		scanf("%d",&p[i].w);
	}
	sort(p+1,p+n+1,cmp);
	for(i=1;i<=r;i++){
		pk();
	}
	printf("%d\n",p[q].id);
	
	return 0;
}
