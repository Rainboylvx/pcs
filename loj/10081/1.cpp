/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 14:52:47 CST
* problem: loj-10081
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,r,p,s;

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
     scanf("%d%d%d%d",&n,&r,&p,&s);
     int i,j;
     int u,v,w;
     For(i,1,r){
         scanf("%d%d%d",&u,&v,&w);
         add(u, v,w);
     }
     For(i,1,p){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
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
                        if( q.empty()) q.push_back(v);
                        else if( dis[v] < dis[q.front()]) q.push_front(v);
                        else q.push_back(v);
                    }
                    //else
                        //q.push_back(v);
                }
            }
        }
    }
}
// ========== spfa END
using namespace spfa;

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    work(s);
    int i;
    For(i,1,n){
        if( dis[i] == 0x7f7f7f7f7f7f7f7f)
            printf("NO PATH\n");
        else
            printf("%lld\n",dis[i]);
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
