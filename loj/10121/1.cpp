/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 19日 星期二 23:45:59 CST
* problem: loj-10112
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 2e5+5;
const int maxe = 1e6+5;
int n,m;
int a[maxn],s[maxn],f[maxn];
map<int,int> last;

/* ======= 全局变量 END =======*/
/* ======== RMQ_BEG */
namespace RMQ_max {
    typedef long long ll; const int siz =30; ll N,f[maxn][siz];

    template <typename T> inline T BEST(T a,T b){ return a > b ? a : b;}
    /*预处理*/ void rmq_init(int size=maxn){N=size;}
    template<typename T> void rmq_init(T size, T a[]){ N=size;for(ll i=1;i<=N;i++) f[i][0] = a[i];}

    void st(){ /*范围*/for(ll j=1;(1<<j)<=N;j++) for(ll i=1;i+(1<<j)-1<=N;i++) f[i][j] = BEST(f[i][j-1],f[i+(1<<(j-1))][j-1]); }

    template<typename T>  //T k =0; while((1<<(k+1)) <= (r-l+1)) k++;
    T query(T l,T r){ T k = T(log(r-l+1)/log(2)); return BEST(f[l][k],f[r-(1<<k)+1][k]); }
}
/* ======== RMQ_END */
void init(){
    scanf("%d%d",&n,&m);
    int i,t;
    For(i,1,n){
        scanf("%d",&a[i]);
        s[i] = max(s[i-1],last[a[i]]+1);
        f[i] = i-s[i]+1;
        last[a[i]] = i;
    }
}

/* 使用: 首先定义EF::check函数 
 * EF::work(int l,int r)            二分
 * EF::work(double l,double r)      二分-double
 *
 * EF::work 区间[l,r) 内第一个不满足check()的位置
 *  if check(mid) => mid < key 则找到第一个 >=key 的位置 
 *  if check(mid) => mid <=key 则找到第一个 >key  的位置 
 *  核心思想:[l,r)是满足check的区间,不停缩小[l,r)
 * */
namespace EF {
    bool check(int mid,int start);    //函数声明
    int work(int l,int r){
        int start = l;
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid,start) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
}
bool EF::check(int mid,int start){
    return s[mid] <= start;
}

int work(int l,int r){
    int ans=0;
    int m = EF::work(l, r+1);
    if( m == r+1) ans = r-l+1;//printf("%d",r-l+1);
    else ans = max(RMQ_max::query(m, r),m-l);
    return ans;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //using namespace RMQ_max;
    RMQ_max::rmq_init(n, f);
    RMQ_max::st();
    int i;
    For(i,1,m){
        int l,r;
        scanf("%d%d",&l,&r);
        int ans = work(l+1, r+1);
        printf("%d\n",ans);
    }


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
