/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 12日 星期二 16:32:26 CST
* problem: loj-2653
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e3+5;
const int maxe = 1e6+5;
bool all_same = 1;
int n;
/* 仿函数 */
struct in_map {
    int min_x,max_x,min_y,max_y;

    in_map(){ min_x=max_x=min_y=max_y=0;}
    in_map( int x0, int x1, int y0, int y1 ): min_x(x0),max_x(x1),min_y(y0),max_y(y1){}

    /* 设置边界*/
    void set( int x0, int x1, int y0, int y1 ){
        min_x = x0 , max_x = x1 ,min_y = y0 ,max_y = y1;
    }

    bool operator()(int x,int y){
        if( x >= min_x && x<=max_x && y >= min_y && y <=max_y)
            return 1;
        return 0;
    }
};
in_map inM;

/* ======= 全局变量 END =======*/
int m[maxn][maxn];
bool vis[maxn][maxn];
void init(){
    int pre = -1;
    scanf("%d",&n);
    inM = in_map(1,n,1,n);
    int i,j;
    For(i,1,n){
        For(j,1,n){
            scanf("%d",&m[i][j]);
            if( pre != -1 && pre != m[i][j])
                all_same = 0;
            else
                pre = m[i][j];
        }
    }
}

/* 顺时针-8个方向 */
int fx[][2] = { {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1} };


int cnt,_max,_min;
void dfs(int x,int y,int start){
    vis[x][y] = 1;
    cnt++;
    int i;
    for(i=0;i<=7;++i){
        int nx = x+fx[i][0];
        int ny = y+fx[i][1];
        if(!inM(nx,ny)) continue; //在地图内
        if( m[nx][ny] != start){
            _max = max(_max,m[nx][ny]);
            _min = min(_min,m[nx][ny]);
        }
        else if( !vis[nx][ny])
            dfs(nx,ny,start);

    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    if( all_same){
        printf("1 1");
        return 0;
    }
    int i,j;
    int up=0,down=0;
    For(i,1,n){
        For(j,1,n){
            if( !vis[i][j]){
                cnt = 0;
                _max = -1;
                _min = 0x7fffffff;
                dfs(i,j,m[i][j]);
                if( cnt == n*n){
                    printf("1 1\n");
                    return 0;
                }
                if( m[i][j] > _max )
                    up++;
                else if( m[i][j] < _min)
                    down++;
            }
        }
    }
    printf("%d %d\n",up,down);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
