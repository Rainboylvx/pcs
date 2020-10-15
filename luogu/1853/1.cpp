/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 24日 星期一 15:16:14 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 2e6+5;
int s,n,d;
int f[maxn];
int a[maxn],b[maxn];

void init(){
    scanf("%d%d%d",&s,&n,&d);
    int i,j;
    for(i=1;i<=d;++i){
        scanf("%d%d",&a[i],&b[i]);
    }
}

void full_pack(){
    int i,j,k;
    for(i=1;i<=d;++i){
        for(j=a[i];j<=s;j+=1000){
            f[j] = max(f[j],f[j-a[i]]+b[i]);
        }
    }
    int ans = 0;
    for(j=1000;j<=s;j+=1000) ans = max(ans,f[j]);
    s += ans;
}

int main(){
    init();
    int i,j,k;
    for(i=1;i<=n;++i){
        full_pack();
        //printf("%d %d\n",i,s);
    }
    printf("%d\n",s);

    return 0;
}
