/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 05月 23日 星期日 16:59:35 CST */
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
    m = 6;
    Random r1(5,5);
    n =  r1();
    Random x(1,m);
    Random color(0,1);
    printf("%d %d\n",m,n);
    for(int i=1;i<=n;++i){
        printf("%d %d %d\n",x(),x(),color());
    }
    return 0;
}
