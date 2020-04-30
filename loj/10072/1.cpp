/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 01 Mar 2020 03:57:35 PM CST
* problem: loj-10072
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e3+5;
int n,m;
int f[maxn][maxn];
int W[maxn][maxn];
int nxt[maxn][maxn];

void init(){
    scanf("%d%d",&n,&m);
    int u,v,w;
    int i;
    memset(f,0x1f,sizeof(f));
    memset(W,0x1f,sizeof(W));
    memset(nxt,-1,sizeof(nxt));
    For(i,1,m){
        scanf("%d%d%d",&u,&v,&w);
        f[u][v] = f[v][u] = min(f[u][v],w);
        W[u][v] = W[v][u] = min(W[v][u],w);
        nxt[u][v] = v;
        nxt[v][u] = u;
    }
}
/* ======= 全局变量 END =======*/

int ans = 0x1f1f1f1f;

int ai,ak,aj;
void floyed(){
    int i,j,k;
    for(k=1;k<=n;k++){

        for(i=1;i<k;i++)
            for( j =i+1;j<k;j++){
                if( W[i][k] + W[k][j] + f[i][j] < ans){
                    ans = W[i][k] + W[k][j] + f[i][j];
                    ak = k,ai =i, aj = j;
                }
            }

        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if( f[i][j] > f[i][k] + f[k][j]){
                    f[i][j] = f[i][k] + f[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    floyed();
    if( ans == 0x1f1f1f1f)
    {
        printf("No solution.");
            return 0;
    }
    //printf("%d\n",ans);
    while( nxt[ai][aj] != aj){
        printf("%d ",ai);
        ai = nxt[ai][aj];
    }
    printf("%d %d ",ai,aj);
    printf("%d\n",ak);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
