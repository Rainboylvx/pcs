/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 22日 星期四 11:52:10 CST */
#include <bits/stdc++.h>
//---> #include "math/quickpow.hpp"
//快速幂取模

template<typename T = long long>
T quick_pow(T a , T b, T mod)
{
    T &base = a;
    T ans = 1;
    if( b == 0) {
        return 1 % mod;
    }
    for( ;b; b >>=1)
    {
        if( b & 1) 
            ans = ans * base % mod; //是1就乘
        base = base * base % mod; // base增增
    }
    return ans % mod;
}
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

ll n,m;
/* 定义全局变量 */

ll p;
void init()
{
    cin >> n >> m >> p;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    std::cout << quick_pow(n,m,p) << "\n";
    return 0;
}

