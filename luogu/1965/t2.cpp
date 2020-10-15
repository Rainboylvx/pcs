/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 19日 星期三 16:01:21 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;

int gcd(int a,int b){
    if( b == 0) return a;
    return gcd(b,a%b);
}

void init(){
    scanf("%d%d",&n,&m);
    int lcm = n*m/gcd(n,m);
    int ans = lcm / m;
    printf("%d\n",ans);
}

int main(){
    init();

    return 0;
}
