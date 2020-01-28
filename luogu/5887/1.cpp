/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 01月 07日 星期二 23:12:38 CST
* problem: luogu-5887
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
int n,m,k;
int p[maxn];
bool vis[maxn];

void init(){
    scanf("%d%d%d",&n,&m,&k);
    int i;
    For(i,1,m){
        scanf("%d",&p[i]);
        p[i]++;
    }
}
/* ======= 全局变量 END =======*/
int gcd(int a,int b){ if( b == 0) return  a; return gcd( b , a %b); }


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int g;
    if( k == 1) { printf("%d\n",0); return 0; }
    g = gcd(n,k);
    if(g == 1){ printf("%d\n",0); return 0; }
    int i,t;
    For(i,1,m){
        vis[p[i] % g] = 1;
    }
    int cnt = 0;
    For(i,0,g-1){
        if(!vis[i]) cnt++;
    }
    printf("%d\n",n / g*cnt);


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
