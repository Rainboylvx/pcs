/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 19:36:48 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int a[1005][1005],f[1005][1005];

//f[i][j] = max{f[i+1][j],f[i+1][j+1]} + a[i][j]
//f[i][j] 表示 从第i行第j个数开始向下走,到达最后一行的最大值
void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=i;++j){
            scanf("%d",&a[i][j]);
        }
    }
}

int main(){
    init();
    int i,j;
    for( i =1;i<=n;i++) 
        f[n][i] = a[n][i];
    for( i=n-1;i>=1;i--){ //枚举行
        for(j=1;j<=i;j++){//行里的每个数
            f[i][j] = max(f[i+1][j],f[i+1][j+1]) + a[i][j];
        }
    }
    printf("%d\n",f[1][1]);

    return 0;
}
