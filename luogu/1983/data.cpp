/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 05月 11日 星期二 09:03:38 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

struct Random {
    random_device rd;
    mt19937 engine{rd()};
    uniform_int_distribution<> dis;
    Random(){}
    Random(int l,int r){ dis = uniform_int_distribution<> (l,r); }
    int operator()(){ return dis(engine); }
} rnd;

int main(){
    Random N(3,5);
    Random N10(2,10);
    Random N5(1,5);
    int n = N();
    printf("10 %d\n",n);
    for(int i=1;i<=n;++i){
        set<int> s;
        int m = N5();
        //printf("%d ",m);
        for(int i=1;i<=m;++i){
            s.insert(N10());
        }
        vector<int> v;
        for (const auto& e : s) {
            v.push_back(e);
        }
        sort(v.begin(),v.end());

        printf("%d ",v.size());
        for (const auto& e : v) {
            printf("%d ",e);
        }
        printf("\n");

    }
    return 0;
}
