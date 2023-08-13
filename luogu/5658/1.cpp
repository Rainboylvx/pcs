/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-08-07 07:19:51
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e6
#include "base.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp" // 分数类
#include "graph/linkList.hpp"
#include "data_structure/stack.hpp"
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
graph_nw gh;
std::string str;
int pair_cnt[maxn]; //以第i个字符为结尾的同级的括号对的数量
stack<int> sta; //记录前面的哪个位置是 '('
// long long ans[maxn]; //记录每个点的合法括号串的数量
long long ans[maxn]; //记录每个点的合法括号串的数量

int fa[maxn]; //记录每个点的父亲

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    std::cin >> n;
    std::cin >> str;
    for(int i = 2;i <= n ;++i ) // i: 1->n
    {
        int t;
        std::cin >> t;
        gh.add(i,t);
        fa[i] = t;
    }
}

//对树进行遍历
void dfs(int u,int parent){
    long long now_ans=0;
    int poped = -1; //记录pop的数据,pop的数据最后需要还原
                    // poped == -1 表示没有弹出数据

    bool pushed = 0; //是否向sta里push

    // 进行操作
    if( str[u-1] == '(')
    {
        now_ans = ans[parent];
        pushed = true;
        sta.push(u);
    }
    else // is )
    {
        if( sta.empty() || sta.top() == -1) // 不能配对
        {
            now_ans = ans[parent];
            sta.push(-1); // 截断sta,不让后面的使用
            pushed = 1; //记录,压栈
            pair_cnt[u] = 0;
        }
        else { // 可以配对
            poped = sta.top();
            sta.pop();
            now_ans = ans[parent]+1;
            now_ans += pair_cnt[fa[poped]];
            pair_cnt[u] = pair_cnt[fa[poped]] + 1;
        }
    }
    ans[u] = now_ans;
    
    for(auto v : gh.start_from_head(u)){
        if( v == parent) continue;
        dfs(v,u);
    }

    if( poped != -1)
        sta.push(poped);

    if( pushed)
        sta.pop();

}


int main(){
#ifdef DEBUG
    // Clock t("main time");
#endif
    init();
    dfs(1,0);
    long long a = 0;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
#ifdef DEBUG
        std::cout << i << " : " << ans[i] << "\n";
#endif
        long long t = i;
        a = a ^ ( t * ans[i]);
    }
    std::cout << a;
    return 0;
}
