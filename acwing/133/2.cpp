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
long long flag;

int main(){
#ifdef DEBUG
    // Clock t("main time");
#endif
    init();
    // operate m sec 
    while (m--) {
        int * pos = max_pos(a.begin(),a.end()); //先找到一个最大的值
        int val = *pos; //这个最大值是
        val += flag; //加入flag, 得到这个最大的val的真正的值
        out << val;
        flag += q; // 更新flag

        { // 把这个数放进去
            int left = val * u / v;
            int right = val - left;
            *pos = left-flag; // 现在每一个元素,都加上flag,所以现在应该去除
                            //添加的这个值,不应该+flag,所以去除flag
            a.push(right-flag);
        }
        // out.ln();
    }

    out.ln();
    std::sort(a.begin(),a.end(),std::greater<int>{});
    a.map([](int n) { 
        out.print(n+flag);
    });

    return 0;
}
