/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 19日 星期日 21:09:37 CST
* problem: uva-1025
*----------------*/
#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7fffffff/3;
#define maxn 55 //最大的车站数目
#define maxt 205  //最大的时间
#define maxm 55 //最大的车的数量

int n,t;
int _time[maxn]; //间隔时间
int sum_t[maxn];
int m1,m2;
//f1[i][j] 表示 车辆i到站j的时间
int f1[maxm][maxn], f2[maxm][maxn]; 

//dp[i][j] 表示 在时刻i到达j站的最小等待时间
int dp[maxt][maxn];  
void init(){
    scanf("%d",&t);
    memset(_time,0,sizeof(_time));
    memset(sum_t,0,sizeof(sum_t));
    memset(f1,0,sizeof(f1));
    memset(f2,0,sizeof(f2));
    int i,j,t1;
    for (i=1;i<=n-1;i++){
        scanf("%d",&_time[i]);
        sum_t[i] = sum_t[i-1] + _time[i];
    }
    scanf("%d",&m1);
    for (i=1;i<=m1;i++){
        scanf("%d",&t1);
        for (j=1;j<=n;j++){
            f1[i][j] = t1+ sum_t[j-1];
        }
    }

    scanf("%d",&m2);
    for (i=1;i<=m2;i++){
        scanf("%d",&t1);
        for (j=1;j<=n;j++){
            f2[i][j] = t1 + sum_t[n-1]- sum_t[j-1];
        }
    }
}

void _dp(){
    /* 设置边界 */
    memset(dp,0x3f,sizeof(dp)); // 表示不合法
    dp[0][1] = 0; //在0时,到达站点1的时间为0
    int i,j,k,l;

    for(i=1;i<=t;i++){ //时间增长
        for(j=1;j<=n;j++){ //每个车站
            dp[i][j] = dp[i-1][j] +1;

            /* 从左边来 */
            for(l=1;l<=m1;l++){ //那一个车
                if( f1[l][j] == i){ //车l 可以在时间i到达j站
                    for(k=1;k<j;k++){ //从左边的哪个车站
                        dp[i][j] = min(dp[ f1[l][k] ][k],dp[i][j]);
                    }

                }
            }

            /* 从右边来 */
            for (l=1;l<=m2;l++){ //哪一个车
                if(f2[l][j] == i){ //可以到达车站j
                    for(k=j+1;k<=n;k++){ //前面的每一个车站
                        dp[i][j] = min(dp[i][j],dp[ f2[l][k] ][k]);
                    }
                }
            }

        }
    }
}

int main(){
    int idx=0;
    while(1){
        idx++;
        scanf("%d",&n);
        if( n== 0) break;
        init();
        _dp();
        if( dp[t][n] < 0x3f3f3f3f)
            printf("Case Number %d: %d\n",idx,dp[t][n]);
        else
            printf("Case Number %d: impossible\n",idx);

    }
    return 0;
}
