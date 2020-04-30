/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 04 Apr 2020 04:44:22 PM CST
* problem: loj-10115
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

/* ======= 全局变量 END =======*/
/* ============ BIT BEG ============ */
namespace BIT_S {
    /* 单点更新 区间查询 */
    ll c[maxn],size;
    #define lowbit(x) (x &(-x))
    inline void bit_init(ll s=maxn){ memset(c,0,sizeof(c)); size=s;}
    void update_s(ll pos,ll num)    { for(;pos <=size ; pos+=lowbit(pos)) c[pos] +=num; }
    ll query(ll pos)  { ll sum =0; for( ;pos >0; pos-=lowbit(pos)) sum+=c[pos]; return sum;}
}
/* ============ BIT END ============ */

/* ============ BIT BEG ============ */
namespace BIT_E {
    /* 单点更新 区间查询 */
    ll c[maxn],size;
    #define lowbit(x) (x &(-x))
    inline void bit_init(ll s=maxn){ memset(c,0,sizeof(c)); size=s;}
    void update_s(ll pos,ll num)    { for(;pos <=size ; pos+=lowbit(pos)) c[pos] +=num; }
    ll query(ll pos)  { ll sum =0; for( ;pos >0; pos-=lowbit(pos)) sum+=c[pos]; return sum;}
}
/* ============ BIT END ============ */
void init(){
    scanf("%d%d",&n,&m);
    BIT_S::bit_init();
    BIT_E::bit_init();
    int i,t,x,y;
    For(i,1,m){
        scanf("%d%d%d",&t,&x,&y);
        if( t == 1){
            BIT_S::update_s(x, 1);
            BIT_E::update_s(y, 1);
        }
        else {
            ll ans = BIT_S::query(y) -BIT_E::query(x-1);
            printf("%lld\n",ans);
        }
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
