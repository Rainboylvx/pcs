/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 08:59:01 AM CST
* problem: loj-10009
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

int f[105][1200];
int val[105][1200];
int a[maxn],b[maxn],t[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    m = (m*60) / 5;
    int i,j;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    For(i,1,n){
        scanf("%d",&b[i]);
    }
    For(i,1,n-1){
        scanf("%d",&t[i]);
    }
    for( i =1;i<=n;i++){
        val[i][1] = a[i];
        int pre = a[i];
        for(j = 2;j<=m;j++){
            pre -= b[i];
            if(pre <=0) pre = 0;
            val[i][j] = val[i][j-1]+pre;
        }
    }


    //边界
    for(i=1;i<=m;i++){
        f[n][i] = val[n][i];
    }

    int k;
    for(i=n-1;i>=1;i--){ //枚举 池塘
        for(j=1;j<=m;j++){ //枚举 时间
            for(k=0;k<=j;k++){
                f[i][j] = max(f[i][j],
                        val[i][k] + ((j-k-t[i] <=0 ) ? 0 : f[i+1][j-k-t[i]])
                        );
            }
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i;
    int _max = -1;
    for( i =1;i<=m;i++){
        _max = max(f[1][i],_max);
        //printf("%d %d \n",i,f[1][i]);
    }
    printf("%d\n",_max);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
