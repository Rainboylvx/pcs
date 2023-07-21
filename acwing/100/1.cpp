/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 05日 星期三 15:29:44 CST */
#include <bits/stdc++.h>
#include "data_structure/sub_array.hpp"
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
