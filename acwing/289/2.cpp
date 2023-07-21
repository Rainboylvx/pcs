/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 21日 星期三 11:40:24 CST */
#include <bits/stdc++.h>
// #include "utils/dbg.h"
//---> #include "queue.hpp" //优先队列
//@desc 队列

//---> #include "base.hpp"
/*
 *   rainboyNoip/algorithms, some helpful cpp utils for noi/acm user
 *    Copyright (C) 2020-2021  Rainboy
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
/* 
 * 常用宏
 * */

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
#include <memory_resource>

#ifndef maxn
#define maxn 1000007
#endif

#ifndef maxe
#define maxe 2000007
#endif

template<typename T,std::size_t N = maxn>
struct queue {
    T a[N]; //数据
    unsigned int head{0};
    unsigned int tail{0};

    queue():head{0},tail{0} { }

    inline void init() { head =tail= 0;}

    inline
    void push(const T & v) {
        a[tail++] = v;
    }

    inline
    void push(T && v) {
        a[tail++] = std::move(v);
    }

    inline void pop_front() { ++head;}
    inline void pop_back() { --tail;}

    inline
    T & front() { return a[head]; }

    inline
    T & back() { return a[tail-1]; }

    inline
    std::size_t size() const { return tail - head;}

    inline
    bool empty() const { return head == tail;}

};


template<typename T,std::size_t N = maxn>
struct monotonic_queue : public queue<T, maxn>{
    // using queue<T, N>::empty();
    using Q = queue<T,N>;
    
    //符合条件就删除
    template<typename F>
    inline void remove_front(F f) {
        while( !Q::empty() && f(Q::front()))
            Q::pop_front();
    }

    template<typename F>
    inline void remove_back(F f) {
        while( !Q::empty() && f(Q::back()))
            Q::pop_back();
    }

    template<typename F>
    void push(const T & v, F f) {
        remove_back(f);
        Q::push(v);
    }

    using Q::push;
};
//---> #include "chips/ring2chain.hpp" //拆环成链
//把环转成链,
//主要用于环型DP

//---> #include "base.hpp"

//按点拆成环
//把点复制一遍
template<typename T,std::size_t N = maxn>
struct ring2chain_node{
    T a[maxn];
    int idx;

    ring2chain_node(): idx(0)
    {}

    inline
    void push(const T & v)
    {
        a[++idx] = v;
    }

    inline std::size_t size() const {
        return idx << 1;
    }

    T & operator[](std::size_t i) {
        if( i >= 1 && i <= idx)
            return a[i];
        else
            return a[i-idx];
    }

};
//---> #include "utils.hpp"
//---> #include "base.hpp"


//计算一个数i 前面的第m个数是多少
//包括i本身
inline
int predecessor(int  i,const int & m) {
    return i-m+1;
}

struct AdjacentNumberFinder {
    int m;

    AdjacentNumberFinder(int o)
        :m(o)
    {}

    //i前面第m个数是哪个
    inline
    int forward(int i) const{
        return i-m;
    }

    //i后面第m个数是哪个
    inline
    int backword(int i) const{
        return i+m;
    }

    friend
    int operator < (int i,const AdjacentNumberFinder & adj) {
        return adj.forward(i);
    }

    friend
    int operator > (int i,const AdjacentNumberFinder & adj) {
        return adj.backword(i);
    }
};


template<typename... T>
auto maximum(T&&... args) {
    return std::max({std::forward<T>(args)...});
}

template<typename T1,typename T2>
void upd_max(T1 & t,const T2& t2){
    if(t < t2)
        t = t2;
}

//用最大的那个值更新T1
template<typename T1,typename T2,typename... T3>
void upd_max(T1 & t,const T2& t2, const T3 &... t3) {
    if(t < t2)
        t = t2;
    upd_max(t,t3...);
}


/*
namespace rainboy {

    class Timer {
        public:
            Timer()
            : _start_time{std::clock()},
            _Wall_start{ std::chrono::high_resolution_clock::now() }
            {}
            ~Timer(){
                _end_time = std::clock();
                _Wall_end = std::chrono::high_resolution_clock::now();
                std::cerr << std::fixed << std::setprecision(2) 
                    << fg_blue << bg_green
                    << "CPU time used: "
                    << rst << fg_red << blink << blod
                    << 1000.0 * (_end_time - _start_time) / CLOCKS_PER_SEC << " ms\n"
                    << rst << fg_blue << bg_green
                    << "Wall clock time passed: "
                    << rst << fg_red << blink << blod
                    << std::chrono::duration<double, std::milli>(_Wall_end - _Wall_start).count()
                    << " ms\n"
                    << rst;
            }
        private:
            std::clock_t _start_time,_end_time;
            std::chrono::time_point<std::chrono::high_resolution_clock> _Wall_start,_Wall_end;
    };


#if __cplusplus >= 201703L

inline void log_barrier(){
    std::cout << "\n----------------------------\n\n";
}

template <typename... _Args>
void log(_Args&&... args){
    ( (std::cout << args << " "),...);
    std::cout << '\n';
}

//输出类型名 type_name<int&>() -> "int&"
template <class T>
constexpr
std::string_view
type_name()
{
using namespace std;
#ifdef __clang__
    string_view p = __PRETTY_FUNCTION__;
    return string_view(p.data() + 34, p.size() - 34 - 1);
#elif defined(__GNUC__)
    string_view p = __PRETTY_FUNCTION__;
#  if __cplusplus < 201402
    return string_view(p.data() + 36, p.size() - 36 - 1);
#  else
    return string_view(p.data() + 49, p.find(';', 49) - 49);
#  endif
#elif defined(_MSC_VER)
    string_view p = __FUNCSIG__;
    return string_view(p.data() + 84, p.size() - 84 - 7);
#endif
}

#endif
} //namespace rainboy
*/
using namespace std;

using ll = long long;
int n,m;
/* 定义全局变量 */

ring2chain_node<ll> ring;

struct node {
    int p;ll v; //位置,值
};
monotonic_queue<node> mque; //单调队列

void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        ll t;
        std::cin >> t;
        ring.push(t);
    }
}


int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();

    AdjacentNumberFinder adj_n(n/2);
    mque.push({1,ring[1]-1});
    ll ans = 0;
    for(int i = 2;i <= ring.size();i++) {
        int v = ring[i]; //这个位置的数字
        
        int pos =  i < adj_n; //向左移动
        mque.remove_front([&pos](auto & _node){
            return _node.p < pos;
        });

        ll new_v = v + i + mque.front().v;
        // dbg(i,new_v);
        // tdbg(mque.front().v,i,new_v);
        upd_max(ans,new_v);

        // mque.push(, F f)
        mque.push({i,v-i},[t = v-i](auto & x){ return x.v < t; });
    }

    std::cout << ans << '\n' ;
    return 0;
}

