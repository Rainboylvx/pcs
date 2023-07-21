/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-18 10:17:56
*----------------*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1505,maxe = 1e6+5; //点与边的数量

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


int n,m;
/* 定义全局变量 */

// int a[maxn]; //常用的一个数组 
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

int vis[maxn][maxn]; // 求连通块,对应新的图上的点的编号
bool is_cross[maxn]; // 对应点是否是贯通

bool in_circle[maxn];// 点是否在环上
int deg[maxn]; //点的度
//起点在环上,且起点所在的环有贯通点

//求联通块
bool bfs() {

}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    
    while( init()) {

    }
    return 0;
}
