/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 24日 星期一 16:25:51 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e4+5;
int n,t,k;
int f[maxn];
int v[maxn],h[maxn];

void init(){
    scanf("%d%d%d",&n,&t,&k);
    int i;
    for(i=1;i<=n;++i){
        scanf("%d%d",&v[i],&h[i]);
    }
}

int full_pack(int choose){
    int ans = 0;
    memset(f,0,sizeof(f));
    int i,j;
    for(i=1;i<=n;++i){
        //if( i == choose) continue;
        int s = h[i]/5*4;
        for(j=s;j<=t-h[choose];++j){
            f[j] = max(f[j],f[j-s]+v[i]);
        }
    }
    return f[t-h[choose]];
}

int main(){
    init();
    int i,j;
    int ANS = 0;

    //必选一个大的
    for(i=1;i<=n;++i){
        if(h[i] < k) continue;
        //printf("%d %d\n",i,h[i]);
        int ans = full_pack(i);
        ANS = max(ANS,ans+v[i]);
    }

    //全选小的
    memset(f,0,sizeof(f));
    for(i=1;i<=n;++i){
        if(h[i] >= k) continue;
        for(j=h[i];j<=t;++j){
            f[j] = max(f[j],f[j-h[i]]+v[i]);
        }
    }

    printf("%d\n",max(ANS,f[t]));

    return 0;
}
