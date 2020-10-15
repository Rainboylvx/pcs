/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 13日 星期四 14:59:39 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
typedef long long ll;
ll n,m,s;
ll w[maxn],v[maxn];
ll L[maxn],R[maxn];
ll _max = -1;
#define debug(...) //fprintf(stderr,__VA_ARGS__)
// printf => stdout
// stdin stdout stderr

void init(){
    scanf("%lld%lld%lld",&n,&m,&s);
    int i,j,k;
    for(i=1;i<=n;++i) {scanf("%lld%lld",&w[i],&v[i]); _max = max(w[i],_max); }
    for(i=1;i<=m;++i) scanf("%lld%lld",&L[i],&R[i]);
}

ll sum[maxn],sum_cnt[maxn];
ll get_Y(ll W){
    ll ret = 0;
    memset(sum,0,sizeof(sum));
    memset(sum_cnt,0,sizeof(sum_cnt));
    int i,j,k;
    for(i=1;i<=n;++i) {
        sum[i] += sum[i-1];
        sum_cnt[i] += sum_cnt[i-1];
        if( w[i] >= W){
            sum[i] += v[i]; 
            sum_cnt[i] += 1; 
        } 
        MYP("%lld %lld\n",sum[i],sum_cnt[i]);
    }
    for(i=1;i<=m;++i) {
        ll ans =  (sum[R[i]] - sum[L[i]-1]) * (sum_cnt[R[i]] - sum_cnt[L[i]-1]);
        MYP("==> %lld\n",ans);
        ret+= ans;
    }
    return ret;
}

ll bs(ll l , ll r){
    while (l != r) {
        ll m = (l+r)>>1;
        if( get_Y(m) >= s) l = m+1;
        else r = m;
    }
    return l;
}

int main(){
    init();
    MYP("%lld %d\n",get_Y(4),__LINE__);
    ll pos = bs(0ll,_max+1);

    ll a1 = get_Y(pos);
    ll a2 = get_Y(pos-1);
    if( abs(a2-s) <= abs(a1-s) )
        printf("%lld\n",abs(a2-s));
    else
        printf("%lld\n",abs(a1-s));

    return 0;
}
