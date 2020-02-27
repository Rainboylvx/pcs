/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 11 Feb 2020 05:25:43 PM CST
* problem: luogu-1508
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
int a[300][300];
int f[300][300];
int sx,sy;
void init(){
    scanf("%d%d",&m,&n);
    int i,j;
    For(i,1,m){
        For(j,1,n){
            scanf("%d",&a[i][j]);
        }
    }
    For(i,0,299){
        For(j,0,299){
            f[i][j] = -0x3f3f3f3f;
        }
    }
    sy = (n+1)>>1;
    f[m+1][sy] = 0;
}
/* ======= 全局变量 END =======*/
void debug(){
    int i,j;
    For(i,1,m){
        For(j,1,n){
            if( f[i][j] < -1000)
                printf("%4c",'X');
            else
                printf("%4d",f[i][j]);
        }
        printf("\n");
    }
}

void dp(){
    int i,j;
    Rof(i, m, 1){
        For(j,1,n){
            f[i][j] = max(f[i+1][j]+a[i][j],f[i][j]);
            f[i][j] = max(f[i+1][j-1]+a[i][j],f[i][j]);
            f[i][j] = max(f[i+1][j+1]+a[i][j],f[i][j]);
        }
    }
    int ans = -0x3f3f3f3f;
    For(i,1,n){
        ans = max(ans,f[1][i]);
    }
    //debug();
    printf("%d\n",ans);

}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dp();

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
