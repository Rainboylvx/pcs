/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-18 20:47:18
*----------------*/
#define __maxn__ 3e5
#define __maxe__ 6e5
#include <bits/stdc++.h>
#include "graph/linkList.hpp"
#include "graph/lca_craw.hpp" // 爬树法求lca
#include "data_structure/adjacencyList.hpp"
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

int w[maxn]; //每个点的观察值
int bucket_1[maxn<<1]; // 🪣1 记录 dep[s] ,w[a]
int bucket_2[maxn<<1]; // 🪣2 记录 len(s,t) - dep[t] + n ,w[a]-dep[a] +n
int bucket_3[maxn<<1]; // 🪣3 记录可以同时观察到 s,t的点能观察到的数量


graph_nw tree; //存树
lca_craw<CALC_LEN> lca; //求lca
int ans[maxn]; //记录答案
struct _edge {int s,t,len;};
adjacencyList<_edge> people; // 跑步的人
adjacencyList<int> lca_list; //以为lca头, people上边编号的为数据


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
        people.push(s,{s,t,int(len)});
        int id = people.size()-1;
        people.push(t,{t,s,int(len)});
        lca_list.push(_lca,id);
        //记录以a为lca的边编号
        /* if( 2* w[_lca] == lca.dep[s] - lca.dep[t] + len) */
        if( w[_lca] == lca.dep[s] - lca.dep[_lca] )
        {
            bucket_3[_lca]++;
        }
    }
}

//通过dfs 进行统计
void dfs_cnt(int u,int fa,int dep) {

    //已经有的信息,给去除
    ans[u] -= bucket_1[ w[u] + lca.dep[u] ] + bucket_2[w[u]-lca.dep[u]+n];

    for(auto &v : tree.edges_start_for(u))
    {
        if( v == fa ) continue;
        dfs_cnt(v,u,dep+1);
    }


    //进行记录

    //从u开始的起点的边的数量
    /* for( auto &v : people.edges_start_for(u) )  */
    for(int i = people.head(u) ; ~i ; i = people.next(i))
        if( (i  & 1) == 0 ) //这条边是正向的,也就是以u为起点的
            bucket_1[dep]++;
        else { // 这条边是反向的,也就是以u为终点
            int len = people[i].len;
            bucket_2[len-dep+n]++;
        }
    ans[u] += bucket_1[ w[u] + lca.dep[u] ] + bucket_2[w[u]-lca.dep[u]+n];
    ans[u] -= bucket_3[u];

    //退出这个点,反记录信息
    //找到这个点为lca的点的边
    for( auto idx : lca_list.start_from_head(u)) {
        int s = people[idx].s;
        int t = people[idx].t;
        int len = people[idx].len;
        bucket_1[lca.dep[s]]--;
        bucket_2[len-lca.dep[t]+n]--;
    }
}



int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    dfs_cnt(1,0,1);
    ans >> YankArray(n) >> out;

    return 0;
}
