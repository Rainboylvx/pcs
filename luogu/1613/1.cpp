/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 22日 星期五 15:30:04 CST
* problem: luogu-1613
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
bool g[55][55][130];
bool f[55][55];

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; } void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);} }
/* ========= 向量星 1 END =========*/
void init(){
    scanf("%d%d",&n,&m);
    int u,v,i,j,k,t;
    For(i,1,m){
        scanf("%d%d",&u,&v);
        g[u][v][0] = 1;
    }
    For(k,1,64){
        For(i,1,n){
            For(j,1,n){
                For(t,1,n){
                    if( g[i][t][k-1] && g[t][j][k-1] ){
                        g[i][j][k] = 1;
                    }
                }
            }
        }
    }
    using namespace xlx1;
    xlx_init();
    For(i,1,n){
        For(j,1,n){
            For(k,0,64){
                if(g[i][j][k]){
                    f[i][j] =1;
                    addEdge(i, j,1);
                }
            }
        }
    }
}
// ========== spfa BEG
namespace spfa {
    using namespace xlx1;
    typedef long long ll;
    ll dis[maxn];
    bool vis[maxn]; //是否在队列内
    void work(int s){
        memset(dis,0x7f,sizeof(dis));
        dis[s] = 0,vis[s] = 1;
        deque<int> q;
        q.push_back(s);
        while( !q.empty()){
            int u = q.front();q.pop_front();
            vis[u] = 0;
            for( int i = head[u]; ~i ;i=e[i].next){
                int v= e[i].v,w = e[i].w;
                if( dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    if( !vis[v]){
                        vis[v] = 1;
                        if( q.empty()) q.push_back(v);  //SLF 优化
                        else if( dis[v] < dis[q.front()]) q.push_front(v);
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
    spfa::work(1);
    printf("%lld\n",spfa::dis[n]);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
