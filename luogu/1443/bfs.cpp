/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 12日 星期三 17:31:32 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int x,y;
int maze[500][500];
/* 定义全局变量 */

#define F(n) for(int i =1;i<=n;i++)
#define FF(i,n) for(int i =1;i<=n;i++)
#define F3(i,s,n) for(int i =s;i<=n;i++)


void init()
{
    memset(maze,-1,sizeof(maze));
    cin >> n >> m;
    std::cin >> x >> y;
}

struct node {
    int x,y;
};

int fx[][2] = { -1,2, -1,-2, 1, 2, 1,-2, 2,-1, 2,1, -2,1, -2,-1 };

bool in_maze(int x,int y) {
    return x >=1 && x <=n && y >=1 && y <=m;
}

void bfs(){
    queue<node> q;
    q.push({x,y});
    maze[x][y] = 0;

    while ( q.empty()  == false) {
        node h = q.front();
        q.pop();
        F3(i,0,7) {
            int nx  = fx[i][0] + h.x;
            int ny  = fx[i][1] + h.y;
            if( !in_maze(nx, ny)) continue;
            if( maze[nx][ny] !=-1) continue;
            maze[nx][ny] = maze[h.x][h.y] + 1;
            q.push({nx,ny});
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    bfs();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            std::cout << maze[i][j] << " ";
        }
        std::cout << "\n";
    }
    return 0;
}
