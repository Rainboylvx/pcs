/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 08月 01日 星期二 16:33:21 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
int a[maxn];
bool f[maxn];
int ans = 0;
void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        std::cin >> a[i];
    }
    std::sort(a+1,a+1+n);
    memset(f,0,sizeof(f));
    f[0]=1;
    ans = 0;
}

void full_backpack (){
    for(int i=1;i<=n;++i){
        int v = a[i];
        if( f[v] == 1) {
            continue;
        }
        ans++;
        // 进行完全背包 恰好装满
        for(int j = v;j<=25000;j++) {
            f[j] = f[j] || f[j-v];
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T;
    std::cin >> T;
    while ( T-- ) {
        init();
        full_backpack();
        cout << ans << "\n";
    }
    return 0;
}
