/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 04 Apr 2020 05:12:00 PM CST
* problem: loj-10119
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
namespace RMQ {
    typedef long long ll; const int siz =50;
    ll N;
    ll f[maxn][siz];
    /*预处理*/
    void rmq_init(int size=maxn){N=size;}
    template<typename T>
    void st(T len,T a[]){
        for(ll i=1;i<=N;i++) f[i][0] = a[i];
        for(ll j=1;(1<<j)<=N;j++) //范围
            for(ll i=1;i+(1<<j)-1<=N;i++)
                f[i][j] = std::max(f[i][j-1],f[i+(1<<(j-1))][j-1]);

    }
    template<typename T>
    T query(T l,T r){
        T k = T(log(r-l+1)/log(2));
        //T k =0; while((1<<(k+1)) <= (r-l+1)) k++;
        return std::max(f[l][k],f[r-(1<<k)+1][k]);
    }
}
using namespace RMQ;
int a[maxn];
void init(){
    scanf("%d%d",&n,&m);
    rmq_init(n);
    int i,x,y;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    st(n, a);
    For(i,1,m){
        scanf("%d%d",&x,&y);
        printf("%d\n",query(x,y));
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
