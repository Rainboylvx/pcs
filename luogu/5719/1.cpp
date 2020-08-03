/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 24日 星期日 10:23:02 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,k;

int main(){
    scanf("%d%d",&n,&k);
    int a=0,cnta=0,b=0,cntb=0;
    int i;
    for(i=1;i<=n;++i){
        if( i % k == 0){
            cnta++;
            a += i;
        }
        else {
            cntb++;
            b+=i;
        }
    }
    printf("%.1lf %.1lf",a*1.0/cnta,b*1.0/cntb);

    return 0;
}
