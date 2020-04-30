/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 07 Apr 2020 04:49:28 PM CST
* problem:  loj-10012
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

double sum[maxn];
double eps = 1e-5;
bool check(double val){
    memset(sum,0,sizeof(sum));
    int i,j;
    double _min = 0;
    For(i,1,n){
        sum[i] = sum[i-1] + ( a[i] -val);
        if( i-m >=0) {
            _min = min(_min,sum[i-m]);
            if( sum[i] - _min >=0) 
                return 1;
        }
    }
    return 0;
}

void init(){
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
}

//查找范围是[l,r), a[r] 永远 > key
double first_g(double l,double r){
    double m;
    while( r-l >eps) //表示l和r没有重合
    {
        m = (l+r)/2; // 取中间位置
        if(check(m)) //表示 [m+1,r) 满足条件
            l = m;
        else
            r = m;
    }
    return r; // ????
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    double ans = first_g(0, 2000.0);
    //printf("%lf\n",ans*1000);
    ////printf("%d\n",check(5.299));
    printf("%d\n",(int)(ans*1000));

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
