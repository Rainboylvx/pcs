/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 27 Feb 2020 12:30:37 PM CST
* problem:  loj-10064
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(i,u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e3+5;
int n,m;
int cnt[maxn];

/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[maxn*maxn];

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
     int u,v,w;
     For(i,1,m){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
         addEdge(v, u,w);
     }
}
/* ======= 全局变量 END =======*/

int dis[maxn];
bool vis[maxn];
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

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dijkstra(1);
    int i,j;
    
    For(i,1,n){
        for(j= head[i]; ~j ;j =e[j].next){
            int &v = e[j].v; int &w = e[j].w;
            if( dis[v]+ w == dis[i])
                cnt[i]++;
        }
    }
    long long mod = (1<<31)-1;
    long long ans = 1;
    For(i,2,n){
        ans = (ans * cnt[i]) % mod;
        //printf("%d\n",cnt[i]);
    }
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
