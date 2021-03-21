/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 18日 星期四 14:59:34 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int f[101][11]; // 
// f[0][?] = 0
// f[n][1] = n

int egg(int n,int m){
    if( n == 0) return 0;
    if( m == 1) return n;
    if( f[n][m] != -1)
        return f[n][m];

    int ans = 0x7f7f7f7f;
    for(int i=1;i<=n;i++){
        int t = max( egg(i-1,m-1)+1, egg(n-i,m)+1);
        ans = min(ans,t);

    }
    f[n][m] = ans;
    return ans;
}

int main(){
    memset(f,-1,sizeof(f));
    while ( scanf("%d%d",&n,&m) !=EOF) {
        printf("%d\n",egg(n,m));
    }
    return 0;
}
