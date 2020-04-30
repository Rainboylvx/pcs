/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 10:49:02 PM CST
* problem:  loj-10006
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
int a[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    int cnt = 1;
    int sum = 0;

    for( i =1;i<=n;i++){
        sum += a[i];
        if(sum > m){
            sum = a[i];
            cnt++;
        }
    }

    printf("%d\n",cnt);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
