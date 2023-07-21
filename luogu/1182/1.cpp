/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 10日 星期一 16:42:21 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
ll a[maxn]; //前缀和
ll Ma;

void init()
{
    cin >> n >> m;

    for(int i=1;i<=n;++i){
        std::cin >> a[i];
        Ma = std::max(Ma,a[i]);
        a[i] += a[i-1];
    }
}

//检查是否能在最大值不超过val的情况下,
// 可以分M段
bool check(int val) {
    int pre=0; //上一次分段的结束点
    int cnt=0; // 分了几段

    for(int i =1;i<=n;i++) {
        if( a[i] -  a[pre] > val) {
            cnt++;
            pre = i-1;
        }
    }
    if( pre != n)
        cnt++;
    return cnt <=m;
}

int bs_search(int l,int r) {

    while( l < r) {
        int mid = (l +r) >>1;
        if( check(mid) )
            r = mid;
        else
            l = mid+1;
    }
    return l;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    int ans = bs_search(Ma, 1000000000);
    std::cout << ans ;
    return 0;
}
