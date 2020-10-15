/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 09月 05日 星期六 20:57:55 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e6+5;
int n,m;

void init(){
    
}

int main(){
    int i,j;

    long long pre = 2;
    printf("%d %d\n",1,2);
    long long t;
    for(i=2;i<=1e6;++i){
        t  = pre;
        pre = pre + i;
        //printf("%d %d\n",i,pre);
    }
    printf("%lld\n",t);

    return 0;
}
