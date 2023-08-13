/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-21 19:01:20
*----------------*/
#define maxn 1000005
#define maxe 2000005
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
    return num+5;
}
#ifdef __maxn__
const int maxn = _sexp_to_number(__M_concat_sv(__maxn__));
#elif not defined (maxn)
const int maxn = 1000007;
#endif
#ifdef __maxe__
const int maxe = _sexp_to_number(__M_concat_sv(__maxe__));
#elif not defined (maxe)
const int maxe = 1000007;
#endif
#ifndef FOR
#define FOR(i, range) \
    for (auto i : range)
#else
    static_assert(0,"Macro FOR already defined!");
#endif
#ifndef __HEADER_BASE_HPP__
#include <cstring>
#endif
template<std::size_t N = maxn>
struct KMP {
    char * s; //s串
    char * a; //a串,s串中a串的匹配
    int len_s{-1};
    int len_a{-1};
    int next[maxn]; //a串的next
    KMP() = default;
    KMP(char * s,char *a)
        :s(--s),a(--a)
    {}
    void set_s( char * _s) { s = _s;}
    void set_a( char * _a) { a = _a;}
    void init() {
        if( len_s == -1) len_s = strlen(s+1);
        if( len_a == -1) len_a = strlen(a+1);
        calc_a_next(); // 求a串自己的匹配
    }
    void calc_a_next() {
        int pre = next[1] = 0; // pre 上一个元素(i-1) 匹配的长度
        for(int i = 2;i<=len_a;++i) {
            while( pre > 0 && a[i] != a[pre+1] )
                pre = next[pre]; //不停的回退
            if( a[i] == a[pre+1]) pre++; // 停止后的检查
            next[i] = pre;
        }
    }
    inline char at_s(int i) const { return s[i]; }
    inline char at_a(int i) const { return a[i]; }
    template<typename F>
    void work(char * _s,char * _a,F && f) {
        s = _s;
        a = _a;
        work(std::forward<F>(f));
    }
    template<typename F>
    void work(F && f) {
        init(); //初始化
        int pre = 0;
        for(int i =1;i<=len_s;++i)
        {
            while(pre >0 && ( pre == len_a || s[i] != a[pre+1]))
                pre = next[pre];
            if( s[i] == a[pre+1]) pre++;
            if(pre == len_a) { //匹配成功,调用位置
                f(i);
            }
        }
    }
};
using namespace std;
typedef long long ll;
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)
#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif
int n,m;
char a[maxn]; //常用的一个数组
int init()
{
    scanf("%d",&n);
    if( n > 0) scanf("%s",a+1);
    return n;
}
KMP mykmp;
int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    int idx = 0;
    while( init()) {
        mykmp.set_a(a);
        mykmp.len_a = strlen(a+1);
        mykmp.calc_a_next();
        printf("Test case #%d\n",++idx);
        F3( i , 2 , n){
            if( mykmp.next[i] != 0 && i % ( i - mykmp.next[i]) == 0)
            {
                printf("%d %d\n",i,i / (i-mykmp.next[i]));
            }
        }
        printf("\n");
    }
    return 0;
}
