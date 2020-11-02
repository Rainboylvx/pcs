/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 10月 16日 星期五 11:22:43 CST */
#include <bits/stdc++.h>
using namespace std;
#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 505;
int n,m;
int a[maxn][maxn];
int max1 =-1,max2 = -1;

void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n-1;++i){
        for(j=i+1;j<=n;j++){
            scanf("%d",&a[i][j]);
            a[j][i] = a[i][j];
            if( a[i][j] > max1) {
                max2 = max1;
                max1 = a[i][j];
            }
            else if( a[i][j] > max2)
                max2 = a[i][j];
        }
    } }

int ca[maxn],cb[maxn];
bool vis[maxn];

int find_max(int dep){
    int ret = -1,val = -1;
    int i,j;
    for(i=1;i<=n;++i){
        if( vis[i] == 0){
            for(j=1;j<=dep;++j){
                if( a[ca[j]][i] > val ){
                    ret = i;
                    val = a[ca[j]][i];
                }
            }
        }
    }
    return ret;
}

int find_max2(int b[]){
    int i,j,ans = -1;
    for(i=1;i<n/2;++i){
        for(j=i+1;j<=n/2;++j){
            ans = max(ans, a[b[i]][b[j]]);
        }
    }
    return ans;
}

int ANS = -1;
void dfs(int dep){
    if( dep == (n/2)+1){
        int d = find_max2(ca);
        ANS = max(ANS,d);
        return;
    }
    for(int i=1;i<=n;i++){
        if( vis[i] == 0){
            vis[i] = 1;
            ca[dep] = i;
            int pos = find_max(dep);
            vis[pos] = 1;
            cb[dep] = pos;

            dfs(dep+1);

            vis[pos] = 0;
            vis[i] = 0;
        }
    }
}


int main(){
    init();
    int i,j;
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            printf("%2d ",a[i][j]);
        }
        printf("\n");
    }
    printf("+++++++++\n");

    //ca[1] = 2;
    //ca[2] = 3;
    //printf("%d\n",find_max2(ca));

    dfs(1);
    printf("%d\n",1);
    printf("%d\n",ANS);
    printf("max1 = %d \nmax2= %d\n",max1,max2);

    return 0;
}
