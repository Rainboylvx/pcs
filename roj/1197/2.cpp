/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 00:05:30 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int d[505];
inline int len(int i){ //[i,i+1] 的距离
    return d[i];
}
int f[505][505];
int p[505][505]; // p[i][j] 表示i,i+1,...j-1 到j的距离和
int q[505][505]; // q[i][j] 表示i,i-1,i-2...j+1 到j的距离和
int pre[505]; // 前缀和 pre[j] 表示第j个村到第1个村的距离

/* 使用: 首先定义EF::check函数 
 * EF::work(int l,int r)            二分
 * EF::work(double l,double r)      二分-double
 *
 * EF::work 区间[l,r) 内第一个不满足check()的位置
 *  if check(mid) => mid < key 则找到第一个 >=key 的位置 
 *  if check(mid) => mid <=key 则找到第一个 >key  的位置 
 *  核心思想:[l,r)是满足check的区间,不停缩小[l,r)
 * */
namespace EF {
    //bool check(int mid);    //函数声明
    template<typename F>
    int work(int l,int r,F check){
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
}

// [i,j]之间的村到i,j的最小距离和
int Cost(int i,int j){
    int sum=0;
    if( j  == i+1) return 0;
    int middle = (pre[i] + pre[j]) / 2; //中间的位置
    // 二分查找到第一个> 中间的位置
    int pos = EF::work(i, j,
            [middle](int mid){
                if( pre[mid] <= middle) return 1;
                return 0;
            });
    sum += p[pos][j];
    sum += q[pos-1][i];
    return sum;
}

int Cost_mem[505][505];

int main(){
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m-1;++i) scanf("%d",&d[i]);
    for(int i=2;i<=m;++i){
        pre[i] = pre[i-1] + d[i-1];
    }
    for(int i=1;i<=m;++i){
        for(int j=i;j<=m;++j){
            p[i][j] = p[i][j-1] + (j-i)*len(j-1);
            //printf("p[%d][%d]=%d\t",i,j,p[i][j]);
        }
        //printf("\n");
    }
    for(int i = m;i>=1;i--) //起点
    {
        for(int j = i;j>=1;j--){//终点
            q[i][j] = q[i][j+1] + (i-j) * len(j);
            //printf("q[%d][%d]=%d\t",i,j,q[i][j]);
        }
        //printf("\n");
    }
    for(int i=1;i<=m;++i){
        for(int j=i+1;j<=m;j++)
            Cost_mem[i][j] =  Cost(i,j);
    }

    //初始化
    memset(f,0x7f,sizeof(f));
    for(int i=1;i<=m;++i) {
        f[i][1] = p[1][i]; //边界
        /*
         *printf("f[%d][%d]= %d\n",i,1,f[i][1]);
         */
    }

    int ans = 0x7f7f7f7f;

    for(int i=2;i<=m;i++){ //选前i个村
        int Max = min(i,n); //最多建立多个小学
        for(int j=2;j<=Max;++j){ //建j个学校
            for(int k=j-1;k<=i-1;k++){ // [j-1,i-1] 之段区间 建立 j-1学校
                f[i][j] = min(f[i][j],f[k][j-1]+ Cost_mem[k][i]);
            }
        }
    }
    for(int i=n;i<=m;++i){
        ans = min(
                ans,
                f[i][n] + q[m][i]
                );
    }
    printf("%d\n",ans);
    return 0;
}
