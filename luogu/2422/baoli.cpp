/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-12 15:51:21
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

int a[maxn]; //常用的一个数组
ll ans;

ll query(int l,int r) {
    ll _min = 1e6+1;
    ll _sum = 0;
    for(int i = l;i <= r ;++i ) // i: l->r
    {
        if( _min > a[i]) _min = a[i];
        _sum += a[i];
    }
    return _sum * _min;
}

void init()
{
    cin >> n;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> a[i];
    }
}

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    //暴力枚举
    for(int i = 1;i <= n ;++i ) // i: 1->n 长度
    {
        for(int j = i;j<=n;j++)
        {
            ll t = query(j-i+1,j);
            if( ans < t) {
                ans = t;
#ifdef DEBUG
                cout << ans << ": { " << j-i+1 << " , " << j<< " }" << endl;
#endif
            }
        }
    }
#ifdef DEBUG
    cout << "ans :" ;
#endif
    cout << ans << "\n";
    return 0;
}
