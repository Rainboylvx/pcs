/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 12日 星期三 21:28:40 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5,maxe = 1e6+5; //点与边的数量

#define F(n) for(int i=1;i<=n;i++)
#define F3(i,s,t) for(int i=s;i<=t;i++)

int D,G;
// int h[maxn]; //每个物品的高度
// int life[maxn]; //第i个物品增加的生命
// int t[maxn]; // 第i个物品的掉落的时间

struct node {
    int t,life,h;
};

node a[maxn];
bool operator<(node & a,node & b) {
    return a.t  < b.t;
}


int f[105][3005];

void init()
{
    for(int i=0;i<=100;++i){
        for(int j=0;j<=3000;++j){
            f[i][j] = -0x7f7f7f7f;
        }
    }

    f[0][10] = 0; //能达到
    std::cin >> D >> G;
    F(G) {
        // std::cin >> t[i] >> life[i] >> h[i];
        std::cin >> a[i].t >> a[i].life >> a[i].h;
    }
    sort(a+1,a+1+G); //排序
}
const int neg_inf = -0x7f7f7f7f;


int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int time = 10;
    for(int i=1;i<=G;i++) {
            cout << a[i].t << " " << a[i].life <<  " " << a[i].h << "\n";
        // if( time >= a[i].t) {
        //     time += a[i].life;
        //     cout << a[i].t << " " << a[i].life <<  " time: " << time << "\n";
        // }
        // else
        //     break;
    }

    return 0;
}
