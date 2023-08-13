/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-07 10:21:09
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "chips/piece.hpp"
#include "utils/random/tree.hpp"
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
// int a[maxn];

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in(n,m);
    
}


int main(){
#ifdef DEBUG
    // Clock t("main time");
#endif
    init();
    int tree_size = 5;
    __random::tree mytree(tree_size);
    std::cout << tree_size<<"\n";
    char quote[] = {'(',')'};
    for(int i = 1;i <= tree_size ;++i ) // i: 1->n
    {
        std::cout << quote[RND(0,1)];
    }
    std::cout << "\n";
    for( auto [fa,ch] : mytree)
    {
        std::cout << fa << " ";
    }
    return 0;
}
