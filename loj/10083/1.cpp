/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 03 Mar 2020 06:16:02 PM CST
* problem: loj-10083
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
int s,t;
const int maxn = 1e5+5;
int dis[105][300005]; //点,花费的最小时间


/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,c,t,next;
}e[maxn<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int c,int t){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].c=c;
    e[edge_cnt].t=t;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}

/* ================= 向量星 end =================*/


struct node {
    int u,sp;
};
void init(){
     xlx_init(); 
     memset(dis,0x3f,sizeof(dis));
     scanf("%d%d%d%d",&n,&m,&s,&t);
     int i;
     int u,v,c,tt;
     For(i,1,m){
         scanf("%d%d%d%d",&u,&v,&c,&tt);
         addEdge(u, v, c, tt);
         addEdge(v, u, c, tt);
     }
}
/* ======= 全局变量 END =======*/


bool inque[105][300005];
void spfa(){
    queue<node> q;
    dis[s][0] = 0;
    inque[s][0] = 1;
    q.push({s,0});
    while( !q.empty()){
        node h = q.front();
        q.pop();
        inque[h.u][h.sp] = 0;

        int i;
        for(i= head[h.u]; ~i;i = e[i].next){
            int v = e[i].v;
            int c = e[i].c;
            int t = e[i].t;

            int cost = e[i].c + h.sp;
            if( cost >= 10000) continue;
            if( dis[v][cost] > dis[h.u][h.sp] + t){
                dis[v][cost] = dis[h.u][h.sp] + t;
                //printf("%d %d %d\n",v,cost,dis[v][cost]);
                if( !inque[v][cost]){
                    inque[v][cost] = 1;
                    q.push({v,cost});
                }
            }
        }
    }
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    spfa();
    int _maxn = 0x3f3f3f3f,ans = 0;
    int i;
    for(i = 0;i<=10000;i++){
        if( dis[t][i] < _maxn){
            _maxn = dis[t][i];
            //printf("%d %d\n",i,dis[t][i]);
            ans++;
        }
    }
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
