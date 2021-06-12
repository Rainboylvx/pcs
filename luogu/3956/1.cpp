/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 11日 星期五 16:33:57 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int mg[105][105];
int ans = 0x7f7f7f7f;
bool vis[105][105];
/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };


void init(){
    scanf("%d%d",&m,&n);
    memset(mg,-1,sizeof(mg));
    for(int i=1;i<=n;++i){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        mg[x][y] =t;
    }
}

bool inmg(int x,int y){
    return x >=1 && x <=m && y >=1 && y<=m;
}

void dfs(int x,int y,bool magic,int gold){
    if( x ==m && y==m){
        ans = min(ans,gold);
        return;
    }
    vis[x][y] = 1;

    for(int i=0;i<=3;++i){
        int nx = x+ fx[i][0];
        int ny = y+ fx[i][1];
        if( inmg(nx,ny) && vis[nx][ny] == 0){
            if( mg[nx][ny] != -1){
                if(mg[nx][ny] == mg[x][y]){ // same color
                    if( magic == 1) mg[x][y] = -1;
                    dfs(nx,ny,0,gold);
                    vis[nx][ny] = 0;
                    if( magic == 1) mg[x][y] = mg[nx][ny];
                }
                else { // not same color
                    if( magic == 1) mg[x][y] = -1;
                    dfs(nx,ny,0,gold+1);
                    vis[nx][ny] = 0;
                    if( magic == 1) mg[x][y] = !mg[nx][ny];
                }
            }
            else if( magic == 0){ // nx,ny is colorless
                //1 same color
                mg[nx][ny] = mg[x][y];
                dfs(nx,ny,1,gold+2);
                vis[nx][ny] = 0;
                mg[nx][ny] = -1;

                //2 not same color
                mg[nx][ny] = !mg[x][y];
                dfs(nx,ny,1,gold+3);
                vis[nx][ny] = 0;
                mg[nx][ny] = -1;

            }
        }
    }
}
int main(){
    init();
    dfs(1,1,0,0);
    if( ans == 0x7f7f7f7f)
        printf("-1\n");
    else
        printf("%d",ans);
    return 0;
}
