/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Fri 13 Mar 2020 07:40:49 PM CST
* problem: loj-10091
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m;


/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[maxn<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}

/* 函数重载 */
void addEdge(int u,int v){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/


void init(){
     xlx_init(); 
     scanf("%d%d",&n,&m);
     int i;
     int u,v;
     For(i,1,m){
         scanf("%d%d",&u,&v);
         addEdge(u, v);
     }
}
/* ======= 全局变量 END =======*/

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
        int i;
        for( i =1;i<=n;i++){
            if( !dfn[i]) tarjan(i);
        }
    }
}
// ========== tarjan 求强连通分量 END


int out_degree[maxn];
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    Tarjan_QLT::work(n);
    if( Tarjan_QLT::color_cnt == 1){
        printf("%d\n",n);
    }
    else {
        int degree_0 = 0;
        int i;
        For(i,1,edge_cnt){
            int u = e[i].u;
            int v = e[i].v;
            if( Tarjan_QLT::color[u] != Tarjan_QLT::color[v] )
                out_degree[ Tarjan_QLT::color[u] ]++;
        }
        For(i,1,Tarjan_QLT::color_cnt){
            if( out_degree[ i ] ==0)
                degree_0++;
        }
        if( degree_0!= 1){
            printf("%d\n",0);
        }
        else{
            int ans = 0;
            For(i,1,n){
                if( out_degree[ Tarjan_QLT::color[i] ] == 0)
                    ans++;
            }
            printf("%d\n",ans);
        }
    }
    //printf("%d\n",Tarjan_QLT::color_cnt);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
