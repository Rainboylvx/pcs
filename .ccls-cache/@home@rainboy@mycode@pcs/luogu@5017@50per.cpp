/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 10日 星期一 09:32:35 CST */
#include <bits/stdc++.h>
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
        //for(i=1;i<=idx;i++){
            //printf("%lld %lld %lld\n",t[i],sum_cnt[i],sum[i]);
        //}
        for(i=t[1];i<=t[idx]+m;i++){
            f[i]  = 0x7f7f7f7f7f7f7f7f;
            if(i-m<0){
                f[i] = calc_time(0,i);
            }
            else{
                for(j=max(0,i-2*m);j <=i-m;j++){
                    ll tim = calc_time(j+1,i);
                    f[i] = min(f[i],f[j]+tim);
                    //f[i] = min(f[i],f[j]+calc_time(j+1, i));
                }
            }
            //printf("%d %d\n",i,f[i]);
        }
        ll ans = 0x7f7f7f7f7f7f7f7f;
        for(i=t[idx]+m;i >= 0 && i >= t[idx] ;i--){
            ans = min(ans,f[i]);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
