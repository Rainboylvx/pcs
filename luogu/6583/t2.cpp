/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 07月 24日 星期五 14:42:29 CST
* problem: luogu-6583
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
ll rongchi(ll a,ll b,ll c){ //三集合容斥
    if( a == 1) {
        return n / b + n /c - n/(b*c);
    }
    return n / a + n /b + n /c -n/(a*b) - n / ( a * c) - n/(b *c) + n/ (a*c*b);
}
void init(){
    scanf("%lld",&n);
    ll ans = 0;
    ll i ,j;
    for( i =1;i<=n;i++){
        int k = i;
        if( k %2 == 0 || k % 5 == 0){
            while( k % 2 == 0) k/=2;
            while( k % 5 == 0) k/=5;
        }

        {
            ll a = rongchi(k,2,5);
            //printf("%d: %d %d\n",i,k,a);
            ans = ans + a + 1;
            printf("%lld %lld\n",i,a+1);
        }
    }
    printf("%lld\n",ans);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
