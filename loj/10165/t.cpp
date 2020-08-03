/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 29日 星期五 17:26:58 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

//数位dp模板
namespace DIGIT_DP{
    typedef long long ll;
    ll f[30][30],a[100];
    ll dfs(int pos,int pre,bool lead,bool eq){
        if(pos == 0) return 1; //边界
        if(!lead && !eq ) return f[pos][pre];
        ll ret = 0;
        int ed = eq ? a[pos]: 9; //能取到的最大值
        for(int i = 0 ;i<= ed ;++i){
            if( (!i) )
        }
        return ret;
    }
    ll solve(int n){
        ll k = 0;
        while( n) a[++k] = n%10,n/=10;
        memset(f,-1,sizeof(f));
        return dfs()
    }
}

int main(){

    return 0;
}
