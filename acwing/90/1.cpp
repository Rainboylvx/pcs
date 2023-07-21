/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 22日 星期四 13:14:20 CST */
#include <bits/stdc++.h>
#include "math/quickpow.hpp"
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
