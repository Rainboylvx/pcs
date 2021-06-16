/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 13日 星期日 15:12:50 CST */
// 20%
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5,maxe = 1e3+5; //点与边的数量

int n,m;
/* 定义全局变量 */

ll mg[maxn][maxn];
bool vis[maxn][maxn];

/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

ll ans=-0x7f7f7f7f7f7f7f7f;

bool inmg(int x,int y){
    return x >=1 && x <=n && y >=1 && y <=m;
}

void dfs(int x,int y,ll sum){
    vis[x][y] = 1;
    //printf("%d %d %lld\n",x,y,sum);

    if( x == n && y == m ) {
        ans = max(ans,sum);
        return;
    }

    for(int i=0;i<=2;++i){
        int nx = x + fx[i][0];
        int ny = y + fx[i][1];
        if( inmg(nx,ny) && vis[nx][ny] == 0){
            dfs(nx,ny,sum + mg[nx][ny]);
            vis[nx][ny] = 0;
        }
    }

}

void init(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%lld",&mg[i][j]);
        }
    }
}

int main(){
    init();
    dfs(1,1,mg[1][1]);
    printf("%lld",ans);
    return 0;
}
