/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 11日 星期二 18:10:35 CST */
#include <bits/stdc++.h>
// #include "utils/clock.hpp"
using namespace std;
typedef long long ll;
const int maxn = 1e3+5,maxe = 105;

#define  F(i,s,t) for(int i =s;i<=t;++i)

// ll g[maxn][maxe][maxe];
ll f[maxn][maxe][maxe]; //f[i][j][k]
ll sum[maxn][maxe][maxe]; //前缀和
const ll mod = 1000000007;

int n,m,k;
char s1[maxn];
char s2[maxn];
/* 定义全局变量 */

//定义保存第f[i-1][j][k]的第k层信息


//读取数据 
void init()
{
    scanf("%d%d",&n,&m);
    scanf("%d",&k);
    scanf("%s",s1+1);
    scanf("%s",s2+1);
}

//求dp
void dp() {
    for(int i = 0;i<=n;i++)
        f[i][0][0] = 1;
    int kk = k;
    F(i,1,n) // s1,前i个元素
    {
        F(j,1,m) { // s2,前j个元素
            F(k,1,kk) // 匹配的数量
            {
                ll ans = f[i-1][j][k];

                // for(int l = 0; j-l>0 && i-l >0 ;l++) { //检举长度
                //     if( s1[i-l] != s2[j-l] ) break;
                //     ans += f[i-l-1][j-l-1][k-1];
                //     ans %= mod;
                // }

                if(s1[i] == s2[j]) {
                    sum[i][j][k-1] = sum[i-1][j-1][k-1] + f[i-1][j-1][k-1];
                    sum[i][j][k-1] %= mod;
                    ans += sum[i][j][k-1];
                    ans %= mod;
                }

                f[i][j][k] = ans;
            }
        }
    }

}

int main(int argc,char * argv[]){
    // Clock t("main");
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    dp();
    std::cout << f[n][m][k] << "\n";
    return 0;
}
