/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 12月 10日 星期六 08:55:06 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int main(int argc,char * argv[]){
    ll a,b;
    std::cin >> a >> b;
    if( b == 1 ){
        std::cout << a ;
        return 0;
    }
    ll ans = 1;
    for(int i=1;i<=b;++i){
        ans = ans * a;
        if( ans > 1000000000)
        {
            std::cout << -1 ;
            return 0;
        }
        // std::cout << i <<" "<< ans << std::endl;
    }
    std::cout << ans << std::endl;

    return 0;
}
