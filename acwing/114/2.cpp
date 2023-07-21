/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 02日 星期日 18:12:21 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

struct node {
    double l,r;
    bool operator<(node &b)
    {
        return r< b.r;
    }
};
node a[maxn];
int cnt = 0;

void init()
{
    cin >> n >> m;
    int x,y;
    for(int i=1;i<=n;++i){
        std::cin >> x >> y;
        // d -> m
        if( y < 0) y = -y;
        if( y > m) continue;
        double len = sqrt(m*m - y*y);
        ++cnt;
        a[cnt].l = x - len;
        a[cnt].r = x + len;
    }
}

template<typename T>
inline bool is_in_range(T&& a,T && l, T&& r) {
    return a >= l && a <= r;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    if( cnt != n) {
        std::cout << -1 << "\n";
        return 0;
    }
    sort(a+1,a+1+cnt);
    // for(int i=1;i<=cnt;++i){
    //     std::cout << a[i].l << " " << a[i].r << "\n";
    // }
    int ans = 1;
    double pre = a[1].r;
    for(int i=2;i<=cnt;++i){
        if( is_in_range(pre, a[i].l, a[i].r) ) continue;
        ans++;
        pre = a[i].r;
    }
    std::cout << ans << "\n";
    return 0;
}
