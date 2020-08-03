/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019-05-20 16:36
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

    /* dp[i][j] j >i */
    for (i=1;i<=n;i++){
        for (j=i;j<=n;j++){
            /* 更新下一个点 */
            dp[i][j+1] = min( dp[i][j+1], dp[i][j] + get_dis(j,j+1) );
            dp[j][j+1] = min( dp[j][j+1], dp[i][j] + get_dis(i,j+1) );
        }
    }

    for(i=1;i<n;i++)
        dp[n][n] = min(dp[n][n],dp[i][n]+get_dis(i,n));
}

int main(){
    while ( scanf("%d",&n) !=EOF) {
        init();
        _dp();
        printf("%0.2lf\n",dp[n][n]);
    }
    return 0;
}
