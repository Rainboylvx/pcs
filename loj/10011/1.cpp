/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 07 Apr 2020 08:54:07 AM CST
* problem: loj-10011
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
int a[maxn];

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
}


bool check(int dis){
    int i,s = 0,cnt = 1;
    For(i,2,n){
        s += a[i]-a[i-1];
        if( s >= dis){
            s = 0;
            if( ++cnt >= m) return true;
        }
    }
    return 0;
}

//查找范围是[l,r), a[r] 永远 > key
template <typename T>
int first_g(T key,T a[],int l,int r){
    int m;
    while( l != r  ) //表示l和r没有重合
    {
        m = (l+r) >>1; // 取中间位置
        if(check(m)) //表示 [m+1,r) 满足条件
            l = m+1;
        else
            r = m;
    }
    return l;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    if( m == 2 ){
        printf("%d\n",a[n]-a[1]);
        return 0;
    }
    //printf("%d\n",check(7));
    int ans = first_g(0, a, 1, a[n]+1);
    printf("%d\n",ans-1);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
