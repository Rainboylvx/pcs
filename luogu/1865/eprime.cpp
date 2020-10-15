/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 14日 星期五 19:43:24 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e6+5;
int n,m;
int cnt[maxn];
bool del[maxn];

void e_prime(int n){
    int i,j;
    for(i=2;i<=n;++i){
        cnt[i] += cnt[i-1];
        if( !del[i]){
            debug("=>%d\n",i);
            cnt[i] += 1;
            if( i > n/i) continue;
            for(j=i*i;j<=n;j+=i) del[j] = 1;
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    e_prime(m);
    int i,j;
    int l,r;
    for(i=1;i<=n;++i){
        scanf("%d%d",&l,&r);
        if( l < 1 || r > m){
            printf("Crossing the line\n");
            continue;
        }
        else printf("%d\n",cnt[r]-cnt[l-1]);
    }

    return 0;
}
