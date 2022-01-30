/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 01月 30日 星期日 19:32:17 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int n,m;
/* 定义全局变量 */
int mg[500][500];
bool in_mg(int x,int y){
    return x>=0 && x<500 && y >=0 && y<500;
}

void do_star_1(int x,int y,int t){
    if( mg[x][y] == -1 || mg[x][y] > t)
        mg[x][y] = t;
}

void do_star(int x,int y,int t){
    do_star_1(x,y,t);
    for(int i=0;i<=3;++i){
        int nx = x+fx[i][0];
        int ny = y+fx[i][1];
        if(in_mg(nx,ny)){
            do_star_1(nx, ny, t);
        }
    }
}

struct node { int x,y,s; };
bool vis[500][500];

int bfs(){
    if( mg[0][0] == 0){
        return -1;
    }

    queue<node> q;
    q.push({0,0,0});
    vis[0][0] = 1;

    while ( !q.empty() ) {
        node h = q.front();
        q.pop();
        if( mg[h.x][h.y] == -1)
            return h.s;

        for(int i=0;i<=3;++i){
            int nx = h.x+fx[i][0];
            int ny = h.y+fx[i][1];
            if(in_mg(nx,ny) && vis[nx][ny] == 0 ){
                if(mg[nx][ny] !=-1 && mg[nx][ny] <= h.s+1)
                    continue;
                q.push({nx,ny,h.s+1});
                vis[nx][ny]=1;
            }
        }
    }

    return -1;
}

int main(int argc,char * argv[]){
    std::cin >> m;
    memset(mg,-1,sizeof(mg));
    for(int i=1;i<=m;++i){
        int x,y,t;
        std::cin >> x >> y >> t;
        do_star(x,y,t);
    }

    int ans = bfs();
    std::cout << ans << std::endl;
    return 0;
}
