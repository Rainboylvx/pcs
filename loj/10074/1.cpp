/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 13:07:01 CST
* problem: loj-10074
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m,k;

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
     scanf("%d%d%d",&n,&m,&k);
     int i,j;
     For(i,1,m){
         int u,v,w;
         scanf("%d%d%d",&u,&v,&w);
         add(u,v,w);
     }
}

bool vis[maxn];
int _01bfs(int s,int limit){
    /* 清空标记 */
    memset(vis,0,sizeof(vis));
    typedef struct { int u,step; } node;
    deque<node> q;
    q.push_back({s,0}); //加入起点

    while( !q.empty()){
        node h = q.front();
        q.pop_front();
        if(vis[h.u]) continue;
        vis[h.u] = 1;
        if(h.u== n){ return h.step; }
        int i,u = h.u;
        for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
            int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
            if(vis[v]) continue;
            if( w > limit)
                q.push_back({v,h.step+1});
            else
                q.push_front({v,h.step});
        }
    }
    return -1; //不能达到终点
}


/* 使用: 首先定义EF::check函数 
 * EF::work(int l,int r)            二分
 * EF::work(double l,double r)      二分-double
 *
 * EF::work 区间[l,r) 内第一个不满足check()的位置
 *  if check(mid) => mid < key 则找到第一个 >=key 的位置 
 *  if check(mid) => mid <=key 则找到第一个 >key  的位置 
 *  核心思想:[l,r)是满足check的区间,不停缩小[l,r)
 * */
namespace EF {
    bool check(int mid);    //函数声明
    int work(int l,int r){
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
}
bool EF::check(int mid){
    int cnt = _01bfs(1, mid);
    if( cnt == -1) return true;
    return cnt > k;
}
using namespace EF;

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //int c = _01bfs(1, 4);
    //printf("%d\n",c);
    int ans = work(0, 1e9);
    if( ans == (int)1e9)
        printf("%d\n",-1);
    else
        printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
