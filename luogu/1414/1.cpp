#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const int maxn = 1e6+5;
int n,t=0,c[maxn];
// c[i] i作为约数出现的次数
// c[i-1] c[i]的关系
// c[i] 是一个整体下降的趋势
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        int x; scanf("%d",&x);
        t = max(t,x);

        int m = sqrt(x);
        //针对每个数求约数
        for(j=1;j<=m;++j){
            if( x % j == 0){
                c[j]++;
                if( x != j*j ) c[x/j]++;
            }
        }
    }
    int x = t;
    // 找i个数的公约数
    // f[k] 表示 k个数的公约数,f[k-1] >= f[k]
    for(i=1;i<=n;++i){
        while(c[x] < i ) x--; // 想更小的数取尝试
        printf("%d\n",x);
    }
    return 0;
}


