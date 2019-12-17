/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 17日 星期二 08:59:34 CST
* problem:  online_judge-_id 
*----------------*/
#include <bits/stdc++.h>
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

void init(){
     xlx_init(); 
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
