#include <bits/stdc++.h>
using namespace std;
#define maxn 105
int n;
int sx,sy,tx,ty;
char m[maxn][maxn];
struct _node {
	int x,y;
};
int fx[][2] = {1,0,0,1,-1,0,0,-1};
bool vis[maxn][maxn];
void init(){
	scanf("%d",&n);
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",&m[i][1]);
	}
	scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
	memset(vis,0,sizeof(vis));
	sx++;sy++;tx++;ty++;
}
bool in_map(int x,int y){
	return x >=1 && x<=n && y >=1 && y <=n;
}
bool bfs(){
	queue<_node> q;
	q.push({sx,sy});
	//printf("size = %d\n",q.size());
	vis[sx][sy] == 1;
	while( !q.empty()) {
		int i;
		_node h = q.front();q.pop();
		if( h.x == tx && h.y == ty)
			return 1;
		for(i=0;i<4;i++){
			int nx = h.x + fx[i][0];
			int ny = h.y + fx[i][1];
			//printf("===>%d,%d\n",nx,ny);
			if( in_map(nx,ny) && vis[nx][ny]==0 && m[nx][ny]=='.'){
				q.push({nx,ny});
				vis[nx][ny] = 1;
			}
		}
	}
	return 0;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		init();
		if( sx == tx && sy == ty){
			printf("YES\n");
			continue;
		}
		if( m[sx][sy] == '#' || m[tx][ty] == '#'){
            printf("NO\n");
            continue;
        }
		bool ans= bfs();
		if( ans ) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 