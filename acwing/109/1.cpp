/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 04日 星期二 08:31:10 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

ll n,m,t;
ll k;
ll a[maxn];
ll b[maxn];
/* 定义全局变量 */


//需要计算2^x <= n的x
template<ll N>
struct fake_log2 {
    ll a[N]; // a[i] 表示 2^x <= i 的最大x
    constexpr fake_log2() {
        a[1] = 0;
        for(ll i =2;i<=N;i++) {
            if(i == (1<< (a[i-1]+1)))
                i = a[i-1]+1;
            else
                i = a[i-1];
        }
    }
    constexpr ll operator()(int n) {
        return a[n];
    }
};


//求最接近 n的 2^i
//也就是最高位1的位置
constexpr inline ll floor_log(int n) {
    return std::__lg(n);
}

//前2^j 位置,不包括自己
inline ll pre_pos(int i,int j) {
    return i - (1<<j);
}

template<template <std::size_t> typename T, ll N>
constexpr std::size_t extract(const T<N>&) { return N; }

//CRTP,Curiously Recurring Template Pattern
template<template<std::size_t> class _Child,std::size_t N = maxn>
struct multi_double {
    using Child = _Child<N>;
    friend Child;

    fake_log2<N> * log2 = nullptr;
    static constexpr ll max_log = floor_log(N);

    ll f[N][max_log+1];

    //得到点f[i][j]的信息
    //合并点i的2^j的信息为
    inline ll get(int i,int j) {
        return static_cast<Child*>(this)->merge_impl(f[i][j-1],f[i+(1<<(j-1))][j-1]);
    }

    inline void __init() {
        for(ll j = 1;j<=max_log;j++) //枚举2^j
        {
            for(ll i=0;i<=pre_pos(N,j);i++) {//枚举起点,是不是从0点开始比较好
                f[i][j] = get(i,j);
            }
        }
    }
    
    //初始化信息
    void init(){
        //init0,初始化f[i][0]的信息
        // static_cast<Child*>(this)->init0();
        for(ll i =0;i<N;i++) // < N ,因为N后面没有元素了
            f[i][0] = static_cast<Child*>(this)->get0(i);
        __init();
    }

    //从i点开始跳跃,得到停下来的点
    ll jump(int i) {
        for(ll j = max_log;j>=0;j--)
        {
            if( !static_cast<Child*>(this)->limit_jump(i,i+2^j) )
                i += 2^j;
        }
        return i;
    }
};

//求了b的校验和
ll check_sum(int len) {
    ll l =1 , r = len;
    ll sum = 0;
    ll cnt = 0;
    while( l < r && cnt < m) {
        ll x = (b[l]-b[r]) *(b[l]-b[r]);
        sum += x;
        cnt++;
        l++;r--;
    }
    return sum ;
}


//计算从i开始,到达的右端点是哪里
ll calc(int st) {
    ll max_log = std::__lg(n);
    //在这个题目里左端点不能变
    ll pos = st;
    ll pre = st;
    int i = 0;
    for( ; i<=max_log;i++) { //先小步的跑
        ll end = pre + (1<<i)-1;
        if( end > n ) continue;
        ll idx = 0;
        for(ll j = st ; j<= end;j++)
            b[++idx] =  a[j];
        std::sort(b+1,b+1+idx); //排序
        ll sum = check_sum(idx);
        if(  sum > t) break;
        else {
            pre = end+1;
            pos = end;
        }

    }
    
    for( ;i >=0 ;i--) {
        ll end = pre + (1<<i)-1;
        if( end > n ) continue;
        ll idx = 0;
        for(ll j = st ; j<= end;j++)
            b[++idx] =  a[j];
        std::sort(b+1,b+1+idx); //排序
        ll sum = check_sum(idx);
        if(  sum > t) continue;
        else {
            pre = end+1;
            pos = end;
        }
    }
    return pos;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
     
    std::cin >> k;
    while ( k-- ) {
        std::cin >> n >> m >> t;
        for(ll i=1;i<=n;++i){
            std::cin >> a[i];
        }
        ll cnt = 0;
        ll pos ;
        ll pre = 1;
        do {
            pos = calc(pre);
            pre = pos+1;
            cnt++;
        } while( pos != n);
        std::cout << cnt << "\n";
    }
    return 0;
}
