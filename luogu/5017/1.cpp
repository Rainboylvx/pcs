/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 12日 星期三 08:57:56 CST */
// f[i] = max{f[j]} +calc(j+1,i)
#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 4e6+5;
typedef long long ll;
const ll inf = 0x7f7f7f7f7f7f7f7f;
int n,m;
ll f[maxn];

ll sum[maxn],sum_cnt[maxn],a[maxn];
int idx = 0;

// 计算[l,r] 区间内的人到等到r需要的时间
ll calc(int l,int r){
    int lp = lower_bound(a+1,a+idx+1,(ll)l)-a; //第一个 >= l的人的位置
    int rp = upper_bound(a+1,a+idx+1,(ll)(r))-a-1;//最后一个 <= r的人的位置
    ll s = sum[rp] - sum[lp-1];
    ll c = sum_cnt[rp] - sum_cnt[lp-1];
    return c*r - s;
}


void init(){
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    sum_cnt[++idx] = 1;
    for(i=2;i<=n;i++){
        if( a[i] ==a[i-1]){
            sum_cnt[idx]++;
        }
        else {
            sum_cnt[++idx] = 1;
            a[idx] = a[i];
        }
    }
    for(i=1;i<=idx;i++){
        sum[i] = sum[i-1] + a[i]*sum_cnt[i];
        sum_cnt[i] += sum_cnt[i-1];
        #ifdef DEBUG
            debug("%lld %lld %lld\n",a[i],sum[i],sum_cnt[i]);
        #endif
    }
}

//计算f的值,利用前趋,计算f[l]->f[r]
void calc_f_by_pre(int l,int r){
    int i,j,k;
    for(i=l;i<=r;i++){
        f[i] = inf;
        if( i-m<0) f[i] = calc(l,i); //这是第一次发车,前面不能发车
        else {
            for(j = max(0,i-2*m+1);j<=i-m;j++)
                f[i] = min(f[i],f[j]+calc(j+1,i));
        }
        debug("%d %lld\n",i,f[i]);
    }
}

int main(){
    init();
    if( m ==1){
        printf("%d\n",0);
        return 0;
    }
    int i,j,k;
    //dp
    //计算第一个人后m-1个位置
    debug("计算过程:\n");
    calc_f_by_pre(a[1], a[1]+m-1);
    for( i =2;i<=idx;i++){
        int pre = i-1; //上一个人的位置
        if( a[i] - a[pre] >=2*m){ //距离很远
            ll base = inf;
            for(j=a[pre];j<a[pre]+m;j++) base = min(base,f[j]); //最小值
            for(j=a[i];j<a[i]+m;j++){
                f[j] = calc(a[i],j) + base;
                debug("%lld %lld\n",j,f[j]);
            }
            for(j=a[i]-1;j>=max(a[i]-2*m,ll(0));j--)
                f[j] = base;
        }
        else { //距离不远
            calc_f_by_pre(a[pre]+m,a[i]+m-1);
        }
    }
    debug("输出结果\n");
    ll ans = inf;
    for(i=a[n] ;i < a[n]+m;i++){
        ans = min(ans,f[i]);
#ifdef DEBUG
        debug("%lld %lld\n",i,f[i]);
#endif
    }
    printf("%lld\n",ans);
    
    return 0;
}
