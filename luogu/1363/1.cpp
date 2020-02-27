/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 22 Feb 2020 09:41:52 AM CST
* problem: luogu-1363
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1505;
int n,m;
int g[maxn][maxn];
bool vis[maxn];
char s[maxn][maxn];
int sx,sy;

/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while( scanf("%d%d",&n,&m)!= EOF){
        int i,j;
        For(i,0,n-1){
            scanf("%s",s[i]);
        }
        For(i,0,n-1){
            For(j,0,m-1){
                if( s[i][j] == 'S') sx=i,sy = j;
                if( s[i % n ][j % m] == '#')
                    g[i][j] = 0;
                else
                    g[i][j] = 1;
                printf("%c",s[i % n ][j % m]);
            }
            printf("\n");
        }
        printf("============\n");
    }


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
