/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 10:53:03 PM CST
* problem: loj-10007
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
struct node { int s,t; 
    bool operator<(const node &b){
        return t < b.t;
    }
};
node a[maxn];

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%d%d",&a[i].s,&a[i].t);
    }
    sort(a+1,a+n+1);
    int cnt = 1;

    int pre = a[1].t;
    for(i=2;i<=n;i++){
        if( a[i].s >= pre){
            cnt++;
            pre = a[i].t;
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
