#include <iostream>
//---> #include "data_structure/stack.hpp"
//@desc 栈

//---> #include "data_structure/dynamic_array.hpp"
//一个只能用于末尾增减的array,取代vector
// 使用方法
// 定义 dynamic_array<int,100> myarr;
// 末尾加入           myarr.push(a)
// 得到末尾的元素引用 myarr.back()
// 得到末尾的元素引用 myarr.top()
// 得到删除最后一个元素 myarr.pop()
// 使用下标操作  myarr[i],最小下标1
// 元素个数  myarr.size();
// 范围指针 begin() end()
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


template<typename T=int,std::size_t N=maxn>
struct dynamic_array {
    T a[maxn];
    int idx;

    using value_type = T;
    using iterator = T *;

    dynamic_array() :idx{0} {}

    inline void clear() { idx = 0; }

    void push(const T& v) {
        a[++idx] = v;
    }

    inline
    T & back() {
        return a[idx];
    }

    inline
    T & top() {
        return back();
    }

    inline
    void pop() {
        --idx;
    }

    std::size_t size() const { return idx;}

    T * begin() {
        return &a[1];
    }

    T * end() {
        return &a[idx+1];
    }
    const T * begin() const {
        return &a[1];
    }

    const T * end() const {
        return &a[idx+1];
    }


    T & operator[](std::size_t id) {
        return a[id];
    }
};


#ifdef  __FAST_OUT_
template<typename T>
fast_out & operator<<(fast_out & out ,dynamic_array<T> & da) {
    out.println(da.begin(), da.end());
    return out;
}
#endif

template<typename T=int,std::size_t N=maxn>
using stack = dynamic_array<T, N>;



// 单调栈,TODO
// 通常 T = {int idx,val;} 包含位置与值的信息
template<typename T,std::size_t N = maxn>
struct monotonic_stack: public stack<T, maxn>{

    // 添加元素,
    template<typename F>
    void push(T a,F && f);


    // 取顶部元素,符合f条件的全部删除
    template<typename F>
    void top(F&& f);

};
using ll = long long;
struct node1 {
    int s,val; //s前缀和,val 当前元素的和
};

stack<node1> sta1;
stack<ll> sta_max;//前缀最大值
stack<int> sta2;
int n;
char opt;
int val;


int main(){
    std::cin >> n;
    while ( n-- ) {
        std::cin >> opt;

        if( opt == 'I') {
            std::cin >> val;
            int v = val;
            if( sta1.size() == 0) {
                sta1.push({v,v});
                sta_max.push(v);
            }
            else {
                int s = sta1.top().s + v;
                sta1.push({s,v});
                int pre_max = sta_max.top();
                sta_max.push( std::max(pre_max,s) );
            }
        }
        else if(opt == 'D')
        {
            if( sta1.size() == 0) continue;
            sta1.pop();
            sta_max.pop();
        }
        else if (opt == 'L')
        {
            if( sta1.size() == 0) continue;
            int v = sta1.top().val;
            sta1.pop();
            sta_max.pop();
            sta2.push(v);
        }
        else if( opt == 'R')
        {
            if( sta2.size() == 0) continue;
            int v = sta2.top();
            sta2.pop();
            if( sta1.size() == 0) {
                sta1.push({v,v});
                sta_max.push(v);
            }
            else {
                int s = sta1.top().s + v;
                sta1.push({s,v});
                int pre_max = sta_max.top();
                sta_max.push( std::max(pre_max,s) );
            }
        }
        else if( opt == 'Q') {
            std::cin >> val;
            std::cout << sta_max[val] <<"\n";
        }

        //debug
        // std::cout << "opt " << opt << "\n";
        // for( auto x : sta1) {
        //     std::cout << x.s  << " " << x.val << " ,";
        // }
        // std::cout << "\n";

    }
    return 0;
}

