#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m,k;
int pos;

/* ======= 全局变量 END =======*/
const int maxn = 1e5+5;

bool vis[maxn];

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d%d",&n,&m,&k);
    int i;
    for( i =1 ;i<=m;i++){
        scanf("%d",&pos);
        pos++;
        while(1){
            int np = pos + k;
            if( np > n) np %= n;
            if( vis[np] ) break;
            pos  = np;
            vis[np] = 1;
        }
    }
    For(i,1,n){
        printf("%2d ",i);
    }
    printf("\n");
    int cnt  = 0;
    For(i,1,n){
        printf("%2d ",vis[i]);
        if( !vis[i]) cnt++;
    }
    printf("\n");
    printf("%d\n",cnt);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
