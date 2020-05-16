/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 14:03:07 CST
* problem: loj-10077
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
const int mod = 100003;
int n,m;

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
     scanf("%d%d",&n,&m);
     int i,j;
     For(i,1,m){
         int u,v;
         scanf("%d%d",&u,&v);
         add(u,v,1);
     }
}


int cnt[maxn]; //到i的最短路径条数
namespace spfa {
    using namespace xlx1;
    typedef long long ll;
    ll dis[maxn];
    void work(int s){
        cnt[s] = 1;
        memset(dis,0x7f,sizeof(dis));
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while( !q.empty()){
            int u = q.front();q.pop();
            for( int i = head[u]; ~i ;i=e[i].next){
                int v= e[i].v,w = e[i].w;
                if( dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u];
                    q.push(v);
                }
                else if( dis[v] == dis[u] + w ){
                    cnt[v] += cnt[u];
                    cnt[v] %= mod;
                }
            }
        }
    }
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    spfa::work(1);
    int i;
    For(i,1,n){
        printf("%d\n",cnt[i]);
        //printf("%lld %d\n",spfa::dis[i],cnt[i]);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
