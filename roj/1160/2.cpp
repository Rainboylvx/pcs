/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 10:00:45 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

void dfs(int a){
    if( a == 0) return ;
    printf("%d", a % 10);
    dfs(a / 10);
}

int main(){
    scanf("%d",&n);
    dfs(n);
    return 0;
}
