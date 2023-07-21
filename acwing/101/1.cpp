/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 05日 星期三 10:42:56 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,p,h;
/* 定义全局变量 */


int sub[maxn]; //差分数组


//区间加减
void sub_range(int l,int r,int add) {
    if( l > r) return;
    sub[l] += add;
    sub[r+1] -= add;
}

void init()
{
    std::cin >> n >> p >> h >> m;
}

bool _m[5005][5005];

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    sub[1] = h;
    for(int i=1;i<=m;++i){
        int l,r;
        std::cin >> l >> r;
        if( l > r)
            std::swap(l, r);
        if( l > n || r > n) continue;
        if( _m[l][r]) continue;
        _m[l][r] = 1;
        if( l == r-1) continue;
        sub_range(l+1, r-1, -1);
    }
    ll sum = 0;
    for(int i=1;i<=n;++i){
        sum += sub[i];
        std::cout << sum << "\n";
    }
    
    return 0;
}
