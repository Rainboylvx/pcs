/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 31日 星期一 20:53:20 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,w;
/* 定义全局变量 */

void init()
{
    cin >> n >> w;
}
int bucket[maxn];

int get_seq_k(int k) {
    int sum = 0;
    for(int i=600;i>=0;--i){ //注意这里,可能得到0分
        sum += bucket[i];
        if( sum >= k)
            return i;
    }
    return 1; //应该永远不会执行到这里
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        bucket[t]++;
        int k = (i*w) /100;
        if( k <1) k = 1;
        // cout << k << " " <<  get_seq_k(k)<<endl;
        cout << get_seq_k(k) << " ";

    }
    return 0;
}
