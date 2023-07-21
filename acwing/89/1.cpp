/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 22日 星期四 11:52:10 CST */
#include <bits/stdc++.h>
#include "math/quickpow.hpp"
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
