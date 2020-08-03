/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 01月 07日 星期二 22:00:32 CST
* problem: luogu-5886
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m,p;
const int maxn = 1e6+5;
const int maxm = 1e6+5;
int cnt[maxn];

/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d%d",&n,&m,&p);
    int i,j,k,t;
    For(i,1,n){
        scanf("%d",&k);
        For(j,1,k){
            scanf("%d",&t);
            cnt[t]++;
        }
    }
    int ans = 0;
    For(i,1,m){
        if( cnt[i] == p) ans++;
    }
    printf("%d\n",ans);
    For(i,1,m){
        if( cnt[i] == p)
            printf("%d ",i);
    }
    printf("\n");


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
