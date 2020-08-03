/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 12日 星期日 11:11:07 CST
* problem: OpenJ_Bailian-2790
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n;
char map[105][105];

bool vis[105][105];
int ha, la, hb, lb;

int fx[4][2] = {
    {-1,0},
    {1,0},
    {0,1},
    {0,-1}
};

void init(){
    scanf("%d",&n);
    memset(vis,0,sizeof(vis));

    int i;
    for (i=0;i<n;i++){
        scanf("%s",&map[i][0]);
    }
    scanf("%d%d%d%d",&ha,&la,&hb,&lb);
}

bool in_map(int x,int y){
    if( x >=0 && x< n && y>=0 && y <n)
        return true;
    return false;
}


bool dfs(int x,int y){
    vis[x][y] = 1;
    if( x == hb && y == lb){
        return true;
    }
    
    int i;
    for(i=0;i<4;i++){
        int nx = x + fx[i][0];
        int ny = y + fx[i][1];

        if( vis[nx][ny] == 0 && in_map(nx,ny) && map[nx][ny] =='.'){
            if( dfs(nx,ny))
                return 1;
        }
    }

    return 0;
}

int main(){
    scanf("%d",&T);
    while(T--){
        init();
        if( map[ha][la] == '#')
        {
            printf("NO\n");
            continue;
        }
        bool res = dfs(ha,la);
        if( res)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;

}
