/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-17 16:58:17
*----------------*/
#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

//////// 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif


const int inf = 0x7f7f7f7f;
int n,m;
/* 定义全局变量 */

struct node {int x,y;};
char maze[2000][2000]; //常用的一个数组 
node vis[2000][2000]; // vis[x][y] 表示中心的x,y点是被哪个迷宫的点访问的
int sx,sy; //起点

bool init()
{
    /* if( cin >> n >> m) { */
    int eof = scanf("%d%d",&n,&m);
    if( eof == 2){
        F3(i,0,n-1){
            scanf("%s",maze[i]) ;
            F3( j , 0 , m-1){
                if( maze[i][j] == 'S')
                    sx = i, sy = j;
            }
        }
        return true;
    }
    else return false;
}
int fx[][2] = {1,0,0,1,-1,0,0,-1};

bool in_map(int x,int y) {
    return x >= 0-n && x < n+n && y >=0-m && y < m+m;
}

//把{x,y} 映射到 中心的迷宫里
std::tuple<int,int> get_xy_org(int x,int y) {
    /* return std::make_tuple((x + n) % n ,(y+m) % m); */
    //不论x是正还是负,都能得到一个正的余数
    x %= n; 
    y %= m;
    return std::make_tuple((x + n) % n ,(y+m) % m);
}

bool bfs(int x,int y) {
    /* memset(vis,0,sizeof(vis)); */
    queue<node> q;
    q.push({x,y});
    vis[x][y] = {x,y}; //标记被x,y访问的

    while(!q.empty()) {
        int _x = q.front().x;
        int _y = q.front().y;
        q.pop();
        F3( i , 0 , 3){
            int nx = _x + fx[i][0];
            int ny = _y + fx[i][1];
            /* if( !in_map(nx,ny)) continue; //这个应该不需要 */
            auto [tox,toy] = get_xy_org(nx,ny); //得到映射到中心的x,y
            if( maze[tox][toy] =='#') continue;
            if( vis[tox][toy].x != inf && vis[tox][toy].y != inf) { //已经访问过
                //有不被访问的,被一个新的点访问了
                if( vis[tox][toy].x != nx || vis[tox][toy].y != ny) {
                    return true;
                }

                //那么现在nx,ny 必然是被 vis[tox][toy] 记录的点
            }
            else { //没有被访问过
                /* log(nx,ny); */
                vis[tox][toy] = {nx,ny};
                q.push({nx,ny});
            }
        }
    }
    return false;
}




int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    
    while(init()) {
        /* printf("%d %d\n",n,m); */
        memset(vis,0x7f,sizeof(vis));
        bool ans = bfs(sx,sy); //完全遍历所有的点
        if (ans)
            printf("Yes\n");
        else
            printf("No\n");
        /* F3( i , 0 , n-1){ */
        /*     F3( j , 0 , m-1){ */
        /*         if( vis[i][j].x != inf) */
        /*             printf("1"); */
        /*         else */
        /*             printf("0"); */
        /*     } */
        /*     printf("\n"); */
        /* } */
    }
    return 0;
}
