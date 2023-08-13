/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 29日 星期六 08:35:24 CST */
#include <bits/stdc++.h>
#include <cstddef> // for std::size_t
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <tuple>
#include <string_view>
#include <functional>
#include <memory_resource>
#ifdef __cpp_lib_ranges
#include <ranges>
#endif
#ifdef __cpp_concepts
#include <concepts>
#endif
using std::literals::string_view_literals::operator""sv;
#define __M_concat_II(a,b) a##b
#define __M_concat_I(a,b) __M_concat_II(#a,b)
#define __M_concat_sv(a) __M_concat_I(a,sv)
constexpr int _sexp_to_number(std::string_view _sv){
    int num = 0,e = 0,i=0;
    while( i < _sv.length() && _sv[i] !='e')
        num = num*10 + _sv[i] - '0',++i;
    ++i;
    while( i < _sv.length() )
        e = e*10 + _sv[i]-'0',++i;
    while(e--) num = num*10;
    return num;
}
constexpr int add_five(int number) {
    return number + 5;
}
long long operator ""_Number(const char * str,std::size_t N){
    return _sexp_to_number(std::string_view(str,N));
}
struct __INF {
    template<typename T>
    constexpr operator T() const {
        return std::numeric_limits<T>::max();
    }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
struct __NINF {
    template<typename T>
    constexpr operator T() const {
        return std::numeric_limits<T>::lowest();
    }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
constexpr auto NINF = __NINF();
constexpr auto INF  = __INF();
struct __inf {
    constexpr operator unsigned long long() const { return 0x3f3f3f3f3f3f3f3f; }
    constexpr operator long long() const  { return 0x3f3f3f3f3f3f3f3f; }
    constexpr operator unsigned int() const { return 0x3f3f3f3f; }
    constexpr operator int() const { return 0x3f3f3f3f; }
    constexpr operator char() const { return 0x3f; }
    constexpr operator unsigned char() const { return 0x3f; }
    template<typename T>
    constexpr bool operator==(const T oth) const
    {
        return T(*this) == oth;
    }
};
constexpr auto inf = __inf();
#ifdef __maxn__
const int maxn = add_five(_sexp_to_number(__M_concat_sv(__maxn__)));
#elif not defined (maxn)
const int maxn = 1000007;
#endif
#ifdef __maxe__
const int maxe = add_five(_sexp_to_number(__M_concat_sv(__maxe__)));
#elif not defined (maxe)
const int maxe = 1000007;
#endif
#ifndef FOR
#define FOR(i, range) \
    for (auto i : range)
#else
    static_assert(0,"Macro FOR already defined!");
#endif
namespace binary_index_tree {
    int lowbit(int a) { return a & -a; } //每个元素的管辖范围
    inline int fa(int a) { return  a + lowbit(a);} //求a的父亲的坐标
    inline int left(int a) { return a - lowbit(a);} //a管辖范围左边的相邻的点
} // end namespace binary_index_tree
template<std::size_t N =maxn>
struct bit_range_max {
    using ll = long long;
    ll a[N]; //原数组
    ll c[N];
    int size_{0};
    void clear() { size_ = 0;}
    int size() const { return size_;}
    void push_back(ll val){
        size_++;
        c[size_] = a[size_] = val;
        update_by_child(size_);
    }
    template<typename... Args>
    void push_back(ll val ,Args... args){
        push_back(val);
        push_back(args...);
    }
    inline bool update_by_child(int pos) {
        c[pos] = a[pos]; // 先等于自己的直接点
        ll lb = binary_index_tree::lowbit(pos);
        bool update_flag = 0;
        for(int i = 1; i < lb; i<<=1)
            if( c[pos] < c[pos - i] )
                c[pos] = c[pos - i],update_flag = 1;
        return update_flag;
    }
    void update(int pos, ll val) {
        a[pos] = val;
        update_by_child(pos);
        using binary_index_tree::fa;
        for( pos = fa(pos); pos <= size_; pos = fa(pos))
        {
            if( !update_by_child(pos))
                ;
        }
    }
    int max(int l,int r) {
        ll res = -1;
        while( l <= r) {
            int nl = binary_index_tree::left(r)+1;
            if( nl >=l) {
                if( res < c[r]) res = c[r];
                r = nl-1; //下一个求解区间
            }
            else { // nl < l
                if( res < a[r]) res = a[r];
                r--;
            }
        }
        return res;
    }
    int max_pos(int x,int y) {
        if( x > y) return -1; //-1 表示不可能的位置
        ll res = -1;
        int pos = y;
        while( x <= y) {
            int nx = binary_index_tree::left(y)+1;
            if( nx >=x) {
                if( res < c[y]) res = c[y],pos=y;
                y = nx-1; //下一个求解区间
            }
            else { // nx < x
                if( res < a[y]) res = a[y],pos=y;
                y--;
            }
        }
        int lb = binary_index_tree::lowbit(pos);
        while(  lb != 1) { //说明有孩子
            int tpos=pos;
            if( a[pos] == res) break;// 从0开始先从自己比较,这样可以避免错误
            for(int i =1 ;i< lb ;i <<= 1) { 
                if( pos - i < x) continue;//应该在[x,y]之间
                if(c[pos - i] == res){ // 如果为最大值
                    tpos = pos-i; //最大值的位置
                }
            }
            if( pos == tpos ) break; //没有被孩子更改,那pos位置就是最大的
            pos = tpos;
            lb = binary_index_tree::lowbit(pos);
        }
        return pos;
    }
};
using namespace std;
typedef long long ll;
int n,m;
ll s[maxn];
ll a[maxn];
bit_range_max bit1,bit2;
void init()
{
    cin >> n;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> s[i];
    }
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> a[i];
        bit1.push_back(a[i]);
    }
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        bit2.push_back( 2*s[i] + a[i]);
    }
}
int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int last;
    ll ans = 0;
    int pos = bit2.max_pos(1,n);
    last = pos;
    ans += bit2.a[pos];
    bit1.update(pos,0);
    cout << ans << "\n";
    for(int i = 2;i <= n ;++i ) // i: 2->n
    {
        ll pre = 0; //从前面找的最大值
        ll suf = 0; //从后面找的最大值
        int pre_pos = -1;
        int suff_pos = -1;
        if( last > 1) { //有前面的位置
            pre_pos = bit1.max_pos(1,last-1);
            pre = bit1.a[pre_pos]; //前面的最大值
        }
        if( last < n) { //有后面的位置
            suff_pos = bit2.max_pos(last+1,n);
            suf = bit2.a[suff_pos];
        }
        if( ans + pre > ans - 2*s[last] + suf) { //选前面的值
            ans += pre;
            bit1.update(pre_pos,0); //这个位置改成0
        }
        else { //选后面的值
            ans -= 2*s[last];
            ans += suf;
            last = suff_pos;
            bit2.update(suff_pos,0); //把这个位置改成0
            bit1.update(suff_pos,0); //这个位置改成0
        }
        cout << ans << "\n";
    }
    return 0;
}
