/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-20 10:51:34
*----------------*/

#define __maxn__ 2e5
#define __maxe__ 4e5
#include "base.hpp"
#include "graph/heavy_light_decomposition.hpp"
#include "graph/lca_craw.hpp" // 爬树法求lca
#include "data_structure/adjacencyList.hpp"
/* #include "chips/piece.hpp" */
/* #include "math/fraction.hpp" // 分数类 */
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

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======

heavy_light_son_decomposition hls;

//数据读取 
inline void init() {
    in(n,m);
    F(n-1){
        in >> tree;
    }
    in >> YankArray(n) >> w;
    lca.init(tree,1); //初始化,lca
    F(m){
        int s,t;
        in.read(s,t);
        //求出s,t 的长度与lca
        auto [_lca,len] = lca.find(s,t);
        people.push(s,{s,t,int(len)});
        int id = people.size()-1;
        people.push(t,{t,s,int(len)});
        //记录以a为lca的边编号
        lca_list.push(_lca,id);
        if( w[_lca] == lca.dep[s] - lca.dep[_lca] )
            bucket_3[_lca]++; //bucket_3 表示 点u可以同时观察
                            //到下面的s,t的数量
    }
}

//>>>>>>>>>>>>>>>>>>>>>> dsu_on_tree
namespace  dsu_on_tree {
auto & e = tree;
int flag_hson;
int start_u;

//统计节点u下面的统计信息
void calc_info(int u,int parent) {
    //统计
    int dep  =lca.dep[u];
    for(int i = people.head(u) ; ~i ; i = people.next(i))
        if( (i  & 1) == 0 ) //这条边是正向的,也就是以u为起点的
            bucket_1[dep]++;
        else { // 这条边是反向的,也就是以u为终点
            int len = people[i].len;
            bucket_2[len-dep+n]++;
        }

    for(auto &v : tree.edges_start_for(u))
    {
        if( v == parent || v == flag_hson ) continue;
        calc_info(v,u);
    }

    //从一个点退出时,如果这个是lca 删除
    if( start_u != u) {

        for( auto idx : lca_list.start_from_head(u)) {
            int s = people[idx].s;
            int t = people[idx].t;
            int len = people[idx].len;
            bucket_1[lca.dep[s]]--;
            bucket_2[len-lca.dep[t]+n]--;
        }
    }
}

//删除节点u下面的统计信息
void del_info(int u,int parent) {
    //统计
    int dep  =lca.dep[u];
    for(int i = people.head(u) ; ~i ; i = people.next(i))
        if( (i  & 1) == 0 ) //这条边是正向的,也就是以u为起点的
            bucket_1[dep]--;
        else { // 这条边是反向的,也就是以u为终点
            int len = people[i].len;
            bucket_2[len-dep+n]--;
        }

    for(auto &v : tree.edges_start_for(u))
    {
        if( v == parent || v == flag_hson ) continue;
        del_info(v,u);
    }

    //从一个点退出时,如果这个是lca 删除
    for( auto idx : lca_list.start_from_head(u)) {
        int s = people[idx].s;
        int t = people[idx].t;
        int len = people[idx].len;
        bucket_1[lca.dep[s]]++;
        bucket_2[len-lca.dep[t]+n]++;
    }

}

void dfs(int u,int parent,bool keep)
{
    //1. 遍历轻儿子
    for(int i = e.head(u) ; ~i ;i = e.next(i)) {
        int v = e[i].v;
        if( v == parent || v==hls.hson(u) ) continue;
        dfs(v,u,false);
    }
    //2. 遍历轻儿子
    if( hls.hson(u) ) { //hson 存在
        dfs(hls.hson(u),u,true);
        flag_hson = hls.hson(u);
    }
    // 3. 暴力统计u,和u的轻儿子子树的贡献
    start_u = u;
    calc_info(u,parent);
    flag_hson = 0; //删除儿子标记
    start_u = 0;

    //统计信息
    ans[u] = bucket_1[ w[u]+lca.dep[u] ];
    ans[u] += bucket_2[ w[u]-lca.dep[u]+n ];
    ans[u] -= bucket_3[u];

    if( !keep) {
        // 从u回溯,删除子树上的所有点的贡献
        //! 会把记录信息的数组清零
        del_info(u,parent);
        // 清空 必须放这里,想一想,只有重儿子的情况
        // max_color_sum = max_color_cnt = 0;
    }
}

} // end namespace dsu_on_tree
//<<<<<<<<<<<<<<<<<<<<<< dsu_on_tree

int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    hls.init(tree,1); //求 每个点的重儿
    dsu_on_tree::dfs(1,0,1);
    ans >>YankArray(n) >> out;
    return 0;
}
