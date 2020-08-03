/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 30日 星期四 06:43:40 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int T,n,m;

int day[105][105];

struct node {
    int w,v;
};
node a[105];

int f[10005];
void full_pack(){
    memset(f,0,sizeof(f));
    int i,j;
    for(i = 1;i<=n;i++){
        for(j = a[i].w ;j<= m;j++){
            f[j] = max(f[j],f[j-a[i].w]+a[i].v);
        }
    }
    m += f[m];
}

int main(){
    scanf("%d%d%d",&T,&n,&m);
    int i,j,k;
    for(i=1;i<=T;++i){
        for(j=1;j<=n;++j){
            scanf("%d",&day[i][j]);
        }
    }

    //printf("m = %d\n",m);
    for(i=2;i<=T;i++){
        for(j=1;j<=n;++j){
            a[j].w = day[i-1][j];
            a[j].v = day[i][j] - day[i-1][j];
        }
        full_pack();
        //printf("%d:m = %d\n",i,m);
    }
    printf("%d\n",m);

    return 0;
}
