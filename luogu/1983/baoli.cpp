/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 01月 26日 星期三 09:46:10 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
vector<int> v[100];

int d[1000];
int ans = 999999;

bool check(){
    for(int i=1;i<=m;++i){ //检查m条线路
        int size = v[i].size(); //车站的数量
        int st = 0; // st v[i]的下标
        int _min_carStation =  999999;
        for(int j=0;j<size;j++)
            _min_carStation = std::min(_min_carStation,d[v[i][j]]);

        for(int j=1;j<size;j++){
            int start = v[i][j-1];
            int end = v[i][j];
            for(int k=start+1;k<end;++k){ //尝试中间的car station
                if( d[k] >= _min_carStation)
                    return false;
            }
        }
    }
    return true;
}

bool dfs(int dep){
    if( dep > n){
        if( check() ){
            // 到到最大的那个点
            int _max = 0;
            for(int i=1;i<=n;++i){
                _max = std::max( _max,d[i]);
            }
            ans = std::min(ans,_max);
            // std::cout << " YES << " << ans;
            cout << ans;
            return true;
        }
        return false;
    }
    for(int i=1;i<=n;++i){
        d[dep] = i;
        if( dfs(dep+1))
            return  true;
    }
    return false;
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
            v[i].push_back(tt); //第i条车
        }
    }
    dfs(1);
    // std::cout << ans ;

    return 0;
}
