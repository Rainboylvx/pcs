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

int fx[] ={1,2,2,1,-1,-2,-2,-1};
int fy[] ={2,1,-1,-2,-2,-1,1,2};

bool vis[2][maxn][maxn]; //vis[1][i][j] bfs 1 是否访问过这个点
int dis[2][maxn][maxn];
struct node { int x,y;};
//queue<node> q[2];       // 双向bfs的两个队列

int h[2]={0},t[2]={0};
node q[2][maxn*maxn];

inline void q_push(int k,int x,int y){
    q[k][t[k]++]= {x,y};
}
inline int q_empty(int k){ return t[k]-h[k]; }
inline node q_pop(int k){ return q[k][h[k]++];}


int sx,sy,tx,ty; // 起点终点
/* ======= 全局变量 END =======*/
void init(){
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));

    memset(h,0,sizeof(h));
    memset(t,0,sizeof(t));
    memset(q,0,sizeof(q));

    scanf("%d",&L);
    scanf("%d%d%d%d",&sx,&sy,&tx,&ty); 
    sx++,sy++,tx++,ty++;
    vis[0][sx][sy] = 1;
    vis[1][tx][ty] = 1;
    q_push(0,sx,sy); // 起点入队
    q_push(1,tx,ty); // 终点入队
}
bool inmap(int x,int y){
    if( x >=1 && x <= L && y >=1 && y <=L)
        return 1;
    return 0;
}

bool expand(int k){ //拓展队列k

    node head = q_pop(k); //取出头部分的点
    
    int i;
    For(i,0,7){
        int nx = head.x + fx[i];
        int ny = head.y + fy[i];
        if( inmap(nx, ny) && !vis[k][nx][ny]){
            vis[k][nx][ny] = 1;
            dis[k][nx][ny] = dis[k][head.x][head.y] +1;
            q_push(k,nx,ny);
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

    while( q_empty(0) &&  q_empty(1)  ){
        if(q_empty(0) < q_empty(1)){
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
