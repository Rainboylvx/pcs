/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 27日 星期三 21:41:00 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int f[100][100];
void init(){
    f[0][0] = 1;
    int i,j;
    for(i=1;i<=31;++i){
        f[i][0] = f[i-1][0];
        printf("%d: ",i);
        for(j=1;j<=i;++j){
            f[i][j] = f[i-1][j] + f[i-1][j-1];
            printf("%d ",f[i][j]);
        }
        printf("\n");
    }
}

// [0..x]内二进制表示含k个1的数的个数
int calc(int x,int k){
    int tot=0,ans=0;
    // tot 当前路径上已有1的数量，ans答案
    int i;
    for(i=31;i>=0;--i){
        if( x & (1<<i)){ // 对应位置上是不是1
            ++tot;
            if( tot > k) break;
            x = x^(1<<i); //置0
        }
        if( (1<<(i-1)) <=x ){
            ans += f[i-1][k-tot];
        }
    }
    if( tot+x == k) ++ans;
    return ans;
}

int main(){
    init();
    return 0;
}
