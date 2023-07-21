#include <iostream>
#include "data_structure/stack.hpp"
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
