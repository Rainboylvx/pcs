/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 20日 星期三 20:27:35 CST
* problem:  aoj-2840
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e4+5;
const int maxe = 50016;
int n,m;

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w1,w2,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w1,int w2){ e[edge_cnt] = { .u = u,.v=v,.w1=w1,.w2=w2,.next =head[u]}; head[u] = edge_cnt++; }
    //void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 2 =========*/
namespace xlx2 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 2 END =========*/
/* ========= 向量星 1 END =========*/
void init(){
     xlx1::xlx_init(); 
     xlx2::xlx_init(); 
     scanf("%d%d",&n,&m);
     int u,v,w1,w2;
     int i;
     For(i,1,m){
         scanf("%d%d%d%d",&u,&v,&w1,&w2);
         //printf("%d %d %d %d\n",u,v,w1,w2);
         xlx1::addEdge(v,u,w1,w2); //建立反图
     }
}

// ========== dijkstra BEG
namespace dijkstra1 {
    using namespace xlx1;
    typedef long long ll;
    typedef pair<ll,ll> pairI;
    ll dis[maxn]; 
    bool vis[maxn];
    void work(int s){
        priority_queue<pairI, vector<pairI>, greater<pairI> > q;
        memset(dis,0x3f,sizeof(dis));
        /* memset(vis,0,sizeof(vis)); */
        dis[s]=0;
        q.push(make_pair(0,s));
        while(!q.empty()){
            int now=q.top().second;
            q.pop();
            if(vis[now])continue;
            vis[now]=1;
            for(int i=head[now];i!=-1;i=e[i].next){
                if(dis[e[i].v]>dis[now]+e[i].w1){
                    dis[e[i].v]=dis[now]+e[i].w1;
                    q.push(make_pair(dis[e[i].v],e[i].v));
                }
            }
        }
    }
}

// ========== dijkstra BEG
namespace dijkstra3 {
    using namespace xlx2;
    typedef long long ll;
    typedef pair<ll,ll> pairI;
    ll dis[maxn]; 
    bool vis[maxn];
    void work(int s){
        priority_queue<pairI, vector<pairI>, greater<pairI> > q;
        memset(dis,0x3f,sizeof(dis));
        /* memset(vis,0,sizeof(vis)); */
        dis[s]=0;
        q.push(make_pair(0,s));
        while(!q.empty()){
            int now=q.top().second;
            q.pop();
            if(vis[now])continue;
            vis[now]=1;
            for(int i=head[now];i!=-1;i=e[i].next){
                if(dis[e[i].v]>dis[now]+e[i].w){
                    dis[e[i].v]=dis[now]+e[i].w;
                    q.push(make_pair(dis[e[i].v],e[i].v));
                }
            }
        }
    }
}
// ========== dijkstra END
namespace dijkstra2 {
    using namespace xlx1;
    typedef long long ll;
    typedef pair<ll,ll> pairI;
    ll dis[maxn]; 
    bool vis[maxn];
    void work(int s){
        priority_queue<pairI, vector<pairI>, greater<pairI> > q;
        memset(dis,0x3f,sizeof(dis));
        /* memset(vis,0,sizeof(vis)); */
        dis[s]=0;
        q.push(make_pair(0,s));
        while(!q.empty()){
            int now=q.top().second;
            q.pop();
            if(vis[now])continue;
            vis[now]=1;
            for(int i=head[now];i!=-1;i=e[i].next){
                if(dis[e[i].v]>dis[now]+e[i].w2){
                    dis[e[i].v]=dis[now]+e[i].w2;
                    q.push(make_pair(dis[e[i].v],e[i].v));
                }
            }
        }
    }
}
// ========== dijkstra END


int main(){
    //clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dijkstra1::work(n);
    dijkstra2::work(n);
    //printf("d1= %lld\n",dijkstra1::dis[4]);
    //printf("d2= %lld\n",dijkstra2::dis[1]);
    //遍历所有的边
    int i,j;
    For(i,0,xlx1::edge_cnt-1){
        int u = xlx1::e[i].u;
        int v = xlx1::e[i].v;
        int w1 = xlx1::e[i].w1;
        int w2 = xlx1::e[i].w2;
        int w = 0;
        if( dijkstra1::dis[u] + w1 > dijkstra1::dis[v]) w++;
        if( dijkstra2::dis[u] + w2 > dijkstra2::dis[v]) w++;
        xlx2::addEdge(v, u,w);
    }
    dijkstra3::work(1);
    printf("%lld\n",dijkstra3::dis[n]);
    

    //=================== 
    //fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
