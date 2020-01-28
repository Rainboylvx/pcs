/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 01月 27日 星期一 20:19:45 CST
* problem:  loj-10155
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

const int maxn = 50005;
int sum[maxn]; //约数和,不包括自己本身
int d1[maxn],d2[maxn]; //最值1,最值2

void init(){
    scanf("%d",&n);
    int i,j;
    for( i =1;i<=n;i++)
        for(j = 2;j<=n/i;j++){
            sum[i*j] += i;
        }

}
/* ======= 全局变量 END =======*/

void dp(){
    int i,j;
    for(i=n;i >= 1;i--){ //从大到小枚举
        if( sum[i] < i){ //存在树上的点,sum[i]为自己的父亲
            if(d1[i]+1 > d1[sum[i]]){
                d2[sum[i]] = d1[sum[i]] ;
                d1[sum[i]] = d1[i]+1;
            }
            else if( d1[i]+1 > d2[sum[i]])
                d2[sum[i]] = d1[i]+1 ;
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dp();
    int ans = 0;
    int i;
    For(i,1,n){
        ans = max( ans,d1[i]+d2[i]);
    }
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
