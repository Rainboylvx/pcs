/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 29日 星期五 15:33:19 CST
* problem: loj-10165
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
int num[20];
ll f[20][20];

/* ======= 全局变量 END =======*/
void init(){
    read(n);read(m);
}

ll dfs(int pos,int pre,bool lead,bool eq){
    if( pos == 0) return 1; //边界
    if( !lead && !eq && f[pos][pre] !=-1 ) return f[pos][pre];
    int ed = eq ? num[pos] : 9;
    ll cnt = 0;
    for(int i = 0;i<=ed;i++ ){
        if( lead ){
            cnt += dfs(pos-1,i,lead && i==0,eq && i == ed);
        }
        else {
            if( abs(i-pre) < 2) continue;
            cnt += dfs(pos-1,i,lead && i == 0, eq && i == ed);
        }
    }
    if( !lead && !eq ) f[pos][pre] = cnt;
    return cnt;
}
ll solve(int a){
    num[0] = 0;
    while( a ) num[++num[0]] = a % 10, a/=10;
    memset(f,-1,sizeof(f));
    return dfs(num[0],0,1,1);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    ll a = solve(m);
    ll b = solve(n-1);
    ll ans = a -b;
    printf("%lld\n",ans);
    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
