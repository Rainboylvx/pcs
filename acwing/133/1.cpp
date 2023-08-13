/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-22 07:51:15
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "data_structure/dynamic_array.hpp"
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

int n,m,root;
int q,u,v,t;
// int a[maxn];
dynamic_array<int> a;

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in.read(n,m,q,u,v,t);
    in >> YankArray(n) >> a;
    // out << a;
}


int main(){
#ifdef DEBUG
    // Clock t("main time");
#endif
    init();
    // operate m sec 
    while (m--) {
        int * pos = max_pos(a.begin(),a.end());
        // 对这个值就进操作
        // std::for_each(a.begin(),a.end(),[](int &n){ n+= q;});
        int val = *pos;
        out << "before: " << a;
        a.map([](int &n) { n+=q;});
        out << val;

        int left = val * u / v;
        int right = val - left;
        out << "left : " <<left << " right: " << right << "\n";
        out.ln();
        *pos = left;
        a.push(right);
        out << "after: " << a;
        out.ln();
        out.ln();
    }

    out.ln();
    std::sort(a.begin(),a.end(),std::greater<int>{});
    out << a;
    return 0;
}
