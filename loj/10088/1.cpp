/*---------------t-
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 07 Mar 2020 07:18:51 PM CST
* problem: loj-10088
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
const int maxn = 25*25;

int r[25],num[25];


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
    int i;
    memset(num,0,sizeof(num));
    For(i,1,24){
        scanf("%d",&r[i]);
    }
    scanf("%d",&m);
    int t;
    For(i,1,m){
        scanf("%d",&t);
        num[t+1]++;
    }
}
/* ======= 全局变量 END =======*/

void create_graph(int val){
     xlx_init(); 
     int i;
     For(i,1,24){
         addEdge(i, i-1,-num[i]);
         addEdge(i-1, i,0);
     }
     For(i,8,24){
         addEdge(i-8, i,r[i]);
     }
     For(i,1,7){
         addEdge(i+16,i,r[i]-val);
     }
     addEdge(0, 24,val);
}

bool inque[50];
int dis[50];
int cnt[50];

bool spfa(int val){
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    inque[0] = 1;
    memset(inque,0,sizeof(inque));
    memset(cnt,0,sizeof(cnt));
    int i;
    For(i,1,24){
        dis[i] = -0x3f3f3f3f;
    }

    while(!q.empty()){
        int u = q.front();q.pop();
        inque[u] = 0;

        for(i = head[u];~i;i=e[i].next){
            int w = e[i].w;
            int v = e[i].v;
            if( dis[v] < dis[u]+w){
                dis[v] = dis[u]+w;
                cnt[v]++;
                if(cnt[v]>= 25) {
                    return 0;
                }

                if( !inque[v]){
                    inque[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    if( dis[24] == val){
        return 1;
    }
    return 0;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d",&n);
    while( n -- ){
        init();
        int i;
        bool  flag = 0;
        for( i =0;i<=m;i++){
            create_graph(i);
            if( spfa(i)){
                flag = 1;
                printf("%d\n",i);
                break;
            }
        }
        if( !flag)
            printf("No Solution\n");
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
