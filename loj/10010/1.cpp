/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 09:35:29 AM CST
* problem: loj-10010
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;

ll a[maxn];
ll s[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i,j;
    ll sum = 0;
    For(i,1,n){
        scanf("%lld",&a[i]);
        sum += a[i];
    }
    int avg = sum / n;
    For(i,1,n){
        s[i] = s[i-1] + (a[i]- avg);
    }
    sort(s+1,s+1+n);
    int k = (n+1) >>1;
    sum = 0;
    For(i,1,n){
        sum += abs( s[i]-s[k]);
    }
    printf("%lld\n",sum);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
