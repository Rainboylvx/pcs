/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-12 15:57:47
* if you want to compile this code , please visit 👉 https://github.com/RainboyNoip/algorithms
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp" // 分数类
// #include "graph/linkList.hpp"
// #include "chips/range.hpp"

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp" 
#endif

//==== 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)

//====== 全局变量 =======
using ll = long long;
int n,m,root;
int a[maxn];
ll f[maxn];

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in.read(n);
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        in.read(a[i]);
    }
}


int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    f[1] = a[1] *a[1];
    ll ans = f[1];
    ll pre_sum = a[1];
    ll pre_min = a[1];
    for(int i = 2;i <= n ;++i ) // i: 2->n
    {
        ll t = a[i] *ll(a[i]);
        ll t2 = (a[i]+pre_sum) * std::min(ll(a[i]),pre_min);
        if( t > t2 ) {
            f[i] = t;
            pre_sum = a[i];
            pre_min = a[i];
        }
        else {
            f[i] = t2;
            pre_sum += a[i];
            pre_min = std::min(ll(a[i]),pre_min);
        }
        if( ans < f[i])
            ans = f[i];
    }
    out << ans;
    return 0;
}
