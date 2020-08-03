/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 29日 星期五 13:36:29 CST
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
ll f[20][20];
ll sum[20];

/* ======= 全局变量 END =======*/
void init(){
    int i,j,k;
    for(i=0;i<=9;++i) f[1][i] = 1;
    sum[1] = 10;
    for(i=2;i<=10;++i){
        for(j=0;j<=9;++j){
            for(k=0;k<=9;k++){
                if(abs(k-j) >=2){
                    f[i][j] += f[i-1][k];
                }
            }
            sum[i] += f[i][j];
        }

    }
    read(n);read(m);
}

int num[100];
bool check(){
    if( num[0] == 0) return 0;
    if( num[0] <= 1) return 1;
    for(int i=num[0]-1;i>=1;i--){
        if( abs(num[i]-num[i+1]) < 2) return 0;
    }
    return 1;
}
ll calc(ll a){
    if(  a == 0) return 1;
    num[0] = 0;
    while( a ) num[++num[0]] = a % 10,a/=10;
    int i,j,k;
    ll ans = 0;
    for( i =1;i< num[0] ;i++)
        ans += sum[i] -f[i][0];
    ans++;
    //最高位
    for(i=1;i< num[num[0]];i++)
        ans+= f[num[0]][i];
    for(i=num[0]-1;i>=1;i--){
        for(j=0;j<=num[i]-1;j++)
            if( abs(j-num[i+1]) >=2)
                ans+=f[i][j];
        if(abs(num[i+1] - num[i]) < 2) break;
    }
    if( i == 0) ans++;
    return ans;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    ll ans = calc(m)-calc(n-1);
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
