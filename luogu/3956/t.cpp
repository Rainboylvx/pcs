/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 06月 14日 星期日 10:35:49 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 405;
int n,m;
int Map[maxn][maxn];
bool vis[maxn][maxn];
int sx,sy;

void init(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&sx,&sy);
    memset(Map,-1,sizeof(Map));
    Map[sx][sy] = 0;
}

bool in_map(int x,int y){
    return x>=1 && x <=n && y>=1 && y <=m;
}

struct node {
    int x,y;
};
int fx[][2] = { 1,2,2,1, -1,2,2,-1, 1,-2,-2,1, -1,-2,-2,-1 };
void bfs(int x,int y){
    vis[x][y] = 1;
    queue<node> q;
    q.push({x,y});
    while(!q.empty()){
        node h = q.front();q.pop();
        int i;
        for(i=0;i<8;i++){
            int nx = fx[i][0] + h.x;
            int ny = fx[i][1] + h.y;
            if( in_map(nx, ny) && vis[nx][ny] == 0){
                Map[nx][ny] = Map[h.x][h.y] +1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }

}

int main(){
    init();
    bfs(sx,sy);
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=m;++j){
            printf("%-5d",Map[i][j]);
        }
        printf("\n");
    }

    return 0;
}
