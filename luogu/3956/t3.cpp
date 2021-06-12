// 100
/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 05月 23日 星期日 15:47:21 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int mg[105][105];
int mg_v[105][105];
/* 定义全局变量 */

void init(){
    scanf("%d%d",&m,&n);
    memset(mg,-1,sizeof(mg));
    memset(mg_v,0x7f,sizeof(mg_v));
    for(int i=1;i<=n;++i){
        int x,y,t;
        scanf("%d%d%d",&x,&y,&t);
        mg[x][y] =t;
    }
}

/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
//bool vis[105][105];
bool inmg(int x,int y){
    return x >=1 && x <=m && y>=1 &&y<=m;
}

//重新设置这个格子的颜色
void reset_(int x,int y,bool sf){
    if( sf == 0){
        mg[x][y] = -1;
    }
}

int ans = 0x7f7f7f7f;
// pc == pre color
// color 当前点的颜色
void dfs(int x,int y,bool sf,int color,int gold){
    mg_v[x][y] = gold;
    //if( x == 3 && y == 3){
        //printf("gc 3 3 \n");
    //}
    //if( x == y && x == 2){
        //printf("%d %d %d\n",x,y,gold);
    //}
    if( x == m && y == m){
        ans = min(ans,gold);
        return;
    }
    for(int i=0;i<=3;++i){
        int nx =  x + fx[i][0];
        int ny =  y + fx[i][1];

        if( inmg(x,y)){

            if( mg[nx][ny] != -1){
                if( mg[nx][ny] == color ){
                    if( gold < mg_v[nx][ny])
                        dfs(nx,ny,1,mg[nx][ny],gold);
                }
                else{
                    reset_(x, y, sf);
                    if( gold+1 < mg_v[nx][ny])
                        dfs(nx,ny,1,mg[nx][ny],gold+1);
                }
            }
            else if( sf == 1){ //下一个格子无色 且自己可以施法
                //1
                if( gold+2 < mg_v[nx][ny]){
                    //mg[nx][ny] = mg[x][y];
                    dfs(nx,ny,0,mg[x][y],gold+2);
                }

                //2
                if (gold+3 < mg_v[nx][ny]) {
                    //mg[nx][ny] = !mg[x][y];
                    dfs(nx,ny,0,!mg[x][y],gold+3);
                    //mg[nx][ny] = -1;
                }
            }
        }
    }
}

int main(){
    init();
    dfs(1,1,1,mg[1][1],0);
    if( ans == 0x7f7f7f7f)
        printf("-1");
    else    {
        printf("%d",mg_v[m][m]);
    }

    //printf("\n");
    //printf("\n");
    ////输出每个点的频数
    //for(int i=1;i<=n;++i){
        //for(int j=1;j<=n;++j){
            //if( mg_v[i][j] == 0x7f7f7f7f)
                //printf("%5d ",-1);
            //else    
            //printf("%5d ",mg_v[i][j]);
        //}
        //printf("\n");
    //}
        ////printf("%d",ans);

    return 0;
}
