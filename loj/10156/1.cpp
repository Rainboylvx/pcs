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
int root;
int f[maxn][2];
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
            addEdge(u, v);
            addEdge(v, u);
        }
    }
    root = 0; // 认为0是根
    memset(f,-1,sizeof(f));
}
/* ======= 全局变量 END =======*/


int dfs_dp(int u,bool exist,int fa){
    if( f[u][exist] != -1) return f[u][exist];
    
    int i,j,child = 0,ans = 0;
    for(i=head[u]; ~i; i = e[i].next){
        int v = e[i].v;
        if( v == fa) continue;
        child++;
        if( exist ) //当前的点放了
        {
            ans += min(
                    dfs_dp(v, exist, u),
                    dfs_dp(v, !exist, u)
                    );
        }
        else //没有放
            ans+= dfs_dp(v,!exist,u);
    }
    if( !child  ){ //有0个孩子
        if( exist) return f[u][1] = 1;
        return f[u][0] = 0;
    }
    return f[u][exist] = ans+exist;
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int a1 = dfs_dp(0,1,0);
    int a2 = dfs_dp(0,0,0);

    printf("%d\n",min(a1,a2));

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
