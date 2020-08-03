/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 18日 星期一 21:38:26 CST
* problem: loj-10104
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

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/
using namespace xlx1;

vector<int> Child[maxn]; // 割点的dfs树分量孩子大小
int siz[maxn]; //点i为根的子树大小
// ==== 此模板可以求无向图割点,割边,边分,点双
#define CUT_N  //割点 开关
//#define BRIDGE //割边 开关
//#define N_BCC  //点双 开关
//#define E_BCC  //边双 开关
//不用加instack
namespace UDG_tarjan {
    using namespace xlx1; // 从0开始存边
    typedef long long ll;
    int low[maxn],dfn[maxn];
    int index=0,bridge= 0,child=0,root,t=-1;

#ifdef CUT_N
    bool cut_n[maxn];   //点是否割点
#endif

#ifdef BRIDGE
    bool cut_e[maxe];   //边是否割边
#endif

#ifdef E_BCC
    int color_n[maxn],color_n_cnt=0;  //边双 给点染色
    stack<int> sta_e;   //边双 存点入栈
#endif

#ifdef N_BCC
    stack<int> sta_n;   //存边的栈
    int color_e_cnt=0,color_e[maxe]; //对边进行染色
    int color_n_t[maxn]; //临时
    int nbcc_cnt=0; //点双计数
    vector<int> nbcc_v[maxn];
#endif

    void udg_tarjan_init(int Root = 1){
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        index=bridge=0;
#ifdef CUT_N
        memset(cut_n,0,sizeof(cut_n));
        root = Root,child=0;
#endif
#ifdef BRIDGE
        memset(cut_e,0,sizeof(cut_e));
#endif
#ifdef E_BCC
        memset(color_n,0,sizeof(color_n));
        color_n_cnt = 0; //sta_e.clear();
#endif
#ifdef N_BCC
        color_e_cnt=nbcc_cnt=0;
        memset(color_e,0,sizeof(color_e));
        memset(color_n_t,0,sizeof(color_n_t));
        //for (const auto& e : nbcc_v) e.clear();
#endif
    }

    void tarjan(int u,int E){
        siz[u] = 1;
        low[u] = dfn[u] = ++index; 
#ifdef E_BCC
        sta_e.push(u); //边双 存点入栈
#endif
        for(int i= head[u]; ~i ;i=e[i].next){
            int v = e[i].v;
            if( !dfn[v]){
#ifdef N_BCC
                sta_n.push(i); //点双 存边入栈
#endif
#ifdef CUT_N
                if( u == root) child++;   //割点 根点孩子加1
#endif
                tarjan(v,i);
                if( u == root) Child[u].push_back(siz[v]);   //割点 根点孩子加1
                siz[u] += siz[v];
                if( low[u] > low[v]) low[u] = low[v];
#ifdef BRIDGE   // 割边
                if( low[v] > dfn[u]){ bridge++; cut_e[i]= cut_e[i^1] = 1; }
#endif
#ifdef CUT_N    // 割点
                if( low[v] >= dfn[u] && u != root) {
                    cut_n[u] = 1;
                    Child[u].push_back(siz[v]);
                }
#endif
#ifdef N_BCC
                //点双 对边进行染色
                if( low[v] >=dfn[u] ){
                    nbcc_cnt++;
                    t=-1; do {
                        t = sta_n.top();sta_n.pop();
                        color_e[t] = color_e[t^1] = color_e_cnt;
                        int u = e[t].u,v = e[t].v; //核心思想：不重复的放入
                        if( color_n_t[u] != nbcc_cnt){
                            nbcc_v[nbcc_cnt].push_back(u);
                            color_n_t[u] = nbcc_cnt;
                        }
                        if( color_n_t[v] != nbcc_cnt) {
                            nbcc_v[nbcc_cnt].push_back(v);
                            color_n_t[v] = nbcc_cnt;
                        }
                    }while( t != i );
                }
#endif
            }
            else if( (i^1) != E && low[u] > dfn[v]) low[u] = dfn[v];
        }
#ifdef CUT_N // 割点
        if( u == root && child>1) cut_n[u] = 1;
#endif
#ifdef E_BCC // 边双
        if( low[u] == dfn[u]){
            color_n_cnt++,t=-1;
            do {
                t = sta_e.top();sta_e.pop();
                color_n[t] = color_n_cnt;
            }while( t != u);
        }
#endif
    }
}

void init(){
     xlx1::xlx_init(); 
     scanf("%d%d",&n,&m);
     int u,v,i;
     For(i,1,m){
         scanf("%d%d",&u,&v);
         add(u, v);
     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    using namespace UDG_tarjan;
    root = 1;
    tarjan(1,-1);
    int i;
    For(i,1,n){
        if(cut_n[i]){
            ll ans = 0,sum =0;
            ll nn = n;
            for (const auto& e : Child[i]) {
                sum += e;
                ans += (nn-e)*e;
            }
            sum = n - sum-1;
            ans += sum*(nn-sum);
            ans += (nn-1);
            printf("%lld\n",ans);
        }
        else printf("%lld\n",((ll)n-1)<<1);
        //printf("%d %d\n",i,cut_n[i]);
        //printf("===>");
        //for (const auto& e : Child[i]) {
            //printf("%d ",e);
        //}
        //printf("\n");
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
