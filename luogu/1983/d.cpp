/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 01月 26日 星期三 09:11:50 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

struct Random {
    random_device rd;
    mt19937 engine{rd()};
    uniform_int_distribution<long long> dis; // in [0,0x7fffffffffffffff]
    Random(){}
    Random(int l,int r){ dis = uniform_int_distribution<long long> (l,r); }

    int operator()(){ return dis(engine); }
    template<typename U> //产生一定范围内的随机数
    U operator()(U l,U r){ return dis(engine) % ( r-l+1 ) + l; }

    Random create(int l,int r){ return Random(l,r); } //工厂模式
} rnd;

int main(int argc,char * argv[]){
    int n = 5;
    int m = 3;
    std::cout << n <<" "<< m << std::endl;
    for(int i=1;i<=m;++i){
        int x = rnd(2,n);
        set<int> s;
        for(int j=1;j<=x;++j){
            s.insert(rnd(1,n));
        }
        vector<int> v;
        for (const auto& e : s) {
            v.push_back(e);
        }
        sort(v.begin(),v.end());
        std::cout << v.size() << " " ;
        for (const auto& e : v) {
            std::cout << e << " " ;
        }
        std::cout << std::endl;
    }
    return 0;
}
