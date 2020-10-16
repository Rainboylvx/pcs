/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 10月 16日 星期五 16:35:31 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;

namespace RAND {
    void init(){
        srand(time(0));
    }
    int rand0N(int n){
        return rand() % (n+1);
    }
    int randLR(int l,int r){
        return rand0N(r-l) + l;
        //(0,r-l) + l = (l,r)
    }
}

int main(){
    int n = 4;
    printf("%d\n",n);
    int i,j;
    for(i=1;i<=n-1;++i){
        for(j=i+1;j<=n;++j){
            printf("%d ",RAND::randLR(1,10));
        }
        printf("\n");
    }

    return 0;
}
