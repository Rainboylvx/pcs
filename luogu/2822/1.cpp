/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-25 09:14:20
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

int n,m,root;
int t,k;
// int a[maxn];

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in(t,k);
    
}


//求阶乘
int jc(int n){
    if (n==0) {
        return  1;
    }
    int s = 1;
    F(n){
        s *= i;
    }
    return s;
}


int main(){
#ifdef DEBUG
    Clock __t("main time");
#endif
    // init();
    in.read(t,k);
    F(t){
        int cnt = 0;
        in.read(n,m);
        log(n,m);
        F3( ii , 0 , n){
            F3( jj , 0 , m){
                if( jj > ii) continue;
                int tt = jc(ii) /jc(jj) / jc(ii-jj);
                if( tt % k == 0) {
                    log(ii,jj,tt,tt%k);
                }

                if( tt % k == 0)
                    cnt++;
            }
        }
        out<< cnt;
        out.ln();
    }
    return 0;
}
