/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 29 Mar 2020 02:37:37 PM CST
* problem:  online_judge-_id 
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m,T;
int cnt;
int row[maxn],col[maxn];
int sum[maxn];

int compute(int a[],int len,int avg){
    memset(sum,0,sizeof(sum));
    int cnt = 0;
    int i;
    for(i = 1;i<=len;i++){
        a[i] -= avg;
        a[len+i] = a[i];
    }
    for(i=1;i<len+len;i++){
        sum[i] = sum[i-1] + a[i];
    }
    for( i =len;i<len+len;i++){
        int ans = sum[i] -
    }
    return cnt;
}

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d%d",&n,&m,&T);
    int i,x,y;
    For(i,1,T){
        scanf("%d%d",&x,&y);
        row[x]++;
        col[y]++;
    }

    bool r = ( T % n ) == 0;
    bool c = ( T % m ) == 0;
    if( r && c){
        printf("both ");
        printf("%d",compute(row, n, T/n) + compute(col, m, T/m));
    }
    else if( r ){
        printf("row ");
        printf("%d",compute(row, n, T/n));
    }
    else if ( c){
        printf("column ");
        printf("%d",compute(col, m, T/m));
    }
    else 
        printf("imposible\n");
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    printf("\n");
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
