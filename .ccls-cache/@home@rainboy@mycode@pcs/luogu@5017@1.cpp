/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 10日 星期一 09:32:35 CST */
#include <bits/stdc++.h>
#include <cpp_tools.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
int n,m;
ll f[maxn];
ll sum[maxn],sum_cnt[maxn];
ll t[maxn];
int cnt[maxn];
int idx;

// f[j] = min{f[i]} + (i,j)->j
//
int calc_time(int l,int r){
    int lp = lower_bound(t+1,t+idx+1,(ll)l)-t;
    int rp = upper_bound(t+1,t+idx+1,(ll)(r))-t-1;
    ll s = sum[rp] - sum[lp-1];
    ll c = sum_cnt[rp] - sum_cnt[lp-1];
    return c*r - s;
}



int main(){
    scanf("%d%d",&n,&m);
    int i,j,k;
    if( m == 1){
        printf("%d\n",0);
        return 0;
    }
    else 
        //if ( m == 2) 
    {
        for(i=1;i<=n;++i) scanf("%lld",&t[i]);
        sort(t+1,t+1+n);
        idx = 1;
        sum_cnt[1] = 1;
        for(i=2 ;i<=n;i++ ){
            if( t[i] == t[i-1]) sum_cnt[idx]++;
            else {
                t[++idx] = t[i];
                sum_cnt[idx] = 1;
            }
        }
        for(i=1;i<=idx;i++){
            sum[i] = sum_cnt[i]*t[i]+sum[i-1];
            sum_cnt[i] += sum_cnt[i-1];
        }
        #ifdef DEBUG
        for(i=1;i<=idx;i++){
            printf("%lld %lld %lld\n",t[i],sum_cnt[i],sum[i]);
        }
        #endif
        for(j=t[1];j<=t[1]+m;j++) {
            f[j] = calc_time(0, j);
            printf("%lld %lld\n",j,f[j]);
        }
        for(i=2;i<=idx;i++){
            ll base = 0x7f7f7f7f7f7f7f7f;
            if(t[i] - t[i-1] > m){
                for(j=t[i-1];j<=t[i-1];j++)
                    base = min(base,f[j]);
                for(j=t[i-1];j>=t[i-1]-m;j--)
                    f[j] = base;
                for(j=t[i];j<=t[i]+m;j++){
                    f[j] = 0x7f7f7f7f7f7f7f7f;
                    for(k =max(0,j-m);k< j;k++)
                        f[j] = min(f[j],f[k]+calc_time(k+1, j));
                    //printf("%d %d\n",j,f[j]);
                }
            }
            else
                for(j=t[i];j<=t[i]+m;j++){
                    f[j] = 0x7f7f7f7f7f7f7f7f;
                    for(k =max(0,j-m);k< j;k++)
                        f[j] = min(f[j],f[k]+calc_time(k+1, j));
                    //printf("%d %d\n",j,f[j]);
                }
        }
        ll ans = 0x7f7f7f7f7f7f7f7f;
        for(i=t[idx]+m;i >= 0 && i >= t[idx] ;i--){
            ans = min(ans,f[i]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
