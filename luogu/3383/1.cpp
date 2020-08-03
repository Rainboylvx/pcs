/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 25日 星期三 14:19:12 CST
* problem:  luogu-3383
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e7+5;
int n,m;
/* 线性欧拉筛 */
int notp[maxn] = {1,1};
int p[maxn];
void ola(){
    int i,j;
    For(i,2,maxn){
        if( !notp[i] ) p[++p[0]] = i;
        for(j=1;j<=p[0] && p[j] * i <=maxn ;++j){
            notp[ p[j]*i ] = 1;
            if( i % p[j] == 0) break;
        }
    }
}

void init(){
    ola();
    scanf("%d%d",&n,&m);
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,t;
    For(i,1,m){
        scanf("%d",&t);
        printf("%s\n", notp[t] ? "No":"Yes");
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
