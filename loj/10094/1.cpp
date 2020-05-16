/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 16日 星期六 18:43:50 CST
* problem:  loj-10094
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/
using namespace xlx1;
void init(){
     xlx1::xlx_init(); 
     scanf("%d",&n);
     int i,j,t;
     For(i,1,n){
         For(j,1,n){
             scanf("%d",&t);
             if( t )
                 addEdge(i, j);
         }
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

int indgree[maxn],in=0;
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    using namespace Tarjan_QLT;
    work(n);
    for(int i=1;i<=edge_cnt;++i){
        int v = e[i].v,u = e[i].u;
        if( color[v] == color[u]) continue;
        indgree[color[v]]++;
    }
    for(int i =1;i<=color_cnt;i++){
        if( indgree[i] == 0) in++;
    }
    printf("%d\n",in);

    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
