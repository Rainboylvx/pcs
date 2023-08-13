/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-03 22:58:52
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "data_structure/bit.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp" // 分数类
// #include "graph/linkList.hpp"
// #include "chips/range.hpp"

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif

//==== 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)

//====== 全局变量 =======

int n,m,root;
int gh[15][15];
int f[1<<12][15];// f[i_state][dep], 状态，深度

//预处理1:
unsigned int gs[1<<12]; // 由s0 集合出发的边,得到的点的集合

//预处理1:
int dis[1<<12][15]; // dis[s][i],点i到集合s的最小距离
//====== 全局变量 =======

//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in(n,m);
    memset(f,inf,sizeof(f)); //
    memset(dis,inf,sizeof(dis));
    memset(gh,inf,sizeof(gh));
    for(int i = 1;i <= m ;++i ) // i: 1->m
    {
        int u,v,w;
        in.read(u,v,w);
        u-=1; //因为我们所有的点都从0开始
        v-=1; //所以需要减少1
        
        //注意这里,可能重边,这里取最小的边
        gh[u][v] = gh[v][u] = std::min(gh[v][u],w);
    }
    // 设定边界
    memset(f,inf,sizeof(f));
    for(int i = 0;i < n ;++i ) // i: 1->n
    {
        f[1<<i][0] = 0; // 只挖了第i个点，深度为0的最小值为0
    }

    // 求gs集合
    for(int i = 1; i <  (1<<n);i++) // 枚举 s0集合
    {
        Bit s0(i);
        for(int j = 0;j<n;j++) { //枚举s0中的每个点
            if( s0.at(j)  == 0) continue; //没有这个点
            for(int k = 0 ;k<n;k++){ // 枚举另外的点
                if( s0.at(k) ) continue;//k点存在s0上
                if( gh[j][k] != inf ) { //边存在
                    auto x = Bit(gs[i]).set(k);
                    gs[i] = x;
                }
            }
        }
    }
    // 求dis[s][i]
    for(int i =1;i< (1<<n);i++) {
        Bit s(i);
        for(int j =0 ;j < n;j++ ) // j 是 s中的点
        {
            if( s.at(j) ==  0) continue;
            for(int k =0 ;k < n;k++ ) // 枚举 另一个点k
            {
                if( k == j) continue;
                if( s.at(k) ) continue; // k在s中
                // dis[s][k] = std::min(dis[s][k],gh[j][k]);
                dis[i][k] = std::min(dis[i][k],gh[j][k]);
            }
        }
    }
}

int get_len_sum(int s0,int sx) {
    int sum = 0;
    // auto s = Bit(s0);
    auto _sx = Bit(sx);
    for(int i = 0;i<n;i++) {
        if( _sx.at(i) == 0) continue;
        if( dis[s0][i] == inf)
            return -1; //表示有不存在的边
        sum += dis[s0][i];
    }
    return sum;
}

int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    //特殊判断,没有点的时候,输出0
    //luogu的51这个数据点是0,但是不符合题意,题目 n >= 1
    if( n== 0 || n == 1) {
        out << 0;
        return 0;
    }
    int final_state = (1<<n) - 1;
    int ans = inf;
    log(f[0b01][0]);
    log(f[0b10][0]);

    //枚举 层
    for(int i =1 ; i < n;i++) {
        //枚举 当前状态
        for(int state = 1;state <= final_state ;state++) {
            //子集枚举,得到s0
            auto s1 = Bit(state);
            for(unsigned int s0: s1.sub_sets())
            {
                //真正第第i层的点sx
                int sx = s1.complement_set(s0);
                if( sx == 0) continue; //sx 没有点
                if( Bit( gs[s0] ).is_sub(sx) ) { // 如果sx是s0出发的边形成的点集的子集
                    //求出sx 到s0 的最小边的值
                    int sum = get_len_sum(s0, sx);
                    if( sum == -1) continue; // 存在不合法的边,就是没有边
                    f[state][i] = std::min(
                            f[state][i],
                            f[s0][i-1] + sum * i);
                    if( state == final_state && ans > f[state][i])
                    {
                        ans = f[state][i];
                    }
                }
            }
        }
    }
    log(f[0b11][1]);

    out << ans;
    return 0;
}
