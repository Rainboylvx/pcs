/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 30日 星期六 07:47:40 CST
* problem: loj-10167
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

/* ======= 全局变量 END =======*/

namespace DIGIT_DP {
    typedef long long ll;
    ll f[30][30],a[100];

    ll dfs(int pos,int pre,bool eq){
        if( pre == 4) return 0;
        if( pos == 0) return 1;
        if( !eq && f[pos][pre] !=-1) return f[pos][pre];

        int ed = eq ? a[pos] : 9;
        int ret = 0;
        for(int i=0;i<=ed;i++){
            if( i == 2 && pre == 6)
                ;
            else 
                ret += dfs(pos-1,i,eq && i == ed);
        }
        if( !eq ) f[pos][pre] = ret;
        return ret;
    }
    ll solve(int n){
        int k = 0;
        while(n) a[++k] = n%10,n/=10;
        memset(f,-1,sizeof(f));
        return dfs(k,0,1);
    }
    
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while( scanf("%d%d",&n,&m)){
        if( n == 0 && m == 0) return 0;
        using namespace DIGIT_DP;
        ll ans = solve(m)-solve(n-1);
        printf("%lld\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
