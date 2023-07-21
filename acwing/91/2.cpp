/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 23日 星期五 00:36:45 CST */
#include <bits/stdc++.h>
#include <bitset>
//---> #include "utils.hpp"
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

template<typename T1,typename T2>
void upd_min(T1 & t,const T2& t2){
    if(t > t2)
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
//---> #include "math/bit.hpp"
//二进制操作
//---> #include "base.hpp"

//基础的bit操作

//a的第pos位设为1
template<typename T = int>
T set_at_pos(T a , T pos){
    return a | (1 <<pos);
}

//a的第pos位设为0
template<typename T = int>
T clear_at_pos(T a , T pos){
    return a & ~(1 <<pos);
}

//a的第pos位取反
template<typename T = int>
T toggle_at_pos(T a , T pos){
    return a ^ (1 <<pos);
}

//保留后k位,其它
template<typename T = int>
T keepLast(T a , T k){
    return a & ((1<<k)-1);
}

//第k位的值
template<typename T = int>
T bit_at_pos(T a , T k){
    return (a>>k) & 1;
}


//清除最后一个1
//11,000 & 10,111 = 10,000
template<typename T = int>
T clear_last(T a){
    return a & (a-1);
}


//最低位1 后面有多少个0
template<typename T = int>
T count_bit_trail_zero_buildin(T a){
    if constexpr (std::is_same_v<int, T> || std::is_same_v<T,unsigned int>)
        return __builin_ctz(a);
    else
        return __builin_ctzll(a);
}

//最低位1 后面有多少个0
template<typename T = int>
T count_bit_trail_zero(T a){
    int count = 0;
    for( ; (a & 1) == 0; a>>=1 )
        count++;
    return count;
}


//一共有多少个1
template<typename T = int>
T count_bit_build(T a){
    if constexpr (std::is_same_v<int, T> || std::is_same_v<T,unsigned int>)
        return __builin_popcount(a);
    else
        return __builin_popcountll(a);
}

//一共有多少个1
template<typename T = int>
T count_bit(T a){
    int count = 0;
    for( ; a; a = clear_last(a) )
        count++;
    return count;
}


// 保留最低位的1,其它置0
// 111000 -> 001000
template<typename T>
inline T lowbit(T x) {
    return x & (-x);
}


//表示二进制的类
template<typename T = int>
struct Bit {
    T number;

    Bit(T v = 0)
        : number(v)
    {}

    inline void set(int pos) {
        number = set_at_pos(number, pos);
    }
    inline void reset(int pos) {
        number = clear_at_pos(number, pos);
    }

    inline void clear(int pos){
        number = clear_at_pos(number, pos);
    } 

    operator T() const { return number; }

    T to_number() const { return T(*this);}

    bool is_1(int pos) const {
        return bit_at_pos(number, pos);
    }

    bool is_0(int pos) const {
        return bit_at_pos(number, pos) == 0;
    }

};
using namespace std;
typedef long long ll;

int n,m;
/* 定义全局变量 */

int dis[30][30];
int f[(1<<20)+5][30];
void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            std::cin >> dis[i-1][j-1]; //点的编号从0开始
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    int max_sate = (1<<n) - 1;
    int ans = 0x3f3f3f3f;

    memset(f,0x3f,sizeof(f));
    //边界
    // for(int i = 0 ;i<n;i++){
    //     f[1<<i][i] = 0;
    // }
    f[1][0] = 0;

    for(int i=1;i<=max_sate;++i){
        for(int j=0;j< n;j++) {
            auto bit = Bit(i);

            if( bit.is_0(j) ) continue;

            auto clear_at_j = bit;
            clear_at_j.clear(j);
            //枚举前面的点
            for(int k=0;k<=n-1;++k){
                if(clear_at_j.is_0(k)) continue;
                // upd_min(f[i][j], f[int(clear_at_j)][k] + dis[k][j]);
                if( f[i][j] > f[clear_at_j][k] + dis[k][j]){
                    f[i][j] = f[clear_at_j][k] + dis[k][j];
                    // cout <<"f[" << bitset<5>(i) << "," << j <<"] = " << f[i][j] << "<--" 
                        // << "f[" << bitset<5>(clear_at_j.to_number()) << "," << k << "] : " << f[clear_at_j][k] << " +"
                        // << dis[k][j] << '\n';
                }
                if( i == max_sate)
                    upd_min(ans, f[i][j]);
            }
            // log(i,j,f[i][j]);
        }
    }
    // for(int i=0;i<n;++i){
    //     cout << i << " : " << f[max_sate][i];
    //     std::cout  << "\n";
    // }
    std::cout << f[max_sate][n-1]<< "\n";
    return 0;
}

