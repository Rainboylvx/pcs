/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 14:27:27 CST
* problem: loj-10078
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
int five[6];

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
using namespace xlx1;
/* ========= 向量星 1 END =========*/
void init(){
     xlx1::xlx_init(); 
     scanf("%d%d",&n,&m);
     int i,j;
     For(i,1,5){
         scanf("%d",&five[i]);
     }
     For(i,1,m){
         int u,v,w;
         scanf("%d%d%d",&u,&v,&w);
         add(u,v,w);
     }
}


// ========== spfa BEG
ll dis_1[maxn];
ll dis_2[maxn];
ll dis_3[maxn];
ll dis_4[maxn];
ll dis_5[maxn];
namespace spfa {
    using namespace xlx1;
    typedef long long ll;
    void work(int s ,ll dis[]){
        dis[s] = 0;
        queue<int> q;
        q.push(s);
        while( !q.empty()){
            int u = q.front();q.pop();
            for( int i = head[u]; ~i ;i=e[i].next){
                int v= e[i].v,w = e[i].w;
                if( dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push(v);
                }
            }
        }
    }
}
// ========== spfa END

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    memset(dis_1,0x7f,sizeof(dis_1));
    memset(dis_2,0x7f,sizeof(dis_2));
    memset(dis_3,0x7f,sizeof(dis_3));
    memset(dis_4,0x7f,sizeof(dis_4));
    memset(dis_5,0x7f,sizeof(dis_5));
    spfa::work(five[1], dis_1);
    spfa::work(five[2], dis_2);
    spfa::work(five[3], dis_3);
    spfa::work(five[4], dis_4);
    spfa::work(five[5], dis_5);

    int ord[] = {0,1,2,3,4,5};
    ll *dis[6] = { 0, dis_1, dis_2, dis_3, dis_4, dis_5};
    ll ans = 0x7f7f7f7f7f7f7f7f;
    do {
        ll t = 0;
        t+= dis[ord[1]][1]; //到1的距离
        t+= dis[ord[2]][five[ord[1]]]; 
        t+= dis[ord[3]][five[ord[2]]]; 
        t+= dis[ord[4]][five[ord[3]]]; 
        t+= dis[ord[5]][five[ord[4]]]; 
        if( ans > t){
            ans = t;
            //int i;
            //For(i,1,5){
                //printf("%d ",ord[i]);
            //}
            //printf("\n");
             //printf("==>%lld\n",dis[ord[1]][1]);
             //printf("==>%lld\n",dis[ord[2]][ord[1]]); 
             //printf("==>%lld\n",dis[ord[3]][ord[2]]); 
             //printf("==>%lld\n",dis[ord[4]][ord[3]]); 
             //printf("==>%lld\n",dis[ord[5]][ord[4]]); 
             //printf("\n");
             //printf("\n");
             //printf("\n");


        }
    }while( next_permutation(ord+1, ord+1+5));
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
