/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-21 20:25:25
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
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
template<typename T,std::size_t N = maxn>
struct queue {
    T a[N]; //数据
    unsigned int head{0};
    unsigned int tail{0};
    void clear() { head = tail = 0;}
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
    template<typename... Args>
    inline void emplace_back(Args&&... args) {
        a[tail++] = {std::forward<Args>(args)...};
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
    using Q = queue<T,N>;
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
#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp" 
#endif
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)
int n,m,root;
int que_idx[maxn]; //每个人对应的队列的编号
queue<int> queque; //队列的队列,按顺序,记录每个队伍的编号
bool in_queue[maxn]; // 队伍i是否在 queque 中
queue<int,1001> que[1001]; //每个队伍
char str[20];
void init() {
    memset(in_queue,0,sizeof(in_queue));
    scanf("%d",&n);
    F(n){
        scanf("%d",&m);
        FF( j , m ){
            int t;
            scanf("%d",&t);
            que_idx[t] = i;
        }
    }
    F(1000){
        que[i].clear();
    }
    queque.clear();
}
int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    int idx =0;
    while(1) {
        init();
        if(n == 0 ) break;
        printf("Scenario #%d\n",++idx);
        while(1){
            scanf("%s",str);
            if(str[0] == 'E')
            {
                int t;
                scanf("%d",&t);
                if( !in_queue[que_idx[t]] ){
                    queque.push(que_idx[t]);
                    in_queue[que_idx[t]] = 1;
                }
                que[que_idx[t]].push(t);
            }
            else if(str[0] == 'D')
            {
                int h = queque.front();
                int t = que[h].front();
                que[h].pop_front();
                if( que[h].empty()) {
                    queque.pop_front();
                    in_queue[h] = 0;
                }
                printf("%d\n",t);
            }
            else if (str[0] == 'S')
                break;
        }
        printf("\n");
    }
    return 0;
}
