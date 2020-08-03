/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 28日 星期四 15:31:04 CST
* problem: loj-10164
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
ll f[20][20];
ll num[100];

/* ======= 全局变量 END =======*/

// 第pos个位置
// 前一个选s,eq 相等
ll dfs(int pos,int s,bool eq){
    if(pos == 0) return 1;
    int res = 0;

    int ed = eq ? num[pos] : 9;
    for(int i = s;i<=ed;i++){
        res += dfs(pos-1,i, eq && i == ed);
    }

    return res;
}

ll solve(ll a){
    memset(f,0,sizeof(f));
    num[0] = 0;
    while (a) {
        num[++num[0]] = a%10;
        a /=10;
    }
    return dfs(num[0],0,1);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while ( scanf("%lld%lld",&n,&m) !=EOF) {
        ll ans = solve(m)-solve(n-1);
        printf("%lld\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
