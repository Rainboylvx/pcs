#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;

struct _pos{int x,y;};
_pos p[20];
int n;
double g[20][20];
double get_len(_pos a,_pos b){
	return sqrt((b.y-a.y)*(b.y-a.y)+(a.x-b.x)*(a.x-b.x));
}

bool vis[20];
double ans = 1231234423.0;
int mem[100];
void dfs(int dep,int pre,double sum){
	if( dep > n){
	    if( ans > sum){
	        ans = sum;
			//int i;
			//printf("len = %.2lf\n",sum);
			//for(i=1;i<=n;++i){
				//printf("%d ",mem[i]);
			//}
			//printf("\n");
	    }
		return;
	}
	int i;
	for(i=1;i<=n;i++){
		if( !vis[i]){
		    //最优性剪枝
			if( sum +g[pre][i] >= ans) continue;
			vis[i] = 1;
			mem[dep] = i;
			dfs(dep+1,i,sum+g[pre][i]);
			vis[i] = 0;
		}		
	}
}
int main(){
	cin>> n;
	int i,j;
	for(i=1;i<=n;i++)
		cin >> p[i].x >>p[i].y;
	for(i=0;i<n;i++)
		for(j=i+1;j<=n;j++){
			g[i][j] = g[j][i] = get_len(p[i],p[j]);
		}

    vis[0] = 1;
    mem[1] = i;
    dfs(1,0,0);

    printf("%.2lf\n",ans);
	return 0;
}
