/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 10:37:01 AM CST
* problem:  loj-10003
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
struct  node { int a,b, m,idx;
    bool operator<(const node &b){
        return m < b.m;
    }
};
int n;

int a[maxn],b[maxn];
node m[maxn];
int ord[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i,t;
    For(i,1,n){
        scanf("%d",&m[i].a);
        m[i].idx = i;
        a[i] = m[i].a;
    }
    For(i,1,n){
        scanf("%d",&m[i].b);
        b[i] = m[i].b;
    }
    For(i,1,n){
        m[i].m =  min(m[i].a,m[i].b);
    }
    sort(m+1,m+1+n);
    int head = 1,tail = n;
    for( i =1;i<=n;i++){
        if( m[i].m == m[i].b){
            ord[tail--] = m[i].idx;
        }
        else ord[head++] = m[i].idx;
    }
    int a_end =0;
    int b_end =0;
    For(i,1,n){
        a_end += a[ord[i]];
        b_end = max(b_end,a_end);
        b_end += b[ord[i]];
    }
    printf("%d\n",b_end);
    For(i,1,n-1){
        printf("%d ",ord[i]);
    }
    printf("%d",ord[n]);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
