/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-03 22:58:52
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "math/bit.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp" // 分数类
// #include "graph/linkList.hpp"
// #include "chips/range.hpp"

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#endif
#define log(...)

//==== 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)

//====== 全局变量 =======

int n,m,root;
int gh[15][15];
int f[1<<12][15];// f[i_state][dep], 状态，深度

//====== 全局变量 =======

//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in(n,m);
    for(int i = 1;i <= m ;++i ) // i: 1->m
    {
        int u,v,w;
        in.read(u,v,w);
        u-=1; //因为我们所有的点都从0开始
        v-=1;
        
        gh[u][v] = w;
        gh[v][u] = w;
    }
    // 设定边界
    memset(f,inf,sizeof(f));
    for(int i = 0;i < n ;++i ) // i: 1->n
    {
        f[1<<i][0] = 0; // 只挖了第i个点，深度为0的最小值为0
    }
}

// 从一个集合里找到最小的值
int min_len(int k,int sets) {
    int len= 5e5+1;
    for(int i = 0 ;i < n ;i++) {
        if( bit_at_pos(sets,i) && gh[i][k])
        {
            if( len > gh[i][k])
                len = gh[i][k];
        }
    }
    return len;
}

int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    int final_state = (1<<n) - 1;
    //枚举深度
    int ans = INF;
    for(int i = 1;i<n;i++) 
    {
        //枚举状态
        for(int state = 1;state < (1<<n);state++)
        {
            // if( state == 0b0011){
            //     log(i,state);
            // }
            //枚举子集作为当前层
            for( auto sub_state: bit_sub_sets(state))
            {
                //子集的另一半
                int oth_sets = (sub_state ^ state) & final_state;
                if( !oth_sets) continue;

                // 子集找到值
                int sumL = 0;
                for(int j = 0;j < n;j++) {
                    if( bit_at_pos(sub_state,j) == 0) continue;
                    // int len = min_len(j,oth_sets);
                    // if( len == inf) // 没有找到
                    sumL += min_len(j,oth_sets);
                }

                f[state][i] = std::min(
                    f[state][i],
                    f[oth_sets][i-1] + sumL * i
                );
                // if( sub_state == 0b0010 )
                // {
                //     log(i,state,sub_state,oth_sets);
                //     log(f[state][i]);
                // }
                if( state == (1<<n)-1 && ans > f[state][i])
                    ans = f[state][i] ;
            }
        }

    }
    log(f[0b0001][0]);
    log(f[0b0011][1]);
    log(f[0b1011][1]);
    out << ans;
    return 0;
}
