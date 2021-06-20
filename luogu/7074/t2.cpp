// dp
/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 20日 星期日 15:00:12 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5,maxe = 1e6+5; //点与边的数量

int n,m;

/* 定义全局变量 */
int mg[maxn][maxn];
int f1[maxn][maxn],f2[maxn][maxn];
void init(){
    scanf("%d%d",&n,&m);
    //printf("%d %d\n",n,m);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            scanf("%d",&mg[i][j]);
            //printf("%d ",mg[i][j]);
        }
        //printf("\n");
    }
    f1[1][1] = f2[1][1] = mg[1][1];
    //printf("%d\n",f1[1][1]);
    for(int i=2;i<=n;++i){
        f1[i][1] = mg[i][1] + f1[i-1][1];
        f2[i][1] = f1[i][1];
        //printf("%d\n",f1[i][1]);
    }
}
int main(){
    init();

    for(int j =2;j<=m;j++){
        f1[1][j] = max(f1[1][j-1],f2[1][j-1]) + mg[1][j]; // 只能从左边来
        for(int i=2;i<=n;++i){ //从上到下
            f1[i][j] = max(
                    max( f1[i][j-1], f2[i][j-1]) ,
                    f1[i-1][j]) + mg[i][j];
        }

        f2[n][j] = max(f1[n][j-1],f2[n][j-1]) + mg[n][j]; //只能从左边来
        for(int i=n-1;i>=1;--i){ //从下到上
            f2[i][j] = max(
                    max( f1[i][j-1],f2[i][j-1]),
                    f2[i+1][j]) + mg[i][j];
        }
    }
/*
 *    printf("n = %d\n",n);
 *
 *    for(int j=2;j<=m;++j){
 *        printf("j = %d: ",j);
 *        for(int i=1;i<=n;++i){
 *            printf("(%d %d) ",f1[i][j],f2[i][j]);
 *        }
 *        printf("\n");
 *    }
 */

    int ans = max(f1[n][m],f2[n][m])   ;
    printf("%d",ans);
    return 0;
}
