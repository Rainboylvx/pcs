#include "algo/discrete.hpp"

discrete mydiscrete;

//创建一个桶
int bucket[maxn];
int a[maxn]; //原来每个人爱好的语言
int b1[maxn],b2[maxn]; //每个电影使用的编号

int main(){
    int n,m;
    std::cin >> n;
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        mydiscrete.push(t);
        a[i] = t;
    }
    mydiscrete.decrete(); //对每个语言进行离散化

    for (int i =1;i <=n;i++) {
        //统计每个语言 被喜欢的次数
        bucket[mydiscrete[ a[i] ]]++;
    }

    std::cin >> m;

    int _max1 = -1,_max2= -1; //记录很开心,开心的人数

    for(int i=1;i<=m;++i){
        std::cin >> b1[i];
    }
    for(int i=1;i<=m;++i){
        std::cin >> b2[i];
    }
    int ans;
    for(int i=1;i<=m;++i){
        int x = b1[i];
        int y = b2[i];
        int q1 = mydiscrete[x]; //得到离散化后的值
        int q2 = mydiscrete[y];
        if( _max1 < bucket[q1]) {
            _max1 = bucket[q1];
            _max2 = bucket[q2];
            ans = i;
        }
        else if ( _max1 == bucket[q1] && _max2 < bucket[q2]) {
            _max1 = bucket[q1];
            _max2 = bucket[q2];
            ans = i;
        }
    }

    std::cout << ans << "\n";

    return 0;
}
