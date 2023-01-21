/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 24日 星期五 15:02:21 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
ll n,m;

void init(){
    scanf("%lld",&n);
    ll ans = 0;
    ll i,j;
    for(i=1;i<=n;i++ ){
        int k = 0;
        for(j=1;j<=n;j++ ){
            if( i % j == 0 ) k++;
            else if( j % 2 == 0 || j % 5 == 0) k++;
        }
        ans +=k;
        printf("%lld %lld\n",i,k);
    }
    printf("%lld\n",ans);
}

int main(){
    init();

    return 0;
}
