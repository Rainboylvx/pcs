/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 19日 星期二 18:06:14 CST
* problem: loj-133
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

/* 二维BIT  BIT_2D */
/* 核心在于 C[x][y] 管辖的范围*/
namespace BIT_2D {
    //横管横，纵管纵
    typedef long long ll;
    const int MAXN = 4100;
    int SIZE_N = 4100;
    int SIZE_M = 4100;
    ll a[MAXN][MAXN],c[MAXN][MAXN];
    inline int lowbit(int x){ return x&-x;}
    void update(int x,int y,int val){
        for(int i=x;i <=SIZE_N;i += lowbit(i))
            for(int j=y;j <=SIZE_M;j += lowbit(j))
                c[i][j] += val;
    }
    ll query(int x,int y){
        ll sum =0;
        for( int i = x;i>0; i -= lowbit(i))
            for(int j = y ;j >0;j-=lowbit(j))
                sum += c[i][j];
        return sum;
    }
    ll query_sub_martix(int x1,int y1,int x2,int y2){ return query(x2, y2) - query(x2, y1-1) - query(x1-1,y2) + query(x1-1, y1-1); }
}
void init(){
    scanf("%d%d",&n,&m);
    using namespace BIT_2D;
    SIZE_N = n,SIZE_M=m;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    using namespace BIT_2D;
    int t,x1,y1,x2,y2,o;
    while(scanf("%d",&t) != EOF){
        if( t == 1){
            scanf("%d%d%d",&x1,&y1,&o);
            update(x1,y1,o);
        }
        else {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            ll ans = query_sub_martix(x1, y1, x2, y2);
            printf("%lld\n",ans);
        }
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
