//暴力
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e2+5;
int n,k;
int a[maxn],b[maxn],c[maxn];
int f[maxn];

/* ======= 全局变量 END =======*/

void init(){
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
    }
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if( j== i) continue;
            if( a[j] <= a[i]&& b[j] <= b[i] && c[j] <= c[i])
                f[i]++;
        }
    }
    for(i=0;i<n;i++){
        int ans=0;
        for(j=1;j<=n;j++){
            if( f[j] == i)
                ans++;
        }
        printf("%d\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
