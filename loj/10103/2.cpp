/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 18日 星期一 17:52:59 CST
* problem:  online_judge-_id 
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

/* ======= 全局变量 END =======*/
int cnt;
int k = 7;
void init(){
    cnt++;
    int i,u,v;
    if( cnt == k)
        printf("%d %d\n",n,m);
    For(i,1,m){
        scanf("%d%d",&u,&v);
    if( cnt == k)
        printf("%d %d\n",u,v);
    }
    if( cnt == k) return ;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while (1) {
        scanf("%d%d",&n,&m);
        if( !n && !m ) break;
        init();
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
