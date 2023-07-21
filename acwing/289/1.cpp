/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 21日 星期三 11:40:24 CST */
#include <bits/stdc++.h>
// #include "utils/dbg.h"
#include "queue.hpp" //优先队列
#include "chips/ring2chain.hpp" //拆环成链
#include "utils.hpp"
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
