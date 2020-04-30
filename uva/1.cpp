/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Fri 27 Mar 2020 04:13:04 PM CST
* problem: loj-10099
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
int in_case;
int dot[maxn];

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 1 END =========*/

/* ======= 全局变量 END =======*/
void init(){
     xlx1::init(); 
     int i,u,v;
     For(i,1,n){
         scanf("%d%d",&u,&v);
         xlx1::addEdge(u, v);
         xlx1::addEdge(v, u);
     }
}

int dfn[maxn],low[maxn];
int idx,bcc_cnt;
stack<int> sta;
int color[maxn];
vector<int> bcc[maxn];
int root;
bool iscut[maxn];

void tarjan_init(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    idx = bcc_cnt = root = 0;
    while( !sta.empty()) sta.pop();
    memset(color,0,sizeof(color));
    memset(iscut,0,sizeof(iscut));
}

void tarjan(int u){
    dfn[u] = low[u]  = ++idx;
    int i,child=0;
    for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
        int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
        if( !dfn[v]){
            sta.push(i);
            child++;
            tarjan(v);
            low[u] = min(low[u],low[v]);
            if( low[v] >= dfn[u] && u != root) iscut[u] = 1;
            if( low[v] >= dfn[u] ){
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                while(1){
                    int i = sta.top(); sta.pop();
                    int uu = xlx1::e[i].u,vv=xlx1::e[i].v;
                    if( color[uu] != bcc_cnt){
                        bcc[bcc_cnt].push_back(uu);
                        color[uu] = bcc_cnt;
                    }
                    if( color[vv] != bcc_cnt){
                        bcc[bcc_cnt].push_back(vv);
                        color[vv] = bcc_cnt;
                    }
                    if( uu == u && vv == v) break;
                }
            }
        }
        else low[u] = min(low[u],dfn[v]);
    }
    if( u == root && child > 1)
        iscut[u] = 1;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    //
    while( 1){
        scanf("%d",&n);
        if( n == 0) break;
        in_case++;
        init();
        tarjan_init();
        int i;
        for( i =1;i<=n;i++){
            if( !dfn[i]){
                root = i;
                tarjan(i);
            }
        }
        if( bcc_cnt == 1){
            int num = 0;
            memset(dot,0,sizeof(dot));
            int i;
            For(i,1,xlx1::edge_cnt){
                int u = xlx1::e[i].u;
                int v = xlx1::e[i].v;
                if( !dot[u]) dot[u] = 1,num++;
                if( !dot[v]) dot[v] = 1,num++;
            }
            long long ans = (num*(num-1)) >>1;
            printf("Case %d: %d %lld\n",in_case,2,ans);
        }
        else {
            long long ans = 1;
            long long ans1 = 0;
            int i,j;
            for( i =1;i<=bcc_cnt;i++){
                int cnt = 0;
                for (const auto& e : bcc[i]) {
                    if( iscut[e]) cnt++;
                }
                if( cnt == 1){
                    ans1++;
                    ans *= (bcc[i].size()-1);
                }
            }
            printf("Case %d: %lld %lld\n",in_case,ans1,ans);
        }
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
