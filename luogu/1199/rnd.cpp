/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 10月 16日 星期五 16:35:31 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;

random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<int> dis(1,99);

int randLR(){
    return dis(rnd);
}

int main(){
    int n = 6;
    printf("%d\n",n);
    int i,j;
    for(i=1;i<=n-1;++i){
        for(j=i+1;j<=n;++j){
            printf("%d ",randLR());
        }
        printf("\n");
    }
    return 0;
}
