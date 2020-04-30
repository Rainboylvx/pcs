/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 09 Apr 2020 09:33:31 AM CST
* problem: loj-103
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
typedef unsigned long long ULL;
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;

ULL p[maxn];
const int seed = 13331;
/* ======= 全局变量 END =======*/
char str_a[maxn],str_b[maxn];
int len_a,len_b;
ULL sum[maxn];
void init(){
    scanf("%s",str_a+1);
    scanf("%s",str_b+1);
    len_a = strlen(str_a+1);
    len_b = strlen(str_b+1);

    p[0] = 1;
    for(int i = 1;i< maxn ;i++)
        p[i] = p[i-1] *seed; //预处理 b^n

    sum[0] = 0;
    for(int i = 1;i<=len_a;i++){
        sum[i] = sum[i-1] * seed  + (ULL)(str_a[i]-'A'+1);
    }
    ULL s = 0;
    for( int i = 1;i<=len_b;i++){
        s = s *seed + (ULL)(str_b[i]-'A'+1);
    }
    int ans = 0;
    for(int i= 0;i<=len_a-len_b;i++){
        if( s == sum[(i+len_b)]-sum[i]*p[len_b]) ++ans;
    }
    printf("%d\n",ans);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
