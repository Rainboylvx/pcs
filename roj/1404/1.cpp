/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 07日 星期日 09:32:42 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;


int main(){
    scanf("%d",&n);
    ll sum = 0;
    for(ll i=1;1;++i){
        //printf("%d\n",i);
        sum += i;
        ll t = sum - n;

        if( i==65536){
            printf("%lld\n",sum);
            printf("%lld\n",t);
            printf("%lld\n",t%3);
            printf("%lld\n",t/3);
            break;
        }
        if( t <=0 || t % 3 != 0 ) continue;
        if( t / 3 <= i){
            printf("%lld %lld",t/3,i);
            break;
        }
    }
    return 0;
}
