/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 06月 01日 星期一 10:15:36 CST
* problem: loj-10169
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;
template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch < '0' || ch > '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
ll n,m;

/* ======= 全局变量 END =======*/
void init(){
    read(n);
    read(m);
}

namespace DIGIT_DP {
    int a[30];
    struct _f{ll f,cnt;} f[30][10];
    ll K = 0;
    _f dfs(int pos,int pre,bool lead,bool eq){
        if( pos == 0) return {pre==K,1}; 
        if( !lead && !eq && f[pos][pre].f !=-1) return f[pos][pre];
        int ed = eq ? a[pos] : 9;
        _f ret = {0,0};
        for(int i =0;i<=ed;i++){
            _f r =  dfs(pos-1,i,lead && i == 0,eq && i == ed);
            ret.cnt += r.cnt;
            ret.f += r.f;
            if(pre == K && pre !=0){
                ret.f +=r.cnt;
            }
            else if( pre == K && pre == 0 && !lead){
                ret.f +=r.cnt;
            }
        }
        if( !lead && !eq ) f[pos][pre] = ret;
        return ret;
    }
    _f solve(ll n,int x){
        K = x;
        int k=0;
        while( n ) a[++k] = n % 10,n/=10;
        memset(f,-1,sizeof(f));
        return dfs(k,0,1,1);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    using namespace DIGIT_DP;
    for(int i=0;i<=9;i++){
    //int i=1;
        ll ans = solve(m,i).f-solve(n-1,i).f;
        printf("%lld ",ans);
    }
    printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
