/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 28日 星期四 14:45:51 CST
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
ll n,m;
ll f[20][20];
vector<int>   vn,vm;

/* ======= 全局变量 END =======*/
void init(){
    int i,j,k;
    For(i,0,9){
        f[1][i] = 1;
    }
    For(i,1,10){
        For(j,0,9){
            For(k,j,9){
                f[i][j] += f[i-1][k];
            }
        }
    }
    //For(i,0,9){
        //printf("%lld ",f[2][i]);
    //}
    //printf("\n");
    //For(i,0,9){
        //printf("%lld ",f[3][i]);
    //}
    //printf("\n");
}


ll find(vector<int> vn){
    int i,j;
    ll ans = 0;
    int pre =0;
    for(i = vn.size()-1;i>=0;--i){
        if( vn[i] < pre) break;
        for(j=pre;j<vn[i];j++)
            ans+=f[i+1][j];
        pre = vn[i];
    }
    if( i == -1) ans++;
    return ans;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    while (scanf("%lld%lld",&n,&m) !=EOF) {
        n-=1;
        vn.clear();vm.clear();
        while( n ){
            vn.push_back(n%10);
            n/=10;
        }
        while( m ){
            vm.push_back(m%10);
            m/=10;
        }
        ll ans = find(vm) - find(vn);
        printf("%lld\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
