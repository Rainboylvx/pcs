/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 07 Apr 2020 10:46:48 PM CST
* problem: loj-10013
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
int a[maxn],b[maxn],c[maxn];

/* ======= 全局变量 END =======*/

void init(){
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
}

double get_max(double x){
    double m = a[1]*x*x+b[1]*x+c[1];
    int i;
    For(i,2,n){
        m = max(m, a[i]*x*x+b[i]*x+c[i]);
    }
    return m;
}
const double eps = 1e-9;

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while (t--) {
        init();
        double l = 0,r = 1000;

        while( r -l > eps){
            double m1 = l + (r-l)/3;
            double m2 = r - (r-l)/3;
            if( get_max(m1) < get_max(m2))
                r = m2; //m2 是坏点
            else
                l = m1;
        }

        //printf("l = %lf\n",l);
        //printf("r = %lf\n",r);
        printf("%.4lf\n",get_max(l));
        //printf("%.4lf\n",get_max(0.5));
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
