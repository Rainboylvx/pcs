/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 20日 星期二 19:48:46 CST */
#include <bits/stdc++.h>
#include "utils/log.hpp"
using namespace std;
typedef long long ll;
const int maxn = 3835,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int f[maxn][maxn][2];
int a[maxn];

void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        std::cin >> a[i];
    }
}

template<typename T1>
void max_upd(T1 & a,const T1 & b) {
    if( a < b)
        a = b;
}

template<typename T1,typename... T>
void max_upd(T1 & a,const T1 & b ,const T&... o) {
    if( a < b)
        a = b;
    max_upd(a,o...);
}

// number<int> _max;
int _max;
void dp() {

    //边界,选0个的情况
    for(int i = 2;i <= n;i++)
        max_upd( f[i][0][0] ,f[i-1][0][0]);

    for(int i = 1;i <= m;i++){ //枚举 亮的数量
        for(int j =1;j<= n;j++) { // 枚举 长度
            if( i > j ) continue; //超过了容量
            max_upd(f[j][i][1], f[j-1][i-1][1] + a[j],f[j-1][i-1][0]);
            
            max_upd(_max,f[j][i][1]);
            // log(j,i,1,f[j][i][1]);
            // cout << j <<' ' << i << ' ' << 1 <<"--->" << f[j][i][1] << '\n';
            max_upd(f[j][i][0],f[j-1][i][1],f[j-1][i][0]);
            max_upd(_max,f[j][i][0]);
            // cout << j <<' ' << i << ' ' << 0 <<"--->" << f[j][i][0]<< '\n';
            // if(_max == 1357926) {
            //     cout << j <<' ' << i << ' ' << 0 <<"--->" << f[j][i][0]<< '\n';
            // }
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();

    // dp1 
    // memset(f, -1, sizeof(f));
    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            for(int k=0;k<=1;++k){
                f[i][j][k] = -0x7f7f7f7f;
            }
        }
    }
    f[1][1][1] = 0; //选中第一个 ,为0
    f[1][0][0] = 0; //不选中第一个 ,为0
    dp();
    // return 0;

    // number<int> ans = _max;
    int ans = _max;

    for(int i=0;i<maxn;++i){
        for(int j=0;j<maxn;++j){
            for(int k=0;k<=1;++k){
                f[i][j][k] = -0x7f7f7f7f;
            }
        }
    }
    f[1][1][1] = a[1];
    dp();
    max_upd(ans, f[n][m][1]);
    // std::cout << f[n][m][1] << "\n";
    // dp2 

    // memset()
    // dp();
    std::cout << ans << std::endl;
    return 0;
}
