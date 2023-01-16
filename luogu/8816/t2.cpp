/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 01月 16日 星期一 13:51:22 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,k;
/* 定义全局变量 */

int f[505][105];

std::vector<pair<int,int>> vec;

using Pair = std::pair<int,int>;

int _abs(int x) { return x <0 ? -x : x; }

int manhattan_dist(const Pair & p1, const Pair & p2) {
    return _abs(p1.first-p2.first) + _abs(p1.second-p2.second);
}

bool all_bigger(const Pair &p1 ,const Pair & p2){
    return p1.first >= p2.first && p1.second >= p2.second;
}

int main(int argc,char * argv[]){
    cin >> n >> k;
    for(int i=1;i<=n;++i){
        int x,y;
        std::cin >> x >> y;
        vec.emplace_back(x,y);
    }

    std::sort(vec.begin(),vec.end());

    int ans = 0;
    // for (const auto& e : vec) {
    //     std::cout << e.first << " "  << e.second << "\n";
    // }
    // std::cout << "=====================" << "\n";
    
    // initial edge
    for(int i =0;i<n;i++){
        for(int j =0;j<=k;j++){
            f[i][j] = j+1;
            ans = max(f[i][j],ans);
        }
    }

    for(int i = 1;i < vec.size();i++){
        for(int j =0;j<i;j++){
            int ret1 = manhattan_dist(vec[j], vec[i]);
            if (ret1 < 1 ) continue;
            bool ret2 = all_bigger(vec[i], vec[j]);
            if( !ret2 ) continue;

            for(int mk= 0 ;mk <=k;mk++){
                 int need = ret1-1;
                 if( need <= mk) {
                    f[i][mk] = max(f[i][mk],f[j][mk-need]+need+1);
                    ans = max(f[i][mk],ans);
                 }
            }
        }
        //dandiao
        // std::cout << i+1 <<" "<< f[i][k] << std::endl;
    }
    std::cout << ans << std::endl;
    return 0;
}
