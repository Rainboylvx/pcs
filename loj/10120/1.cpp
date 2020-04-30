/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 04 Apr 2020 05:42:11 PM CST
* problem: loj-10120
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

/* ======== RMQ_BEG */
namespace RMQ_max {
    typedef long long ll; const int siz =30;
    ll N,f[maxn][siz];

    template <typename T> inline T BEST(T a,T b){ return a > b ? a : b;}
    /*预处理*/ void rmq_init(int size=maxn){N=size;}
    template<typename T> void rmq_init(T size, T a[]){ N=size;for(ll i=1;i<=N;i++) f[i][0] = a[i];}

    void st(){ /*范围*/for(ll j=1;(1<<j)<=N;j++) for(ll i=1;i+(1<<j)-1<=N;i++) f[i][j] = BEST(f[i][j-1],f[i+(1<<(j-1))][j-1]); }

    template<typename T>  //T k =0; while((1<<(k+1)) <= (r-l+1)) k++;
    T query(T l,T r){ T k = T(log(r-l+1)/log(2)); return BEST(f[l][k],f[r-(1<<k)+1][k]); }
}

namespace RMQ_min {
    typedef long long ll; const int siz =30;
    ll N,f[maxn][siz];
    template <typename T> inline T BEST(T a,T b){ return a < b ? a : b;}
    /*预处理*/ void rmq_init(int size=maxn){N=size;}
    template<typename T> void rmq_init(T size, T a[]){ N=size;for(ll i=1;i<=N;i++) f[i][0] = a[i];}

    void st(){ /*范围*/for(ll j=1;(1<<j)<=N;j++) for(ll i=1;i+(1<<j)-1<=N;i++) f[i][j] = BEST(f[i][j-1],f[i+(1<<(j-1))][j-1]); }

    template<typename T>  //T k =0; while((1<<(k+1)) <= (r-l+1)) k++;
    T query(T l,T r){ T k = T(log(r-l+1)/log(2)); return BEST(f[l][k],f[r-(1<<k)+1][k]); }
}

/* ======== RMQ_END */
int a[maxn];
void init(){
    scanf("%d%d",&n,&m);
    int i;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    RMQ_max::rmq_init(n, a);
    RMQ_min::rmq_init(n, a);
    RMQ_min::st();
    RMQ_max::st();
    For(i,1,n-m+1){
        printf("%d %d\n",RMQ_max::query(i, i+m-1),RMQ_min::query(i, i+m-1));
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
