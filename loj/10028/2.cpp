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
int dis[2][maxn][maxn];
struct node { int x,y,s; };
queue<node> q[2];       // 双向bfs的两个队列
int sx,sy,tx,ty; // 起点终点
/* ======= 全局变量 END =======*/
void init(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));

    while( !q[0].empty()) q[0].pop();
    while( !q[1].empty()) q[1].pop();
    scanf("%d",&L);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty); 

    q[0].push({sx,sy,0}); // 起点入队
    q[1].push({tx,ty,0}); // 终点入队
}
bool inmap(int x,int y){
    if( x >=1 && x <= L && y >=1 && y <=L)
        return 1;
    return 0;
}

bool expand(int k){ //拓展队列k
    node head = q[k].front();q[k].pop(); //取出头部分的点
    int i;
    For(i,0,7){
        int nx = head.x + fx[i];
        int ny = head.y + fy[i];
        if( inmap(nx, ny) && !vis[k][nx][ny]){
            vis[k][nx][ny] = 1;
            dis[k][nx][ny] = head.s +1;
            q[k].push({nx,ny,head.s+1});
            if( vis[k^1][nx][ny]){
                ans  = dis[k][nx][ny] + dis[k^1][nx][ny] ;
                return 1;
            }
        }
    }
    return 0;
}

void bfs(){
    if( sx == tx && sy == ty){ ans = 0; return; }

    while( !q[0].empty() &&  !q[1].empty()  ){
        if( q[0].size() < q[1].size()){
            if( expand(0)) return;
        }
        else{
            if( expand(1)) return;
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d",&n);
    while(n -- ){
        init();
        bfs();
        printf("%d\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
