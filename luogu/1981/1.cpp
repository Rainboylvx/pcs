/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 03日 星期一 21:26:59 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
const int mod = 10000;
string s;
ll a[100005];
ll pos[100005];
int cnta,cntp;

int main(){
    cin >> s;
    int i;
    ll t = 0;
    for(i=0;i<s.length();i++){ //分割
        if( s[i] == '*'){
            a[++cnta] = t;
            t = 0;
            pos[++cntp] = cnta+1; // 第cnta+1个数字前面的*
        }
        else if( s[i] == '+'){
            a[++cnta] = t;
            t = 0;
        }
        else {
            t = t*10 + (s[i] - '0');
        }
    }
    a[++cnta] = t;
    for( i =1;i<=cntp;i++){
        a[pos[i]] *= a[pos[i]-1];
        a[pos[i]] %= mod;
        a[pos[i]-1] = 0;
    }
    ll sum = 0;
    for( i =1;i<=cnta;i++){
        sum += a[i];
        sum %= mod;
    }
    cout << sum%mod;

    return 0;
}
