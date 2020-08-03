/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 21日 星期四 14:01:36 CST
* problem: luogu-5056
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

long long dp[2][600000],all_ans = 0;
int mapx[20][20],endx,endy;
int bits[28];

int state[2][600000]={0},tots[2]={0};
int pre=1,cnt=0;

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    char s[30];
    int i,j;
    For(i,1,n){
        scanf("%s",s+1);
        For(j,1,m){
            if (s[j] == '.')
                mapx[i][j] = 1,endx=i,endy=j;
        }
    }
    // init bits
    For(i,1,25){
        bits[i] = (i<<1); // ? *2 ?
    }

}

void DP(){
    tots[cnt] = 1;
    dp[cnt][1]= 1;
    state[cnt][1] = 1;
    int i,j;
    for( i =1;i<=n;i++){ // 枚举行
        for(j=1;j<=tots[cnt];j++)
            state[cnt][j] <<=2; // ??
        for(j=1;j<=m;j++){ //枚举列
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
