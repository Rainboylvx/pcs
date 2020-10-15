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
bool cmp(P a,P b){
    return a.l*a.r < b.l*b.r;
}

int main(){
    init();
    sort(p+1,p+1+n,cmp);
    int i,j;
    ll ans = -1;
    ll s = g.l;
    for(i=1;i<=n;++i){
        ll t = s / p[i].r;
        ans = max(ans,t);
        s *= p[i].l;
    }
    printf("%lld\n",ans);
    return 0;
}
