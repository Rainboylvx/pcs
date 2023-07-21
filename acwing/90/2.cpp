/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 22日 星期四 13:14:20 CST */
#include <bits/stdc++.h>
//---> #include "math/quickpow.hpp"
#include <iostream>
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

//快速乘 取模
template<typename T = long long>
T quick_mul(T a , T b, T mod)
{
    if( a == 0 || b == 0) {
        return 0;
    }
    else if( a == 1 || b == 1) {
        return (a*b) % mod;
    }

    T base = b;
    T ans = 0;
    for(; a ;a >>=1 ) {
        if( a & 1) {
            ans = (ans + base) % mod;
        }
        base <<=1; //base * 2, 2^0, 2^1,2^2 ,....
        base %= mod;
    }
    return ans % mod;
}
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

ll a,b,p;
int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    std::cin >> a >> b >> p;
    std::cout << quick_mul(a,b,p) % p << "\n";
    // ll ans = (__int128)a*b % p;
    // std::cout << ans << "\n";
    
    return 0;
}

