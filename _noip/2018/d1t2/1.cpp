/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 21日 星期二 19:12:50 CST
* problem: luogu-5020
*----------------*/
#include <bits/stdc++.h>
using namespace std;

#define maxn 25005
int T;
int n;
int a[maxn];
int f[maxn];


void init(){
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    memset(f,0,sizeof(f));
    f[0] = 1;
    sort(a+1,a+n+1);
}

void dp(){
    int i,j;
    int _max = a[n];
    int cnt = 1;

    for(j=a[1];j<=_max;j++){
        if( f[j] == 0 && f[j-a[1]] == 1){
            f[j] = 1;
        }
    }


    for(i=2;i<=n;i++){
        if(f[ a[i] ] == 0){
            cnt++;
            for(j=a[i];j<=_max;j++){
                if( f[j] == 0 && f[j-a[i]] == 1){
                    f[j] = 1;
                }
            }
        }
    }

    printf("%d\n",cnt);
}

int main(){
    scanf("%d",&T);
    while(T--){
        init();
        dp();
    }
    return 0;
}
