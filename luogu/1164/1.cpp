/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 11:04:55 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int f[10005];

int main(){
    scanf("%d%d",&n,&m);
    f[0] = 1;
    int i,j,t;
    for( i =1;i<=n;i++){
        scanf("%d",&t);
        for(j=m;j>=t;j--){
            f[j] = f[j] + f[j-t];
        }
    }
    printf("%d\n",f[m]);
    return 0;
}
