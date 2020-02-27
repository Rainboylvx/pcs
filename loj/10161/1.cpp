/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 12 Feb 2020 10:30:46 AM CST
* problem: loj-10161
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m;
int root;
int leaf[maxn];
int f[maxn][2];

/* ======= 全局变量 END =======*/

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
    memset(f,-1,sizeof(f));
    xlx_init();
    scanf("%d%d",&m,&n);
    root = n+1;
    int i;
    For(i,1,n){
        scanf("%d",&leaf[i]);
    }
    int u,v;
    For(i,1,m-1){
        scanf("%d%d",&u,&v);
        addEdge(u, v);
        addEdge(v,u);
    }
}

int dfs(int u,int fa,int col){
    if( u <= n ){ //叶子
        return !(col == leaf[u]);
    }
    int i;
    if( f[u][col] !=-1 ) return f[u][col];
    int ret = 0;
    Each_e(u){
        int v  = e[i].v;
        if( v == fa) continue;
        ret += min(dfs(v,u,col),dfs(v,u,!col)+1);
    }
    return f[u][col] = ret;
}

void debug(){
    int i,j;
    printf("%2d%4d%4d\n",0,0,1);
    For(i,n+1,m){
        printf("%2d%4d%4d\n",i,f[i][0],f[i][1]);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ans = min(dfs(root,0,1),dfs(root,0,0))+1;
    printf("%d\n",ans);
    //debug();

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
