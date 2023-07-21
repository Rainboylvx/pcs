//---> #include "algo/discrete.hpp"
/**
 * 离散化 discretization 
 * TODO 是否不使用stl的函数
 *  - unique
 *  - lower_bound
 *
 */
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
#include <string_view>
#include <memory_resource>

#ifndef maxn
#define maxn 1000007
#endif

#ifndef maxe
#define maxe 2000007
#endif

template<std::size_t N = maxn>
struct discrete {
    int a[maxn];
    int idx{0};
    int * last_unique_ptr = nullptr; //最后一个位置

    void init() {
        idx = 0;
        last_unique_ptr = nullptr;
    }

    void push(int v) {
        a[++idx] = v;
    }

    int unique_size () const {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use unique_size()");
#endif
        return last_unique_ptr - (a+1);
    }

    //对存入的值进行离散化
    void decrete() {
        std::sort(a+1,a+1+idx);
        last_unique_ptr= std::unique(a+1,a+1+idx);
    }


#if 0
    //对数据arr,从1到n进行离散化
    template<std::size_t size>
    void pre_work(int arr[size],int n) {
        pre_work(a+1, a+1+n);
    }

    template<typename Iter>
        requires std::is_same_v<typename std::iterator_traits<Iter>::value_type, int>
    void pre_work(Iter begin ,Iter end) {
        std::sort(begin,end); //从小到大排序
        for( ; begin != end; ++begin)
            a[++idx] = *begin;
    }
#endif
    //查询x对应的值是
    int query(int x) {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use query(x)");
#endif
        
        //找到第一个>=x的位置
        auto pos = std::lower_bound(a+1, last_unique_ptr,x) - a;
        if( a[pos] == x)
            return pos;
        else 
            return 0; //返回0 表示没有找到
    }

    int operator[](int x) {
        return query(x);
    }

    int * begin() {
        return a+1;
    }

    int * end() {
#ifdef DEBUG
        if(last_unique_ptr == nullptr)
            throw std::runtime_error("must call discrete(),before use end()");
#endif
        return last_unique_ptr;
    }


};

discrete mydiscrete;

//创建一个桶
int bucket[maxn];
int a[maxn]; //原来每个人爱好的语言
int b1[maxn],b2[maxn]; //每个电影使用的编号

int main(){
    int n,m;
    std::cin >> n;
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        mydiscrete.push(t);
        a[i] = t;
    }
    mydiscrete.decrete(); //对每个语言进行离散化

    for (int i =1;i <=n;i++) {
        //统计每个语言 被喜欢的次数
        bucket[mydiscrete[ a[i] ]]++;
    }

    std::cin >> m;

    int _max1 = -1,_max2= -1; //记录很开心,开心的人数

    for(int i=1;i<=m;++i){
        std::cin >> b1[i];
    }
    for(int i=1;i<=m;++i){
        std::cin >> b2[i];
    }
    int ans;
    for(int i=1;i<=m;++i){
        int x = b1[i];
        int y = b2[i];
        int q1 = mydiscrete[x]; //得到离散化后的值
        int q2 = mydiscrete[y];
        if( _max1 < bucket[q1]) {
            _max1 = bucket[q1];
            _max2 = bucket[q2];
            ans = i;
        }
        else if ( _max1 == bucket[q1] && _max2 < bucket[q2]) {
            _max1 = bucket[q1];
            _max2 = bucket[q2];
            ans = i;
        }
    }

    std::cout << ans << "\n";

    return 0;
}

