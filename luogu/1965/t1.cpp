/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 19日 星期三 15:48:45 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m,k,x;
typedef long long ll;

void init(){
    scanf("%d%d%d%d",&n,&m,&k,&x);
}
int start;
int wz[maxn];

void lun(){
    int i,j;
    start += m;
    start %= n;
    debug("=>> 0 at %d\n",start);
    //for(i=1;i<=n;i++){

    //}
}

int main(){
    init();
    ll i,j;
    ll end =1;
    for( i=1;i<=k;i++) end*=10;
    for(i=1;i<=end;i++){
        debug("%10lld ",i);
        lun();
    }

    return 0;
}
