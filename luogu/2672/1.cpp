//一个枚举的代码,基于排序
/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 27日 星期四 22:28:34 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
ll s[maxn];
ll a[maxn];

// 如果选第i个点为结尾,且只选一个的情况下,能得到的值
ll _base(int i) {
    return a[i] + s[i]*2;
}
void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        std::cin >> s[i];
    }
    for(int i=1;i<=n;++i){
        std::cin >> a[i];
    }
}

//前i个数,不包括i的x个最大数的和
ll get_sum(int i,int x) {
    std::vector<int> v;
    for(int j=1;j<i;++j){
        v.push_back(j);
    }
    std::sort(v.begin(),v.end(),[](int i,int j){ return a[i] > a[j];});
    ll sum = 0;
    for(int i = 0;i<x;i++) {
        sum += a[v[i]];
        // cout << v[i] << " ";
    }
    // cout <<" : " << sum ;
    // cout << endl;
    
    return sum;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    for(int i=1 ;i<=n;i++) {
        cout << _base(i) << " ";
    }
    cout << endl;

    // 枚举x
    for(int i=1 ;i<=n;i++) {
        cout << "------------- " << i << endl;
        ll ans = -1;
        int pos;
        for(int j = 1+i-1;j<=n;j++) { //枚举结尾
            // cout << " end point " << j << "  [ ";
            ll t = get_sum(j, i-1);
            t += _base(j);
            // cout << "all sum =" << t << "\n";
            if( ans < t) {
                ans = t;
                pos = j;
            }
        }
        cout << ans 
            << " pos: "  << pos
            << "\n\n";
    }
    
    return 0;
}
