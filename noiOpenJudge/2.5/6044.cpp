/* 
 * 思路:应该和第三次写的一样,细节的问题,导致超时,要优化
 *
 * 对一个点:[x,y,T], 坐标,和T值
 * 如果队列头的点可以访问的4个点是'#',那T要-1,
 *
 *
 *
 * 最关键的问题是:
 *  1.有的时候一个点已经VIS过了,但是还可以再次被访问
 *      同样的步数但是T更大也就是这个点可以被再次入队
 *  !!!BFS每一次入队的点一定都是第N次能被访问到的点
 * */

/* 
 *
 *  +---+    +---+
 *  | A |--->| B |
 *  +---+    +---+
 *
 * 如果B被VIS过,
 *
 * T =3 时候
 * ###@*
 * ####*
 * +###*
 * */

/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 20日 星期日 19:51:33 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,T;
/* 定义全局变量 */
char mg[400][400];
int sx,sy,tx,ty;
struct node {
    int x,y,step,t;
};

int ST[400][400]; //到这个点的剩余 查克拉
bool vis[400][400];


void init(){
    scanf("%d%d%d",&n,&m,&T);
    for(int i=1;i<=n;++i){
        scanf("%s",mg[i]+1);
        for(int j=1;j<=m;++j){
            if( mg[i][j] == '@' ) {
                sx = i, sy =j;
            }
            if( mg[i][j] == '+' ) {
                tx = i, ty =j;
            }
        }
    }
}

/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };

bool in_mg(int x,int y){
    return x>=1 && x<= n &&  y>=1 && y <=m;
}

int bfs(){
    queue<node> q;
    q.push({sx,sy,0,T});
    vis[sx][sy] =1;
    ST[sx][sy] = T;

    while ( !q.empty() ) {
        node h = q.front();
        q.pop();

        if(h.x == tx && h.y == ty ) return h.step;
        if( h.step >= n*m) return -1;

        for(int i=0;i<=3;++i){
            int nx  = h.x+ fx[i][0];
            int ny  = h.y+ fx[i][1];
            if( !in_mg(nx,ny) ) continue;
            
            int ns = h.step+1;
            //printf("(%d %d %d %d) ->",h.x,h.y,h.step,h.t);
            if( vis[nx][ny] == 0){
                if( mg[nx][ny] == '#' ){
                    if(  h.t -1 >=0){
                        q.push({nx,ny,ns,h.t-1});
                        vis[nx][ny] = 1;
                    }
                }
                else {
                    q.push({nx,ny,ns,h.t});
                    vis[nx][ny] = 1;
                }
            }
            else { //已经到，现在step一定大，
                if( mg[nx][ny] == '#' ){
                    if(  h.t -1 >=0 && h.t-1 > ST[nx][ny]){
                        q.push({nx,ny,ns,h.t-1});
                        ST[nx][ny] = h.t-1;
                    }
                }
                else if(h.t > ST[nx][ny] ) {
                    q.push({nx,ny,ns,h.t});
                    ST[nx][ny] = h.t;
                }
            }

        }
    }

    return -1;
}

int main(){
    init();
    int ans = bfs();
    printf("%d",ans);
    return 0;
}
