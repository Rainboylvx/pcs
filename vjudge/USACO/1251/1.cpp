/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-05 18:09:46
*----------------*/
#define maxn 1000005
#define maxe 2000005
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//////// 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif


int n,m;
/* 定义全局变量 */

// int a[maxn]; //常用的一个数组 
ll a[maxn];
void init()
{
    cin >> n;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> a[i];
    }
}

//从start,开始查找到第一个 >=feer的下标
int find_first_le(int start,ll fee){
    int idx = start;
    for(int i = start;i <= n ;++i ) // i: start->n
    {
        if( a[i] < fee) continue;
        return i;
    }
    return n+1;
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    std::sort(a+1,a+1+n);
    ll ans = 0;
    ll fee;
    int idx = 1; //下标
    //枚举费用
    for(int i = 0;i <= 1e6 ;++i ) // i: 1->1e6
    {
        idx = find_first_le(idx,i);
        ll len = n-idx+1;
        ll t = len * (i);
        if( ans < t) {
            fee = i;
            ans = t;
        }
    }
    cout << ans << " " << fee;
    return 0;
}
