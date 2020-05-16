/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 12日 星期二 14:26:42 CST
* problem: loj-2632
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int N= 5e2+600;
const int maxn= N*N;
const int maxe = 1e6+5;
int n,m;

char str[maxn];
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
int s,t;

void init(){
    xlx_init();
    scanf("%d%d",&n,&m);
    s = 1;
    t = n*(m+1)+m+1;
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%s",str+1);
        for(j=1;j<=m;++j){
            char c = str[j];
            int x1 = (i-1)*(m+1)+j;
            int x2 = x1+1;
            int y1 = i*(m+1)+j;
            int y2 = y1+1;
            if( c == '\\'){
                addEdge(x1,y2,0);
                addEdge(y2,x1,0);
                addEdge(y1,x2,1);
                addEdge(x2,y1,1);
            }
            else {
                addEdge(x1,y2,1);
                addEdge(y2,x1,1);
                addEdge(y1,x2,0);
                addEdge(x2,y1,0);
            }
        }
    }
}

struct node { int u; int step; };
bool vis[maxn];
void _01bfs(){
    deque<node> dq;
    dq.push_back({1,0});

    while ( !dq.empty()){
        node h = dq.front();
        dq.pop_front();
        int u = h.u,i;
        vis[u] = 1;
        if( u == t){
            printf("%d\n",h.step);
            return;
        }
        for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
            int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
            if( vis[v]) continue;
            if( w ){
                dq.push_back({v,h.step+w});
            }
            else
                dq.push_front({v,h.step+w});
        }
    }
    printf("NO SOLUTION\n");
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    _01bfs();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
