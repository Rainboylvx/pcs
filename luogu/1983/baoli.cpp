/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 01月 26日 星期三 09:46:10 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
vector<int> v[100];

int d[1000];
int ans;

bool check(){
    for(int i=1;i<=m;++i){
        int start = v[i].front();
        int end = v[i].back();
        int st = 0; // st v[i]的下标
        int _max = 0; //记非路线上的车站的最大值
        int _min = 9999999; // 记在路线上的最小值
        for(int j = start ; j <= end;j++){
            if( j == v[i][st]){
                _min = min(_min,d[j]);
                st++;
            }
            else {
                _max = max(_max,d[j]);
            }
        }
        if( _min <= _max) return false;
    }
    return true;
}

void dfs(int dep){
    if( dep > n){
        if( check() ){
            for(int i=1;i<=n;++i){
                //std::cout << d[i] << " ";
                ans = min(ans ,d[i]);
            }
            //std::cout << " YES" ;
            //std::cout  << std::endl;
        }
        return;
    }
    for(int i=1;i<=n;++i){
        d[dep] = i;
        dfs(dep+1);
    }
}

int main(int argc,char * argv[]){
    std::cin >> n >> m;
    ans = n;
    for(int i=1;i<=m;++i){
        int t;
        std::cin >> t;
        for(int j=1;j<=t;++j){
            int tt;
            std::cin >> tt;
            v[i].push_back(tt);
        }
    }
    dfs(1);
    std::cout << ans ;

    return 0;
}
