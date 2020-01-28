/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 01月 27日 星期一 20:37:09 CST
* problem: loj-10156
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn =1505;
int n,m;
vector<int> tree[maxn];
int root;


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
    scanf("%d",&n);
    //建树
    int i,j,k;
    For(i,1,n){
        int u,v;
        scanf("%d%d",&u,&k);
        For(j,1,k){
            scanf("%d",&v);
            tree[u].push_back(v);
        }
    }
}
/* ======= 全局变量 END =======*/


void dfs_dp(int u){
    
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dfs_dp(0);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
