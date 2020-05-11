/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 11日 星期一 09:39:33 CST
* problem: luogu-2671
* ----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
const int mod = 10007;
int n,m;

int cnt[maxn][2]; // 颜色,组,计数
int sum[maxn][2]; // 组的值和


struct node {
    int val,col; //值,颜色
};
node a[maxn];

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i) scanf("%d",&a[i].val);
    for(i=1;i<=n;++i) scanf("%d",&a[i].col);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for(i=1;i<=n;++i){
        int col = a[i].col;
        int pos = i % 2;  // 分 奇偶 组
        cnt[col][pos]++; //计数
        sum[col][pos] +=  a[i].val;
        sum[col][pos] %=  mod;
    }
    int ans = 0;
    for(i=1;i<=n;++i){
        int col = a[i].col;
        int pos = i % 2;  // 分 奇偶 组
        ans =(ans+ (i*(((cnt[col][pos]-2) % mod*(a[i].val % mod)) %mod + sum[col][pos]) ) )% mod;
        //ans %= mod;
        //printf("%d\n",ans);
    }
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
