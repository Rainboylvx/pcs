/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 09:52:06 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

int main(){
    scanf("%d",&n);
    for( ; n !=0 ; ){
        int g = n % 10;
        printf("%d",g);
        n = n /10;
    }
    return 0;
}
