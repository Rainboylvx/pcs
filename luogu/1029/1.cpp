/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 10日 星期一 16:25:21 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
long long x,y;
/* 定义全局变量 */

void init()
{
    std::cin >> x >> y;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();

    ll mul = x * y;
    ll ans = 0;
    m = max(x,y); ///不可能超过两都的最大值
    for(ll p =1;p<=m;p++){
        if( mul % p == 0) {
            ll q = mul / p;
            if( std::gcd(p,q) == x) {
                // if( std::lcm(p,q) == y) //这个好像可以不加
                    //因 p*q = lcm(p,q) * gcd(p,q)
                    ans++;
            }
        }
    }
    std::cout << ans << "\n";

    return 0;
}
