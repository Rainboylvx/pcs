/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 02 Mar 2020 04:18:44 PM CST
* problem: loj-10082
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m;
char str[1005];


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


int ext[500][500];
int cnt =0;
int init(){
     xlx_init(); 
     memset(ext,0,sizeof(ext));
     scanf("%d",&n);
     int i;
     cnt = 0;
     For(i,1,n){
         scanf("%s",str+1);
         int len = strlen(str+1);
         char &a1 = str[1];
         char &a2 = str[2];
         char &b1 = str[len-1];
         char &b2 = str[len];
         int u,v;
         if( !ext[a1][a2])
             u = ext[a1][a2] = ++cnt;
         else
             u = ext[a1][a2];
         if( !ext[b1][b2])
             v = ext[b1][b2] = ++cnt;
         else
             v = ext[b1][b2];

         addEdge(u,v,len);
         //addEdge(v,u,len);

     }
     return n;
}
/* ======= 全局变量 END =======*/

double dis[maxn];
bool vis[maxn];

bool spfa(int u,double avg){
    vis[u] = 1;
    int i;
    for(i = head[u]; ~i;i=e[i].next){
        int v = e[i].v;
        int w = e[i].w;
        if( dis[v] < dis[u]+w-avg){
            dis[v] = dis[u]+w-avg;
            if( vis[v] || spfa(v,avg)){
                vis[u] = 0;
                return 1;
            }
        }
    }
    vis[u] = 0;
    return 0;
}

bool check(double mid){
    int i;
    memset(dis,0,sizeof(dis));
    for(i=1;i<=n;i++){
        if( spfa(i,mid)) return 1;
    }
    return 0;
}

double first_not(){
    double l = 0,r = 1001;
    //int a = spfa(1,215.06);
    //printf("%d\n",a);
    while( r - l > 0.001){
        double mid = (l+r) /2;
        //memset(vis,0,sizeof(vis));
        //memset(dis,0xfe,sizeof(dis));
        dis[1] = 0;
        if(check(mid))
            l = mid+0.001;
        else
            r =mid;
    }
    return l-0.001;
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while( init()){
        memset(dis,0xfe,sizeof(dis));
        dis[1]=0;
        double ans = first_not();
        if( ans <= 0){
            printf("No solution\n");
        }
        else
        printf("%.2lf\n",ans);
        //printf("%.3lf\n",ans);
    }
    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
