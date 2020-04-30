/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 02 Mar 2020 09:16:37 AM CST
* problem: loj-10076
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
const int maxn = 1e5+5;



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
     int i,u,v,w;
     For(i,1,m){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
         addEdge(v, u,w);
     }
}
/* ======= 全局变量 END =======*/

int dis[maxn];
bool vis[maxn];

struct node_n {
    int v,w;
    friend bool operator<(const node_n &a,const node_n &b){
        return a.w+dis[a.v] >  b.w+dis[b.v]; // a* 估价
    }
};

void dijkstra(int s){
    typedef pair<int,int> pairI;
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

void dijkstra2(){
    priority_queue<node_n> q;
    q.push({1,0});
    int k = 0;
    while(!q.empty()){
        int now=q.top().v;
        int w = q.top().w;
        if( now == n && w > dis[1]){
            printf("%d\n",w);
            break;
        }
        q.pop();
        for(int i=head[now];i!=-1;i=e[i].next){
            q.push({e[i].v,e[i].w+w});
        }
    }
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dijkstra(n); //算出dis
    int i;
    //For(i,1,n){
        //printf("%d %d\n",i,dis[i]);
    //}
    dijkstra2();

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
