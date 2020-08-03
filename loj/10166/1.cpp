/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 29日 星期五 23:22:05 CST
* problem: loj-10166
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
int a,b,N;

namespace DIGIT_DP {
    typedef long long ll;
    ll f[30][10][200],a[100];
    // pre 前面加起来mod 位
    ll dfs(int pos,int pre,int n,bool lead,bool eq){
        if( pos == 0 ) {
            if( n == 0) return 1;
            else return 0;
        }
        if( !eq && f[pos][pre][n] !=-1) return f[pos][pre][n];
        ll ret = 0;
        int ed = eq ? a[pos] : 9;
        for(int i = 0;i<= ed ; i++){
            ret += dfs(pos-1,i,((n+N-i%N)+N) % N,lead && i == 0 ,eq && i == ed);
        }
        if( !eq )f[pos][pre][n] = ret;
        return ret;
    }

    ll solve(int n){
        if( n==0) return 1;
        ll k = 0;ll sum=0;
        while( n) a[++k] = n%10,sum+=n%10,n/=10;
        memset(f,-1,sizeof(f));
        ll ans = dfs(k,0,0,1,1);
        //if( sum % N == 0) ans++;
        return ans;
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while( scanf("%d%d%d",&a,&b,&N) != EOF){
        ll ans1 = DIGIT_DP::solve(b) ;
        ll ans2 = DIGIT_DP::solve(a-1) ;
        printf("%lld\n",ans1-ans2);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
