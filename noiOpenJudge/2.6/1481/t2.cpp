/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 07月 30日 星期五 15:55:32 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
int a[maxn];
int f[maxn];
int main(){
    int T;
    scanf("%d",&T);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)  scanf("%d",&a[i]);
    f[1] = a[1];
    int ans = f[1];
    for(int i=2;i<=n;++i){
        if( f[i-1] >0){
            f[i] = f[i-1] + a[i];
            ans = max(ans,f[i]);
        }
        else f[i] = a[i];
    }
    printf("%d",ans)g

    return 0;
}
