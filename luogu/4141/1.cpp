/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 02月 03日 星期五 13:57:05 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

template<std::size_t capacity>
struct _backpack {
    int f[capacity] = {0};

    void init() {
        memset(f,0,sizeof(f));
        f[0] = 1;
    }

    //计算一个物品
    void calc(int w) {
        for(int i = capacity;i >= w; i--) {
            f[i] += f[i-w];
            f[i] %= 10;
        }
    }
};


_backpack<2005> mybp;
int g[2005];

vector<int> vec;
int main(int argc,char * argv[]){
    mybp.init();
    std::cin >> n >> m;
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        vec.push_back(t);
    }

    for (const auto& e : vec) {
        mybp.calc(e);
    }

    //遍历物品
    for (const auto& w : vec) {
        memcpy(g,mybp.f,sizeof(g)); //复制
        for(int j=1;j<=m;j++){
            //总体 mybp.f[j]
            // cout << g[j] << " ";
            int ans;
            if( j - w >=0) {
                g[j] = g[j] - g[j-w] +10;
                g[j] %= 10;
            }
            std::cout << g[j] ;
        }
        cout << "\n";
    }
    return 0;
}
