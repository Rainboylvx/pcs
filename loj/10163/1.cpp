/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 27日 星期三 10:05:57 CST
* problem: loj-10163
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
int n,m;
int K,B;
int a[100];

int tobase(int n){
    int k = 0;
    while( n >= B ) a[++k] = n % B, n /= B;
    a[++k] = n;
    //reverse(a+1, a+1+k);
    if( B != 2){
        int i;
        for(i = k;i>=1;--i) if( a[k] !=0 && a[k] != 1) break;
        for(;i>=1;--i) a[i] = 1;
    }
    return k;
}

/* ======= 全局变量 END =======*/
ll f[40][40];
void init(){
    scanf("%d%d",&n,&m);
    scanf("%d%d",&K,&B);
    int i,j,k;
    f[1][0]=1;
    for(i=2;i<=31;++i){
        //f[i][0] = f[i-1][0];
        f[i][0] = 1;
        for(j=1;j<=i;j++)
            f[i][j] = f[i-1][j] +f[i-1][j-1];
    }
}

ll solve(int n){
    int i,j,k;
    int len = tobase(n); // n = 1101
    len++; a[len] = 0;
    ll ret = 0;
    int cnt = 0; // 走了几个1
    for(i = len;i>=1;i--){
        if( a[i] == 1) cnt++;
        if( a[i-1] == 1)
            ret+=f[i-1][K-cnt];
        if( cnt == K) break;
    }
    if( i == 1 && cnt == K)
        ret++;
    return ret;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    ll ans1 = solve(m);
    ll ans2  = solve(n-1);
    printf("%lld\n",ans1-ans2);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
