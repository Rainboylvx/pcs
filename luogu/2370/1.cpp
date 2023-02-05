/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 02月 03日 星期五 13:21:52 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,p,s;

/* 定义全局变量 */

//01 backpack
// CNT 表示物品的数量
// CAPACITY 表示背包的容量
template<std::size_t CAPACITY>
struct backpack {
    int f[CAPACITY] = {0};
    void init() {
        memset(f,0,sizeof(f));
    }


    //计算一个物品,
    void calc(int w,int v) {
        for(int i = CAPACITY; i >= w ;--i) {
            if( f[i] < f[i-w] + v)
                f[i] = f[i-w] + v;
        }
    }
};

//存物品
std::vector< std::pair<int,int> > vec;
// 前i个物品的得到的最大值
std::vector<int> ans;

backpack<1005> my01bp;


int main(int argc,char * argv[]){
    std::cin >> n >> p >> s;
    for(int i=1;i<=n;++i){
        int w,v;
        std::cin >> w >> v;
        //读取一个物品,计算一个物品
   //     vec.emplace_back(w,v);
       vec.push_back({w,v});
    }
    std::sort(vec.begin(),vec.end());

    for (const auto& [w,v] : vec) {
        my01bp.calc(w,v);
        // 存下前i个物品的最大值
        ans.push_back(my01bp.f[s]);
        // cout << my01bp.f[s] << endl;
    }
    auto it = std::lower_bound(ans.begin(), ans.end(), p);

    if( it == ans.end())
        cout << "No Solution!";
    else
        cout << vec[(it-ans.begin())].first;

    return 0;
}
