/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 15 Mar 2020 03:00:54 PM CST
* problem: loj-10092
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m,mod;
int color_size[maxn];
int dp1[maxn],dp2[maxn];
int vis[maxn];

/* ======= 全局变量 END =======*/

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxn*50];
    void inline init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 1 END =========*/

void init(){
    xlx1::init(); 
    scanf("%d%d%d",&n,&m,&mod);
    int i,j,k;
    int u,v;
    For(i,1,m){
        scanf("%d%d",&u,&v);
        xlx1::addEdge(u, v);
    }
}

// ========== tarjan 求强连通分量
namespace Tarjan_QLT {
    int dfn[maxn],low[maxn],color[maxn];
    bool instack[maxn];
    int idx,color_cnt;
    std::stack<int> sta;
    void init(){
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instack,0,sizeof(instack));
        color_cnt = idx = 0;
    }
    void tarjan(int u){
        dfn[u] = low[u] = ++idx;
        sta.push(u);
        instack[u] = 1;
        int i;
        for( i =xlx1::head[u]; ~i ;i = xlx1::e[i].next){
            int &v = xlx1::e[i].v;
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
                color_size[color_cnt]++;
                instack[t] = 0;
                color[t] = color_cnt;
            }
            while( t != u);
        }
    }
    void work(int n){
        int i;
        for( i =1;i<=n;i++){
            if( !dfn[i]) tarjan(i);
        }
    }
}
// ========== tarjan 求强连通分量 END

/* ========= 向量星 2 =========*/
namespace xlx2 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxn*50];
    void inline init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 2 END =========*/
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    Tarjan_QLT::init();
    Tarjan_QLT::work(n);
    int i,j;
    int ans1=0,ans2=0;
    //建立图2
    xlx2::init();
    For(i,1,m){
        int u = xlx1::e[i].u;
        int v = xlx1::e[i].v;
        if( Tarjan_QLT::color[u] != Tarjan_QLT::color[v] ){
            xlx2::addEdge( Tarjan_QLT::color[u] , Tarjan_QLT::color[v] );
        }
    }

    For(i,1,Tarjan_QLT::color_cnt){
        dp1[i] = color_size[i];
        dp2[i] = 1;
    }

    for( i = Tarjan_QLT::color_cnt;i>=1;i--){ //topOrder
        for(j= xlx2::head[i]; ~j ;j = xlx2::e[j].next){
            int &v = xlx2::e[j].v; int &w = xlx2::e[j].w;
            if(vis[v] == i) continue;
            vis[v] = i;
            if( dp1[v] < dp1[i] + color_size[v]){
                dp1[v] = dp1[i] + color_size[v];
                dp2[v] = dp2[i];
            }
            else if( dp1[v] == dp1[i] + color_size[v] ){
                dp2[v] = (dp2[v] + dp2[i]) %mod;
            }
        }
    }
    For(i,1,Tarjan_QLT::color_cnt){
        if( dp1[i] > ans1){
            ans1 = dp1[i];
            ans2 = dp2[i];
        }
        else if( dp1[i] == ans1){
            ans2 += dp2[i];
            ans2 %= mod;
        }
    }
    printf("%d\n%d\n",ans1,ans2);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
