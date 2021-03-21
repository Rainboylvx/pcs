/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 20日 星期六 22:50:40 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
int f[505][505];
int d[505]; //距离
int pre[505];//距离,前缀和
int ppre[505];//距离,前缀和
int Rpre[505];
int Rppre[505];

// [i,j]之间的村到i,j的最小距离和
int Cost(int i,int j){
    int sum=0;
    for(int k=i+1;k<=j-1;++k){//遍历中间的村
        int di = pre[k] - pre[i]; // k->i 的距离
        int dj = pre[j] - pre[k];
        sum += min(di,dj);
    }
    return sum;
}

int main(){
    scanf("%d%d",&m,&n);
    for(int i=2;i<=m;++i){
        scanf("%d",&d[i]);
        pre[i] = pre[i-1] + d[i];
        //ppre[i] = ppre[i-1] + (i-1)*d[i];
        //printf("%d: %d %d\n",i,pre[i],ppre[i]);
    }
    for(int i=m-1;i>=1;i--){
        int t = d[i+1];
        Rpre[i] = Rpre[i+1] + t;
        Rppre[i] = Rppre[i+1] + (m-i)*t; // 后面到第i个村的距离和和
        // m - 1 1
        // m - 2 2
        // m - i i -> m-()
    }
    /*
     *for(int i=1;i<=m;++i){
     *    for(int j=1;j<=m;++j){
     *        printf("Cost(%d,%d)  = %d\n",i,j,Cost(i,j));
     *    }
     *}
     */
    memset(f,0x7f,sizeof(f));
    for(int i=1;i<=m;++i) {
        f[i][1] = 0; //边界
        for(int j=1;j<=i;j++)
            f[i][1] += pre[i] - pre[j];
        printf("f[%d][%d]= %d\n",i,1,f[i][1]);
    }
    int ans = 0x7f7f7f7f;

    for(int i=2;i<=m;i++){ //选前i个村
        int Max = min(i,n); //最多建立多个小学
        for(int j=2;j<=Max;++j){ //建j个学校
            for(int k=j-1;k<=i-1;k++){ // [j-1,i-1] 之段区间 建立 j-1学校
                f[i][j] = min(f[i][j],f[k][j-1]+ Cost(k,i));
            }
        }
    }
    for(int i=n;i<=m;++i){
        printf("f[%d][%d]=%d +",i,n,f[i][n]);
        printf("%d",Rppre[i]);
        printf("\n");
        ans = min(
                ans,
                //f[i][n] + pre[i+1] + pre[i+2] .... pre[n]
                f[i][n] + Rppre[i]
                );
    }
    printf("%d\n",ans);

    return 0;
}
