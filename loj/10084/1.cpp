/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 18:13:25 CST
* problem:  loj-10084
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define F_MAX(u,t) (u = std::max(u,t))
#define F_MIN(u,t) (u = std::min(u,t))
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
int max_len = -1;
int min_len = 0x7f7f7f7f;

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
     int i,u,v,w;
     For(i,1,m){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u,v,w);
         F_MAX(max_len,w);
         F_MIN(min_len,w);
     }
}

double avg;
/*  求负环为什么dis清0？为什dis,ins只要清一次？
 * */
namespace spfa_dfs{
    using namespace xlx1;
    bool ins[maxn]; //在栈内
    double dis[maxn];
    bool dfs(int u){ //找负环
        ins[u] = 1;
        for( int i = head[u]; ~i; i = e[i].next){
             int v = e[i].v,w=e[i].w;
             if( dis[v] > dis[u]+w-avg){
                 dis[v] = dis[u]+w-avg;
                 if( ins[v] || dfs(v) ) return true;
             }
        }
        ins[u] = 0;
        return 0;
    }
    bool wk(){
        memset(dis,0,sizeof(dis));
        memset(ins,0,sizeof(ins)); // bool的全局变量可能不全是0
        for(int i=1;i<=n;++i){
            if( dfs(i) ) return 1;
        }
        return 0;
    }
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
    bool check(double mid); //函数声明
    double work(double l,double r){
        double eps = 1e-9;
        while(r-l >eps){
            double mid = (l+r) /2;
            if( check(mid) ) l = mid; //舍弃左边
            else r = mid;  //舍弃右边
        }
        return r;
    }
}
bool EF::check(double mid){
    avg = mid;
    return !spfa_dfs::wk();
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //avg = 3.7;
    //bool ret = spfa_dfs::wk();
    //printf("%d\n",ret);
    double ans = EF::work(-1e7,1e7);
    printf("%.8lf\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
