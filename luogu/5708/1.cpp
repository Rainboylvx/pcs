/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 11日 星期一 17:50:38 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
double a,b,c;


int main(){
    scanf("%lf%lf%lf",&a,&b,&c);
    double p = (a+b+c)/2;
    double ans = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%.1lf\n",ans);

    return 0;
}
