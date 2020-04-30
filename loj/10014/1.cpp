/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 08 Apr 2020 03:41:20 PM CST
* problem: loj-10014
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
int _max = -1;
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,n){
        scanf("%d",&a[i]);
        _max = max(_max,a[i]);
    }
}

bool check( int val){
    int sum=a[1],i,cnt=1;
    For(i,2,n){
        if( a[i]+sum > val){
            cnt++;
            sum = a[i];
        }
        else sum += a[i];
    }
    return cnt<=m;
}

int first_ge(){
    int l=_max,r=1e9,mid;
    while( l != r  ) //表示l和r没有重合
    {
        mid = (l+r) >>1; // 取中间位置
        if(!check(mid)) //表示 [m+1,r) 满足条件
            l = mid+1;
        else
            r = mid;
    }
    return l;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //printf("%d\n",check(6));
    printf("%d\n",first_ge());

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
