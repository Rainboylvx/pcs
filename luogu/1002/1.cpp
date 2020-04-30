/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 29 Apr 2020 07:58:45 AM CST
* problem: luogu-1002
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
typedef long long ll;
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
int xb,yb,xa,ya;
ll f[50][50];
int _map[50][50];
int fx[8][2] ={
    1,2,
    1,-2,
    2,1,
    2,-1,
    -1,2,
    -1,-2,
    -2,1,
    -2,-1
};

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d%d%d",&xb,&yb,&xa,&ya);
    f[0][0] = 1;
    //马能到达的点
    int i;
    For(i,0,7){
        int nx = xa + fx[i][0];
        int ny = ya + fx[i][1];
        //在地图内
        if(nx >= 0 && ny >=0 && nx <= xb && ny <= yb)
            _map[nx][ny] = 1;
    }
    _map[xa][ya] = 1;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for(i=0;i<=xb;++i){
        for(j=0;j<=yb;++j){
            if( i - 1 >=0 && _map[i-1][j] == 0) 
                f[i][j] += f[i-1][j];
            if( j- 1 >=0 && _map[i][j-1] == 0)
                f[i][j] += f[i][j-1];
            //printf("%d ", f[i][j]);
        }
        //printf("\n");
    }
    printf("%lld\n",f[xb][yb]);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
