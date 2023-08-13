/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 27日 星期四 17:48:06 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

ll n,m,s;
/* 定义全局变量 */
ll w[maxn];
ll v[maxn];
ll Left[maxn],Right[maxn];
ll max_w;
ll sum_cnt[maxn],sum[maxn];

void init()
{
    std::cin >> n >> m >> s;
    for(ll i=1;i<=n;++i){
        std::cin >> w[i] >> v[i];
        // std::cout << w[i] <<" "<< v[i] << std::endl;
        if( max_w < w[i])
            max_w = w[i];
    }
    for(ll i=1;i<=m;++i){
        std::cin >> Left[i] >> Right[i];
        // std::cout << Left[i] <<" "<< Right[i] << std::endl;
    }
}

ll check(ll weight) 
{
    ll ret = 0;
    for(int i=1;i<=n;++i){
        if( w[i] >= weight)
        {
            sum_cnt[i] = sum_cnt[i-1]+1;
            sum[i] = w[i] + sum[i-1];
        }
        else
        {
            sum_cnt[i] = sum_cnt[i-1];
            sum[i] = sum[i-1];
        }
    }
    for(int i=1;i<=m;++i){
        int r = Right[i];
        int l = Left[i];
        ll cnt = sum_cnt[r] -sum_cnt[l-1]; 
        ll _sum = sum[r] - sum[l-1];
        ret += _sum * cnt;
    }
    return  ret;
}

int binary_search(int l,int r) {
    while( l  < r) {
        int mid  = (l+r) >> 1;
        if( check(mid) <= s )
            r = mid;
        else 
            l = mid+1;
    }
    return l;
}

ll _abs(ll a ) {
    if( a < 0)
        return  -a;
    return a;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    int pos = binary_search(0, 100001);
    cout << pos;
    ll v1 = check(pos);
    ll v2 = check(pos-1);
    ll v3 = check(pos-2);
    ll t1 = _abs(v1-s);
    if( _abs(v2-s) < t1)
        t1 = _abs(v2-s);

    if( _abs(v3-s) < t1)
        t1 = _abs(v3-s);
    cout << t1;
    return 0;
}
