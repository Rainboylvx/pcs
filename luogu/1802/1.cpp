/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 05日 星期三 17:43:03 CST */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n,x;
ll f[1005];
ll lose[1005],win[1005],use[1005];


int main(){
    cin >> n >> x;
    ll i,j;
    for(i=1;i<=n;++i){
        cin >> lose[i] >> win[i] >> use[i];
    }
    for(i=1;i<=n;i++){
        for(j=x;j>=use[i];j--)
            f[j] = max(f[j]+lose[i],f[j-use[i]]+win[i]);
        for(j=0;j<use[i];j++)
            f[j] += lose[i];
    }
    cout << f[x]*ll(5) << endl;

    return 0;
}
