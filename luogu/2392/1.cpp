/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 01月 29日 星期日 14:50:35 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int s[5];
/* 定义全局变量 */

//01 背包的封装
template<size_t CAP,size_t CNT>
struct backPack {
    int pack_capacity; // 背包容量
    struct Item {
        int w; //重量,消耗
        int v; //value 价值
    } items[CNT];


    int f[CAP]; //各个容量下得到的价格

    void init() {
        memset(f, 0, sizeof(f));
    }

    //计算01背包
    void calc(int _cap = CAP,int cnt = CNT) {
        //枚举物品
        for(int i=1;i <= cnt;++i) {
            //倒,检举容量
            for(int j=_cap ;j >= items[i].w ;--j ){
                int new_v=  f[j-items[i].w] + items[i].v;
                f[j] = f[j] < new_v ?  new_v : f[j];
            }
        }
    }
};

    //20个物品,每个消耗60
    backPack<20*60+10, 25> mybackPack;
int main(int argc,char * argv[]){

    int ans = 0;
    //读取数据
    for(int i=1;i<=4;++i){
        cin >> s[i];
    }

    for(int i=1;i<=4;++i){
        mybackPack.init();
        int tot = 0;
        for(int j=1;j<=s[i];++j){
            cin >> mybackPack.items[j].w; //消耗
            //价值
            mybackPack.items[j].v = mybackPack.items[j].w;
            tot += mybackPack.items[j].w;
        }
        int t = tot;
        if(  s[i] == 1) {
            t = tot;
        }
        else {
            mybackPack.calc(tot,s[i]);
            for(int j = 0; j <= tot ;j++){
                int tt = max(mybackPack.f[j],tot-mybackPack.f[j]);
                t = min(t,tt);
            }
        }
        // cout << "t= " << t << "\n";
        ans += t;
    }
    std::cout << ans ;

    return 0;
}
