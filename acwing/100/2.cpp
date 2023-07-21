/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 05日 星期三 15:29:44 CST */
#include <bits/stdc++.h>
//---> #include "data_structure/sub_array.hpp"
//差分数组 用于: 多次区间增减,一次查询单点
//区间修改 转成 点修改
// 使用方法
// push(t) 不停的一个一个加入数据
// range_add(l,r,add) 区间加
// for(auto v : sub_array ){ } 遍历前缀和
//
//---> #include "base/macro.hpp"
//一些常用的宏定义

#include <cstddef> // for std::size_t

#ifndef maxn
#define maxn 1000007
#endif

#ifndef maxe
#define maxe 2000007
#endif

#ifndef FOR
#define FOR(i, range) \
    for (auto i : range)
#else
    static_assert(0,"Macro FOR already defined!");
#endif



template<typename T = int , std::size_t N = maxn>
struct sub_array {
    int a[maxn];
    int cnt = 0;
    int pre=0; //前一个元素

    sub_array()
        : cnt(0),pre(0)
    {}

    void clear() {
        pre = cnt = 0;
    }

    int size() const { return cnt; }

    void push(int v) {
        a[++cnt] = v-pre;
        pre = v;
    }

    void range_add(int l,int r,int add) {
        if( l > r) return;
        a[l] += add;
        a[r+1] -= add;
    }

    T query(int r) {
        T sum = 0;
        for(int i=1;i<=r;++i){
            sum += a[i];
        }
        return sum;
    }

    //TODO,遍历前缀和
    auto begin() { return &a[1];}
    auto end()  { return &a[1+size()];}

};
using namespace std;
typedef long long ll;

sub_array<ll> mysub;
int n,m;
/* 定义全局变量 */

void init()
{

}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    std::cin >> n;

    mysub.clear();
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        mysub.push(t);
    }

    ll sum_neg = 0,sum = 0;
    auto i = mysub.begin();
    ++i;
    for( ;i != mysub.end(); ++i) {
        if( *i < 0)
            sum_neg += -*i;
        else
            sum += *i;
    }

    auto abs = [](ll a) {
        if( a< 0) return -a;
        return a;
    };

    std::cout << 
        std::min(sum_neg,sum)
        + abs(sum_neg-sum)
        << "\n";
    std::cout << abs(sum_neg-sum) +1 << "\n";
    return 0;
}

