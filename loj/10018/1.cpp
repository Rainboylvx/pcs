/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 08:34:34 PM CST
* problem: loj-10018
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,k;
int ans=0;

void dfs(int dep,int pre,int lef){
    if( dep == k){
        if( lef >= pre) ans++;
        return;
    }
    int i;
    for(i = pre ;i <=lef/(k-dep) ;i++)
        dfs(dep+1,i,lef-i);
}

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&k);
    dfs(1,1,n);
    printf("%d\n",ans);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
