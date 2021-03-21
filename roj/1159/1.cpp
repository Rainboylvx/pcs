// f(i) = f(i-1) + f(i-2)
/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 09:31:47 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

int f(int a){
    if( a == 1) return 0;
    if( a == 2) return 1;
    return f(a-1) + f(a-2);
}

int main(){
    scanf("%d",&n);
    int ans = f(n);
    printf("%d",ans);
    return 0;
}
