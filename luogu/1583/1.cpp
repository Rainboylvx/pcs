/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 22日 星期日 12:43:04 CST
* problem: luogu-1583
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,k;
int e[11];

struct _p{
    int w,d,c,e,b;
    bool operator<(const _p &x){
        if( w != x.w) return w > x.w;
        return b < x.b;
    }
};
_p p[20005];

void init(){
    scanf("%d%d",&n,&k);
    int i;
    For(i,1,10) scanf("%d",&e[i]);
    For(i,1,n){
        scanf("%d",&p[i].w);
        p[i].b = i;
    }
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int i;
    init();
    sort(p+1,p+1+n);
    //For(i,1,k){
        //printf("%d ",p[i].b);
    //}
    //printf("\n");
    //printf("\n");
    //printf("\n");
    For(i,1,n){
        int c = (i -1) %10 +1;
        p[i].w += e[c];
    }
    sort(p+1,p+1+n);
    For(i,1,k){
        printf("%d ",p[i].b);
    }
    //printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
