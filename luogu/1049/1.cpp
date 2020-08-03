/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 09:11:37 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int V;
int n,m;
int a[100];
int f[100][20005];

void init(){
    scanf("%d",&V);
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
}

int main(){
    init();
    //dp 01_pack
    int i,j;
    for(i=1;i<=n;i++)
        for( j=1;j<=V;j++){
            if( j < a[i]) 
                f[i][j] = f[i-1][j];
            else
                f[i][j] =max(f[i-1][j],f[i-1][j-a[i]]+a[i]);
        }
    printf("%d",V-f[n][V]);

    return 0;
}
