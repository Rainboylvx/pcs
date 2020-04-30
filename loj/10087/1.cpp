/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 04 Mar 2020 09:28:28 AM CST
* problem: loj-10087
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m;

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


int _max = -1;
void init(){
     xlx_init(); 
     scanf("%d",&n);
     int i,a,b,c;
     For(i,1,n){
         scanf("%d%d%d",&a,&b,&c);
         a++;b++;
         _max = max(b,_max);
         addEdge(a-1, b,c);
     }
     For(i,1,_max){
         addEdge(i-1, i,0);
         addEdge(i,i-1,-1);
     }
     //For(i,1,edge_cnt){
         //printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
     //}
}
/* ======= 全局变量 END =======*/

int dis[maxn];
bool inq[maxn];
void spfa(){
    int i;
    For(i,1,_max){
        dis[i] = -0x3f3f3f3f;
    }
    queue<int> q;
    inq[0] = 1;
    q.push(0);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        inq[u] =0;

        int i;
        for(i = head[u];~i;i = e[i].next){
            int v = e[i].v;
            int w = e[i].w;
            if( dis[v] < dis[u]+w){
                dis[v] = dis[u]+w;
                if( !inq[v]){
                    inq[v] = 1;
                    q.push(v);
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
    printf("%d\n",dis[_max]);
    int i;
    //For(i,1,_max){
        
    //printf("%d %d\n",i,dis[i]);
    //}

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
