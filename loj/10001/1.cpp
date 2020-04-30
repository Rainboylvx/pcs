/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 01:29:27 PM CST
* problem: loj-10001
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

struct range {
    int s,t,v;
    bool operator<(const range &b){ return t < b.t; }
};
range r[maxn];

/* ============ BIT BEG ============ */
namespace BIT {
    /* 单点更新 区间查询 */
    ll c[maxn],size;
    #define lowbit(x) (x &(-x))
    inline void bit_init(ll s=maxn){ memset(c,0,sizeof(c)); size=s;}
    void update_s(ll pos,ll num)    { for(;pos <=size ; pos+=lowbit(pos)) c[pos] +=num; }
    ll query(ll pos)  { ll sum =0; for( ;pos >0; pos-=lowbit(pos)) sum+=c[pos]; return sum;}
}
using namespace BIT;
/* ============ BIT END ============ */

int a[maxn];
/* ======= 全局变量 END =======*/
int ans=0;
void init(){
    scanf("%d",&n);
    scanf("%d",&m);
    bit_init(n);
    int i,x,y,z;
    For(i,1,m){
        scanf("%d%d%d",&x,&y,&z);
        r[i] = {x,y,z};
    }
    sort(r+1,r+m+1);
    For(i,1,m){
        int cnt = query(r[i].t) - query(r[i].s-1);
        if( cnt >= r[i].v) continue;
        cnt = r[i].v - cnt;
        int j;
        for( j = r[i].t ;j >= r[i].s && cnt > 0 ;j--){
            if(!a[j]){
                cnt--;
                a[j] = 1;
                ans++;
                update_s(j, 1);
            }
        }
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
