/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Fri 03 Apr 2020 03:50:45 PM CST
* problem: loj-130
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;

/* ======= 全局变量 END =======*/
namespace BIT {
    /* 单点更新 区间查询 */
    ll c[maxn],size;
    #define lowbit(x) (x &(-x))
    inline void bit_init(int s=maxn){ memset(c,0,sizeof(c)); size=s;}
    void update(int pos,int num)    { for(;pos <=size ; pos+=lowbit(pos)) c[pos] +=num; }
    ll query(int pos)  { ll sum =0; for( ;pos >0; pos-=lowbit(pos)) sum+=c[pos]; return sum;}
}
using namespace BIT;


void init(){
    scanf("%d%d",&n,&m);
    int i,t;
    bit_init(n);
    For(i,1,n){
        scanf("%d",&t);
        update(i,t);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,t,x,y;
    For(i,1,m){
        scanf("%d%d%d",&t,&x,&y);
        if( t == 1){
            update(x,y);
        }
        else {
            printf("%lld\n",query(y)-query(x-1));
        }
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
