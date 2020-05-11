/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 11日 星期一 09:04:18 CST
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
vector<int>   v;

int a[maxn];
int b[maxn];

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    scanf("%d",&m);
    int i,t;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    sort(a+1,a+1+n);
    for(i=2;i<=n;++i){
        b[i-1] = a[i]-a[i-1];
    }
    sort(b+1,b+n);
    int ans = 0;
    for(j = 1;j<=m;j++) ans += b[j];
    printf("%d\n",ans);


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
