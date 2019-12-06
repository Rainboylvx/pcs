/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 20日 星期一 10:31:03 CST
* problem: uva-1347
*----------------*/
#include <bits/stdc++.h>
using namespace std;

#define maxn 1005

double dp[maxn][maxn];
struct _p {
    int x,y;
};
_p a[maxn];
int n;

void init(){
    int i;
    for (i=1;i<=n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
}

/* 得到两个点之间的距离 */
double get_dis(int i,int j){
    int lx = a[i].x -a[j].x;
    int ly = a[i].y -a[j].y;
    return sqrt(lx*lx+ly*ly);
}

void _dp(){
    memset(dp,0x42,sizeof(dp));
    dp[1][1] = 0;
    int i,j,k;
    for (i=1;i<=n;i++){
        for (j=1;j<=n;j++){
            /* 更新下一个点 */
            if( i <=j){
                dp[i][j+1] = min( dp[i][j] + get_dis(j,j+1), dp[i][j+1]);
                dp[j+1][j] = min( dp[j+1][j] ,dp[i][j]+ get_dis(i,j+1));
            }
            else {
                dp[i+1][j] = min( dp[i+1][j],dp[i][j] + get_dis(i,i+1));
                dp[i][i+1] = min(dp[i][i+1],dp[i][j]+ get_dis(j,i+1));
            }
        }
    }
    for(i=1;i<n;i++)
        dp[n][n] = min(dp[n][n],dp[i][n]+get_dis(i,n));
    for(i=1;i<n;i++){
        dp[n][n] = min(dp[n][n],dp[n][i]+get_dis(i,n));
    }
}

int main(){
    while ( scanf("%d",&n) !=EOF) {
        init();
        _dp();
        printf("%0.2lf\n",dp[n][n]);
    }
    return 0;
}
