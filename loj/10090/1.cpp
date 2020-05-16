/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 16日 星期六 15:18:21 CST
* problem: loj-10090
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m1,m2;

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
     scanf("%d%d%d",&n,&m1,&m2);
     int i,u,v,w;
     For(i,1,m1){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
     }
     For(i,1,m2){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(v, u,-w);
     }
}
/*  求负环为什么dis清0？为什dis,ins只要清一次？
 * */
namespace spfa_dfs{
    using namespace xlx1;
    bool ins[maxn]; //在栈内
    long long dis[maxn]; // double ,long long 根据题意更改
    bool dfs(int u){ //找负环
        ins[u] = 1;
        for( int i = head[u]; ~i; i = e[i].next){
             int v = e[i].v,w=e[i].w;
             if( dis[v] > dis[u]+w){
                 dis[v] = dis[u]+w;
                 if( ins[v] || dfs(v) ) return true;
             }
        }
        ins[u] = 0;
        return 0;
    }
    bool wk(){
        memset(dis,0x7f,sizeof(dis));
        memset(ins,0,sizeof(ins)); // bool的全局变量可能不全是0
        dis[1] = 0;
        for(int i=1;i<=n;++i){
            if( dfs(i) ) return 1;
        }
        return 0;
    }
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ret = spfa_dfs::wk();
    if( ret ){
        printf("-1");
        return 0;
    }
    else if ( spfa_dfs::dis[n] == 0x7f7f7f7f7f7f7f7f)
    {
        printf("-2");
        return 0;
    }
    printf("%lld\n",spfa_dfs::dis[n]);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
