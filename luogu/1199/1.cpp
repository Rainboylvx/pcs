/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 10月 16日 星期五 11:22:43 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 505;
int n,m;
int a[maxn][maxn];

void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n-1;++i){
        for(j=i+1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[j][i] = a[i][j];
        }
    }
}


int main(){
    init();
    int i,j;
    int ans = -1;
    for(i=1;i<=n;++i){
        int max1 =-1,max2 = -1;
        for(j=1;j<=n;j++){
            if( a[i][j] > max1){
                max2 = max1;
                max1 = a[i][j];
            }
            else if( a[i][j] > max2){
                max2 =a[i][j];
            }
        }
        if( max1 > max2)
            ans = max(ans,max2);
    }
    if( ans == -1)
        printf("%d\n",0);
    else {
        printf("%d\n",1);
        printf("%d\n",ans);
    }

    return 0;
}
