/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 10:26:43 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int k = 0;

int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    for( ;n != 0; ){
        k++;
        int g = n % 10;
        if( k == m)
            printf("%d",g);
        n /= 10;
    }
    return 0;
}
