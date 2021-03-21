/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 09:05:38 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
// f(5) = 5+f(4)
// f(1) = 1
int f(int a){
    if( a == 1 ) return 1;
    return a+f(a-1);
}

int main(){
    scanf("%d",&n);
    int ans = f(n);
    printf("%d",ans);
    return 0;
}
