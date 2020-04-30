/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Fri 03 Apr 2020 04:24:47 PM CST
* problem: loj-10114
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
vector<pair<int,int> >   v1;
int a[maxn];

/* ======= 全局变量 END =======*/

/* ============ BIT BEG ============ */
namespace BIT {
    /* 单点更新 区间查询 */
    ll c[maxn],size;
    #define lowbit(x) (x &(-x))
    inline void bit_init(ll s=maxn){ memset(c,0,sizeof(c)); size=s;}
    void update_s(ll pos,ll num)    { for(;pos <=size ; pos+=lowbit(pos)) c[pos] +=num; }
    ll query(ll pos)  { ll sum =0; for( ;pos >0; pos-=lowbit(pos)) sum+=c[pos]; return sum;} }
/* ============ BIT END ============ */
using namespace BIT;


void init(){
    scanf("%d",&n);
    int i,u,v;
    bit_init(maxn);
    For(i,1,n){
        scanf("%d%d",&u,&v);
        u++;v++; //防止出现0,因为bit数组从1开始
        v1.push_back(make_pair(u, v));
    }
    sort(v1.begin(), v1.end());
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    for (const auto& e : v1) {
        int ans = query(e.second);
        a[ans]++;
        update_s(e.second, 1);
    }
    int i;
    For(i,0,n-1){
        printf("%d\n",a[i]);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
