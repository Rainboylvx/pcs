/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 22日 星期日 12:29:15 CST
* problem: luogu-1059
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n;
int a[1005];
int cnt;
void init(){
    scanf("%d",&n);
    int i,t;
    For(i,1,n){
        scanf("%d",&t);
        if(!a[t]) cnt++;
        a[t]++;
    }
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i;
    printf("%d\n",cnt);
    For(i,1,1000){
        if(a[i]) 
            printf("%d ",i);
    }
    printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
