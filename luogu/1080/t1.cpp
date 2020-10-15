/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 18日 星期二 20:08:58 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
typedef long long ll;
int n,m;
int a[maxn];

struct P {
    ll l,r;
};
P p[maxn];
P g;

void init(){
    scanf("%d",&n);
    int i,j;
    
    scanf("%lld%lld",&g.l,&g.r);
    for(i=1;i<=n;++i){
        scanf("%lld%lld",&p[i].l,&p[i].r);
        a[i] = i;
    }
}

ll calc(){
    int i,j;
    ll s = g.l;
    ll ans = -1;
    for(i=1;i<=n;++i){
        ll t = s / p[a[i]].r;
        //printf("%lld ",t);
        ans = max(ans,t);
        s *= p[a[i]].l;
    }
    //printf("\n");
    return ans;
}

int main(){
    init();
    ll ANS = 0x7f7f7f7f7f7f7f7f;
    do {
        int i,j;
        //for(i=1;i<=n;++i){
            //printf("%d ",a[i]);
        //}
        //printf("\n");
        ll ans = calc();
        ANS = min(ANS,ans);
        //printf("=》 %lld\n",ans);
        //printf("\n");
    }
    while( next_permutation(a+1,a+1+n));
    printf("%lld\n",ANS);

    return 0;
}
