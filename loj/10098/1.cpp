/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 26 Mar 2020 10:41:33 PM CST
* problem: loj-10098
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
int degree[maxn]; //计算缩点的度
/* ======= 全局变量 END =======*/


/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline init(){ edge_cnt = -1; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 1 END =========*/
void init(){
     xlx1::init(); 
     scanf("%d%d",&n,&m);
     int i,u,v;
     For(i,1,m){
         scanf("%d%d",&u,&v);
         xlx1::addEdge(u, v);
         xlx1::addEdge(v, u);
     }
}

//边双连通分量
namespace EBC {
    int low[maxn],dfn[maxn],color[maxn];
    int col[maxe];
    int ord=0,mark;

    void tarjan(int u,int pre){
        low[u] = dfn[u] = ++ord;
        int i;
        for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
            int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
            if(v == pre) continue;
            if( !dfn[v]){
                tarjan(v, u);
                low[u] = min(low[u],low[v]);
                //标记桥
                if( low[v] > dfn[u]) col[i] = col[i^1] =1;
            }
            else low[u] = min(low[u],dfn[v]);
        }
    }

    void dfs(int u,int pre){
        color[u] = mark;
        int i;
        for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
            int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
            // //该边非桥,不为前驱,且没有被染色
            if( !col[i] && v!=pre && !color[v])
                dfs(v,u);
        }
    }

    void work(int u){
        int i;
        for(i=1;i<=n;i++)
            if( !dfn[i])
                tarjan(i, -1);
        for(i=1;i<=n;i++)
            if( !color[i]){
                mark++;
                dfs(i,-1);
            }
    }

}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    EBC::work(1);
    int i,j;
    for(i=0;i<=xlx1::edge_cnt;i+=2){
        int &u = xlx1::e[i].u;
        int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
        if( EBC::color[u] != EBC::color[v] ){
            degree[ EBC::color[u] ]++;
            degree[ EBC::color[v] ]++;
        }
    }
    //For(i,1,n){
        //printf("==%d %d\n",i,EBC::color[i]);
    //}
    int cnt=0;
    For(i,1,EBC::mark){
        if( degree[i] == 1) cnt++;
    }
    //printf("%d\n",EBC::mark);
    //printf("%d\n",cnt);
    printf("%d\n",(cnt+1)>>1);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
