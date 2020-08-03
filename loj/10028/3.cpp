/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 16日 星期一 16:52:48 CST
* problem: loj-10028
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 3e3+5;
int n,L; //数据的数量
int ans;

int fx[] ={2,1,2,-1,-2,-1,-2,1};
int fy[] ={1,2,-1,2,-1,-2,1,-2};

bool vis[2][maxn][maxn]; //vis[1][i][j] bfs 1 是否访问过这个点
struct node { int x,y,s; };
queue<node> q[2];       // 双向bfs的两个队列
int sx,sy,tx,ty; // 起点终点
/* ======= 全局变量 END =======*/
void init(){
    memset(vis,0,sizeof(vis));

    while( !q[0].empty()) q[0].pop();
    scanf("%d",&L);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty); 
    sx++,sy++,tx++,ty++;
    vis[0][sx][sy] = 1;
    q[0].push({sx,sy,0}); // 起点入队
    q[1].push({tx,ty,0}); // 终点入队
}
bool inmap(int x,int y){
    if( x >=1 && x <= L && y >=1 && y <=L)
        return 1;
    return 0;
}

void expand(int k){ //拓展队列k
    if( sx == tx && sy == ty){ ans = 0; return; }
    while( !q[k].empty()){

        node head = q[k].front();q[k].pop(); //取出头部分的点
        int i;
        For(i,0,7){
            int nx = head.x + fx[i];
            int ny = head.y + fy[i];
            if( inmap(nx, ny) && !vis[k][nx][ny]){
                vis[k][nx][ny] = 1;
                q[k].push({nx,ny,head.s+1});
                if( nx == tx && ny == ty){
                    ans = head.s+1;
                    return;
                }
            }
        }

    }

}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d",&n);
    while(n -- ){
        init();
        ans = -1;
        expand(0);
        printf("%d\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
