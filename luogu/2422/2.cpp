/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-12 15:57:47
* if you want to compile this code , please visit 👉 https://github.com/RainboyNoip/algorithms
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "data_structure/stack.hpp"

// #include "chips/piece.hpp"
// #include "math/fraction.hpp" // 分数类
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
ll a[maxn];
ll sum[maxn]; //sum[i],considering a[i] as minimum value, obtained by extending
            // the left and right sides

struct node {
    ll sum;
    ll min;
};

stack<node> sta;

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
    // ll ans = a[1] * a[1];

    //step 1. get left sum
    sta.emplace(a[1],a[1]);
    sum[1] += a[1];
    for(int i = 2;i <= n ;++i ) // i: 2->n
    {

        ll s = a[i];

        while( !sta.empty() && sta.top().min >= a[i])
        {
            s += sta.top().sum;
            sta.pop();
        }
        sta.emplace(s,a[i]);
        sum[i] += s;
    }

    //step2. get right sum
    sta.clear();
    sta.emplace(a[n],a[n]);
    sum[n] += a[n];
    for(int i=n-1;i>=1;i--){
        ll s = a[i];

        while( !sta.empty() && sta.top().min >= a[i])
        {
            s += sta.top().sum;
            sta.pop();
        }
        sta.emplace(s,a[i]);
        sum[i] += s;
    }

    // step3. calc the ans
    ll ans = 0;
    for(int i =1;i<=n;i++){
        sum[i] -= a[i]; // sub the extra add
        ll t = sum[i] * a[i];
        if( ans < t)
            ans = t;
    }


    out << ans;
    return 0;
}
