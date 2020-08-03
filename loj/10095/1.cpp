/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 16日 星期六 19:07:14 CST
* problem: loj-10095
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,p,r;
int spen[maxn]; //每个间谍需要的钱

int indgree[maxn],spen2[maxn]; //spen2 每个分量的最大花费
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
     memset(spen,0x7f,sizeof(spen)); // -1 表示不能被控
     scanf("%d",&n);
     scanf("%d",&p);
    int i,j,t1,t2;
    For(i,1,p){
        scanf("%d%d",&t1,&t2);
        spen[t1] = t2;
    }
    scanf("%d",&r);
    For(i,1,r){
        scanf("%d%d",&t1,&t2);
        addEdge(t1,t2);
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
            int _min = 0x7f7f7f7f;
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
            if( !dfn[i] ) tarjan(i);
        }
    }
}
// ========== tarjan 求强连通分量 END

using namespace Tarjan_QLT;
bool vis[maxn];
void dfs(int u){
    vis[u] = 1;
    int i;
    for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
        int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
        if( vis[v]) continue;
        dfs(v);
    }
}
int biao_ji(){
    int i;
    for( i =1;i<=n;i++){
        if( !vis[i] && spen[i] != 0x7f7f7f7f){
            dfs(i);
        }
    }
    for(i=1;i<=n;i++) if(!vis[i]) return i;
    return -1;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int i,j;
    init();
    For(i,1,edge_cnt){
        int u = e[i].u;
        int v = e[i].v;
        //if( u == 6 || v == 6){
            //printf("yes 0\n\n");
        //}
    }
    work(n);
    memset(spen2,0x7f,sizeof(spen2));
    For(i,1,n){
        spen2[color[i]] = min( spen2[color[i]], spen[i]);
    }
    For(i,1,edge_cnt){
        int u = e[i].u;
        int v = e[i].v;
        //if( u == 6 || v == 6){
            //printf("yes\n\n");
        //}
        if( color[u] == color[v]) continue;
        indgree[color[v]]++;
    }
    int ans = 0;
    for(i=1;i<=color_cnt;++i){
        if( indgree[i] == 0){
            if( spen2[i] == 0x7f7f7f7f){
                printf("NO\n");
                printf("%d\n",biao_ji());
                return 0;
            }
            ans += spen2[i];
        }
    }
    printf("YES\n");
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
