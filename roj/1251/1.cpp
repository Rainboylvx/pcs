/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 25日 星期五 15:17:30 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

struct node {
    int x,y,s;//s = step
};
/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
char maze[5000][5000];
bool vis[5000][5000];
int sx,sy,tx,ty;

bool in_mg(int x,int y){
    return x >= 1 && x <=n && y >=1 && y <= m;
}


queue<node> q;
int bfs(){
    vis[sx][sy] = 1;
    q.push({sx,sy,0});

    while ( !q.empty()) {
        node h = q.front();q.pop();
        if( h.x == tx && h.y == ty)
            return h.s;
        for(int i=0;i<=3;++i){
            int nx = h.x + fx[i][0];
            int ny = h.y + fx[i][1];
            if( in_mg(nx, ny) && vis[nx][ny] == 0 && maze[nx][ny] != '#'){
                vis[nx][ny] = 1;
                q.push({nx,ny,h.s+1});
            }
        }
    }
    return -1;
}

int main(){

    while ( 1 ) {
        
        scanf("%d%d",&n,&m);
        if( n == 0 && m == 0 ) 
            return 0;
        //printf("%d %d\n",n,m);
        memset(vis,0,sizeof(vis));
        while( !q.empty() ) q.pop();
        for(int i=1;i<=n;++i){
            scanf("%s",&maze[i][1]);
            for(int j=1;j<=m;++j){
                if(maze[i][j] == '@')
                    sx = i , sy = j;
                else if(maze[i][j] == '*')
                    tx = i , ty = j;
            }
        }
        int ans = bfs();
        printf("%d\n",ans);

    }

    return 0;
}
