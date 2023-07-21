/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 23日 星期五 00:36:45 CST */
#include <bits/stdc++.h>
#include <bitset>
#include "utils.hpp"
#include "math/bit.hpp"
using namespace std;
typedef long long ll;

int n,m;
/* 定义全局变量 */

int dis[30][30];
int f[(1<<20)+5][30];
void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            std::cin >> dis[i-1][j-1]; //点的编号从0开始
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    int max_sate = (1<<n) - 1;
    int ans = 0x3f3f3f3f;

    memset(f,0x3f,sizeof(f));
    //边界
    // for(int i = 0 ;i<n;i++){
    //     f[1<<i][i] = 0;
    // }
    f[1][0] = 0;

    for(int i=1;i<=max_sate;++i){
        for(int j=0;j< n;j++) {
            auto bit = Bit(i);

            if( bit.is_0(j) ) continue;

            auto clear_at_j = bit;
            clear_at_j.clear(j);
            //枚举前面的点
            for(int k=0;k<=n-1;++k){
                if(clear_at_j.is_0(k)) continue;
                // upd_min(f[i][j], f[int(clear_at_j)][k] + dis[k][j]);
                if( f[i][j] > f[clear_at_j][k] + dis[k][j]){
                    f[i][j] = f[clear_at_j][k] + dis[k][j];
                    // cout <<"f[" << bitset<5>(i) << "," << j <<"] = " << f[i][j] << "<--" 
                        // << "f[" << bitset<5>(clear_at_j.to_number()) << "," << k << "] : " << f[clear_at_j][k] << " +"
                        // << dis[k][j] << '\n';
                }
                if( i == max_sate)
                    upd_min(ans, f[i][j]);
            }
            // log(i,j,f[i][j]);
        }
    }
    // for(int i=0;i<n;++i){
    //     cout << i << " : " << f[max_sate][i];
    //     std::cout  << "\n";
    // }
    std::cout << f[max_sate][n-1]<< "\n";
    return 0;
}
