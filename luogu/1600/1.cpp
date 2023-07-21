/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-18 20:47:18
*----------------*/
#define maxn 200005
#include <bits/stdc++.h>
#include "graph/linkList.hpp"
#include "graph/lca_craw.hpp" // 爬树法求lca
using namespace std;
typedef long long ll;
/* const int maxn = 2e5+5,maxe = 1e6+5; //点与边的数量 */

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

// int a[maxn]; //常用的一个数组 

int w[maxn];
int bucket_1[maxn<<1]; // 🪣1 记录 dep[s]
int bucket_2[maxn<<1]; // 🪣2 记录 len(s,t) - dep[t] + n
int bucket_3[maxn<<1]; // 🪣3 记录 2 w_a = dep[s] - dep[t] + len(s,t)


graph_nw tree; //存树
graph people; // 跑步的人
lca_craw<CALC_LEN> lca; //求lca
int record_lca[maxe]; //记录s,t 的lca
int ans[maxn]; //记录答案


void init()
{
    in.read(n,m);
    F(n-1){
        in >> tree;
    }
    /* out.print(tree.get_edge_cnt()); */
    in >> YankArray(n) >> w;
    /* w >> YankArray(n) >> out; */

    lca.init(tree,1); //初始化,lca
    F(m){
        int s,t;
        in.read(s,t);
        //求出s,t 的长度与lca
        auto [_lca,len] = lca.find(s,t);
        people.add(s,t,len);
        int id = people.last_edge_idx();
        record_lca[id] = _lca; //根据编号记录 lca的值
        record_lca[id^1] = _lca;

        //暴力统计,
        int os = s,ot = t;
        int time = 0;
        while( lca.dep[s] >= lca.dep[_lca]) {
            if(time == w[s] )
                ans[s]++;
            time++;
            s = lca.f[s][0]; //变成父亲
        }
        while( lca.dep[t] > lca.dep[_lca]) {
            if(w[t] == lca.dep[t] - lca.dep[ot] + len  ) {
                ans[t]++;
            }
            t = lca.f[t][0];
        }
    }
}



int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    //暴力统计,测试用
    ans >> YankArray(n) >> out;
    return 0;
}
