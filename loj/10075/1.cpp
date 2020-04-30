/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 01 Mar 2020 11:17:04 PM CST
* problem: loj-10075
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m,x;
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

struct xlx{
    typedef struct  { int u,v,w,next;} node;
    int edge_cnt=0;
    vector<int> head;
    vector<node> e;

    /* 构造函数,点的数量 */
    xlx(int n){
        head = vector<int> (n,-1);
    }

    void add_edge(int u,int v,int w){
        e.push_back({.u = u ,.v = v ,.w = w ,.next = head[u]});
        head[u] = edge_cnt;
        edge_cnt++;
    }

    void add_edge(int u,int v){
        e.push_back({.u = u ,.v = v ,.w = 0 ,.next = head[u]});
        head[u] = edge_cnt;
        edge_cnt++;
    }

    /* 遍历u周围的点 */
    template<class UnaryPredicate>
    void forEach(int u,UnaryPredicate p){
        int i;
        for(i = head[u];i!=-1;i = e[i].next){
            p(e[i].u,e[i].v,e[i].w);
        }
    }
};


xlx xx(maxn);
void init(){
     xlx_init(); 
     scanf("%d%d%d",&n,&m,&x);
     int i;
     int u,v,w;
     For(i,1,m){
       scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
         xx.add_edge(v, u,w);
         //addEdge(v, u,w);
     }
}
/* ======= 全局变量 END =======*/


int dis[maxn];
int sid[maxn];
bool inque[maxn];
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    dis[x] = 0;
    inque[x] = 1;
    queue<int> q;
    q.push(x);
    while( !q.empty()){
        int u = q.front();
        q.pop();
        inque[u] = 0;
        int i;
        for( i = head[u]; ~i;i=e[i].next){
            int v = e[i].v;
            int w = e[i].w;
            if( dis[u]+ w < dis[v]){
                dis[v] = dis[u]+w;
                if( !inque[v]){
                    inque[v] = 1;
                    q.push(v);
                }
            }
        }
    }
}

void spfa2(){
    memset(sid,0x3f,sizeof(sid));
    memset(inque,0,sizeof(inque));
    sid[x] = 0;
    inque[x] = 1;
    queue<int> q;
    q.push(x);
    while( !q.empty()){
        int u = q.front();
        q.pop();
        inque[u] = 0;
        int i;
        auto p = [&](int u,int v,int w){
            if( sid[u]+w < sid[v]){
                sid[v] = sid[u] +w;
                if( !inque[v] ){
                    inque[v] = 1;
                    q.push(v);
                }
            }
        };
        xx.forEach(u, p);
    }
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    spfa();
    spfa2();
    int i;
    int _m = -1;
    For(i,1,n){
        //printf("%d : %d\n",i,sid[i]);
        _m = max(_m ,sid[i]+dis[i]);
    }
    printf("%d\n",_m);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
