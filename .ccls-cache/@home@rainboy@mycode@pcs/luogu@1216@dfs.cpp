/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 19:08:48 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n;
int a[1005][1005];
int ans;

void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){ //行
        for(j=1;j<=i;++j){ //每一行的数
            scanf("%d",&a[i][j]);
        }
    }
}

void dfs(int x,int y,int sum){
    //边界
    if( x == n){
        ans = max(ans,sum+a[x][y]);
        return;
    }
    dfs(x+1,y,sum+a[x][y]);
    dfs(x+1,y+1,sum+a[x][y]);
}

int main(){
    init();
    dfs(1,1,0);
    printf("%d\n",ans);

    return 0;
}
