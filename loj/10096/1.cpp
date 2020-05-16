/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 16日 星期六 19:26:27 CST
* problem: loj-10096
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 5e5+5;
const int maxe = 1e6+5;
int n,m,s,p;
int money[maxn]; //
int money2[maxn]; 
vector<int> jb; //酒吧


/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
using namespace xlx1;
/* ========= 向量星 1 END =========*/

void init(){
     xlx1::xlx_init(); 
     scanf("%d%d",&n,&m);
     int i,j;
     int u,v;
     For(i,1,m){
         scanf("%d%d",&u,&v);
         addEdge(u, v);
     }
     For(i,1,n){
         scanf("%d",&money[i]);
     }
     scanf("%d%d",&s,&p);
     For(i,1,p){
         scanf("%d",&u);
         jb.push_back(u);
     }
}

// ========== tarjan 求强连通分量
namespace Tarjan_QLT {
    int dfn[maxn],low[maxn],color[maxn];
    bool instack[maxn];
    int idx,color_cnt;
    std::stack<int> sta;
    void qlt_init(){
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instack,0,sizeof(instack));
        color_cnt = idx = 0;
    }
    void tarjan(int u){ 
        dfn[u] = low[u] = ++idx; //时序编号
        sta.push(u);			 //入栈
        instack[u] = 1;
        int i;
        for( i =head[u]; ~i ;i = e[i].next){
            int &v = e[i].v;
            if( !dfn[v]){ //没有访问过
                tarjan(v);
                low[u] = std::min(low[u],low[v]); //<u,v> 是树边
            }
            else if( instack[v]){ //已经访问,且未输出
                low[u] = std::min(low[u],dfn[v]);
            }
        }

        //强连通分量子树的跟
        if( dfn[u] == low[u]){
            color_cnt++;
            int t = -1;
            do {
                t = sta.top(); sta.pop();
                instack[t] = 0;
                color[t] = color_cnt;
            }
            while( t != u);
        }
    }
    void work(int n){
        for( int i =1;i<=n;i++){ //从每个点开始
            if( !dfn[i]) tarjan(i);
        }
    }
}
// ========== tarjan 求强连通分量 END
using namespace Tarjan_QLT;

/* ========= 向量星 2 =========*/
namespace xlx2 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 2 END =========*/

// ========== spfa BEG
namespace spfa {
    using namespace xlx2;
    typedef long long ll;
    ll dis[maxn];
    bool vis[maxn]; //是否在队列内
    void work(int s){
        memset(dis,0,sizeof(dis));
        dis[s] = money2[s],vis[s] = 1;
        deque<int> q;
        q.push_back(s);
        while( !q.empty()){
            int u = q.front();q.pop_front();
            vis[u] = 0;
            for( int i = xlx2::head[u]; ~i ;i=xlx2::e[i].next){
                int v= xlx2::e[i].v,w = money2[v];
                if( dis[v] < dis[u] + w){
                    dis[v] = dis[u] + w;
                    if( !vis[v]){
                        vis[v] = 1;
                        if( q.empty()) q.push_back(v);  //SLF 优化
                        else if( dis[v] > dis[q.front()]) q.push_front(v);
                        else q.push_back(v);
                    }
                }
            }
        }
    }
}
// ========== spfa END

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    work(n);
    int i,j;
    For(i,1,n){
        money2[color[i]] += money[i];
    }
    // 建立新的图
    xlx2::xlx_init();
    For(i,1,edge_cnt){
        int u = e[i].u;
        int v = e[i].v;
        if( color[u] != color[v]) xlx2::addEdge(color[u], color[v]);
    }
    spfa::work(color[s]);
    long long ans = -1;
    for (const auto& e : jb) {
        ans = max(ans,spfa::dis[color[e]]);
    }
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
