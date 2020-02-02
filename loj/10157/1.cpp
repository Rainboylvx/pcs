/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 02月 01日 星期六 16:12:06 CST
* problem: loj-_id 
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e4+5;
int n,m;
int val[maxn];
bool is_leaf[maxn];
int f[maxn][3];


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
     int i,j;
     int u,k,m;
     For(i,1,n){
         scanf("%d%d%d",&u,&k,&m);
         val[u] = k;
         int t;
         For(j,1,m){
             scanf("%d",&t);
             addEdge(u,t);
             addEdge(t,u);
         }
     }
}
/* ======= 全局变量 END =======*/

void find_lead(int u,int fa){
    int son=0;
    int i;
    for(i = head[u];~i;i= e[i].next){
        int v = e[i].v;
        if( v == fa) continue;
        son++;
        find_lead(v,u);
    }
    if( !son) is_leaf[u] = 1;
}

int dfs(int u,int st,int fa){
    if(is_leaf[u] ){
        if( st == 0) return val[u];
        if( st == 1) return 0;
        if( st == 2 ) return val[u];
    }
    if( f[u][st] != -1) return f[u][st];

    int i;
    int choose_son=0,ret = 0;
    int min_sub = 0x7f7f7f7f;
    f[u][st] = st == 0 ? val[u] : 0;
    for(i= head[u]; ~i ; i= e[i].next){
        int v = e[i].v;
        if( v == fa) continue;
        int a0 = dfs(v,0,u);
        int a1 = dfs(v,1,u);
        int a2 = dfs(v,2,u);

        if( st == 0)
            ret += min(a0,a1);
        else if ( st == 1)
            ret += min(a0,a2);
        else if( st == 2){
            if( a2 < a0){
                ret += a2;
                min_sub = min(min_sub ,a0-a2);
            }
            else {
                ret += a0;
                choose_son = 1;
            }
        }

    }

    f[u][st] += ret;
    if( !choose_son  && st == 2){
        f[u][st] += min_sub;
    }

    return f[u][st];
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    find_lead(1,0);
    memset(f,-1,sizeof(f));
    int a1 = dfs(1,0,0);
    int a2 = dfs(1,2,0);
    printf("%d\n",min(a1,a2));

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
