/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 11日 星期一 21:54:37 CST
* problem:  loj-10016 
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
double H,h,D;

/* ======= 全局变量 END =======*/

// EF::work3(double l,double r)     三分,凸性函数机值问题,例如一元二次方程
// 核心思想：好点(更优点)与答案在坏点的同一侧
namespace EF_3 {
    double f(double v);
    double work3(double l,double r){
        double eps = 1e-8;
        while(r-l >= eps){
            double m1 = l+(r-l)/3 ,m2 = r-(r-l)/3;
            if( f(m1) <f(m2)) l = m1; // 谁小谁是坏点
            else r = m2;
        }
        return r;
    }
}
double EF_3::f(double x){
    return D+H-(x+(H-h)*D/x);
}

void init(){
    scanf("%lf%lf%lf",&H,&h,&D);
    double start_x =D - (h*D)/H;
    double end_x = D; //D的结束位置
    double ans = EF_3::work3(start_x, end_x);
    ans = EF_3::f(ans);
    ans = max(ans,D-start_x);
    ans = max(ans,h);
    printf("%.3lf\n",ans);
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while (t--) {
        init();
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
