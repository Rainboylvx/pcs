/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 06日 星期一 22:34:31 CST
* problem:  uva-1628
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

const int N =105;
int T,n;
int f[N][N][N][2];
int a[N],e[N];

int _abs(int x,int y){
    int ans = y - x;
    if( ans < 0 )
        return -ans;
    return ans;
}

int dp(int i,int j,int k,int p){

    int t1,t2,t3;
    if( p == 0){
        for(t1=1;t1<i;t1++){ //往左边走

            int ans1 = f[i][j][k][p] - k*_abs(i,t1) +e[t1];
            f[t1][j][k-1][0] = max( ans1, f[t1][j][k-1][0] );

        }

        for(t1=j+1;t1<=n;t1++){ //往右走
            int ans1 = f[i][j][k][p] - k*_abs(i,t1) + e[t1];
            f[i][t1][k-1][1] = max(ans1,f[i][t1][k-1][1]);
        }
    }
    else { //p ==1
        for(t1=1;t1<i;t1++){ //往左走
        }
        for(t1=j+1;t1<=n;t1++){//往右走
        }
    }
}

void init(){
    scanf("%d",&n);
    int i,k;
    for (i=1;i<=n;i++)
        scanf("%d",&a[i]); //位置
    for (i=1;i<=n;i++)
        scanf("%d",&e[i]); //e 初始价格

    /* 边界 */
    for (i=1;i<=n;i++){
        for(k=1;k<n;k++) //边界
            f[i][i][0][k] = f[i][i][1][k] = e[i] - k*fabs(a[i]);
    }

}

int main(){
    scanf("%d",&T);
    while(T--){
        init();

        int i,j,k,l;
        for(l=2;l<=n;l++){ //长度
            for(k=1;k<=n-l;k++){ //可选的k
            }
        }
    }
    return 0;
}
