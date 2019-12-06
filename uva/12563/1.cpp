/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 21日 星期二 15:33:27 CST
* problem: uva-12563
*----------------*/
#include <bits/stdc++.h>
using namespace std;

const int jin_ge = 11*60 + 18;
int T;
int n,t;
int f[9900];
int a[55];
int all =0;
int dp[55][9900];
/* 
 * pre[i][j] == 1  表示 pre[i][j] 是由 pre[i-1][j-t[i]] 更新的,也就是没有选
 * pre[i][j] == 0  表示 pre[i][j] 是由 pre[i-1][j] 更新的,也就是选了
 *
 * */


void init(){
    memset(f,0,sizeof(f));
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&t);
    all = 0;
    int i,j;
    int t1;

    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
        all += a[i];
    }
}

void _dp(){
    int i,j;
    all = t-1;
    for (i=1;i<=n;i++){
        for(j=all;j>=a[i];j--){
            f[j] = max(f[j],f[j-a[i]]+1);
        }
    }


    memset(dp,0x80,sizeof(dp));
    memset(dp[0],0,sizeof(dp[0]));
    int k;
    for(i=1;i<=n;i++){ //前i个歌
        for(j=all;j>=a[i];j--) //容量
            for(k=min(f[all],i);k>=1;k--){
                dp[k][j] = max(dp[k][j],dp[k-1][j-a[i]]+a[i]);
            }
    }

    int sum = 0;
    printf("Case %d: %d %d\n",T,f[all]+1,dp[f[all]][all]+jin_ge);
}
int main(){
    int x; 
    scanf("%d",&x);
    for (T=1;T<=x;T++){
        init();
        _dp();
    }

    return 0;
}
