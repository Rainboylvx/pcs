/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 06日 星期四 15:18:43 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
const int mod = 1000007;
int n,m;
int f[105][105][105];
int a[105];



int main(){
    cin >> n >> m;
    int i,j,k;
    for(i=1;i<=n;++i){
        cin >> a[i];
    }
    for(i=0;i<=n;i++)
        f[i][0][0] = 1;
    int x;

    for(i=1;i<=n;++i){ // 枚举前i种花
        for(j=0;j<=a[i];j++){ //第i种花放j盆
            for(k=max(j,1);k<=m;k++){
                for(x = 0;x <= min(a[i-1],k-j) ;x++){
                    f[i][j][k] += f[i-1][x][k-j];
                    f[i][j][k] %= mod;
                }
            }
        }
    }
    int ans = 0;
    for(i=0;i<=a[n];i++){
        //printf("f[n][%d][m] = %d\n",i,f[n][i][m]);
        ans += f[n][i][m];
        ans %= mod;
    }
    cout << ans;


    return 0;
}
