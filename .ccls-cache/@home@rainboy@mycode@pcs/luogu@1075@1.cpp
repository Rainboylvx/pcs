/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 03日 星期一 22:11:04 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
long long n;

int main(){
    cin >> n;
    ll i;
    for( i =2;i<=sqrt(n)+1;i++){
        if( n % i == 0){
            ll ans = n / i;
            cout << ans;
            return 0;
        }
    }
    return 0;
}
