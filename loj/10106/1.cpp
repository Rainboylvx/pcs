/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 01 Apr 2020 05:32:08 PM CST
* problem: loj-10106
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = -1; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 1 END =========*/
using namespace xlx1;

/* ======= 全局变量 END =======*/
char str[100000];
int in[maxn],out[maxn];
bool flag = 1;
int oi,oo;
bool vis[maxn];
void init(){
    flag = 1;
    oi = oo = 0;
    memset(vis,0,sizeof(vis));
    xlx1::xlx_init();
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%s",str);
        int len = strlen(str);
        int u = str[0] - 'a';
        int v = str[len-1] - 'a';
        addEdge(u, v);
        out[u]++;
        in[v]++;
    }
    int cnt_1=0,cnt_ng = 0;
    for( i = 0;i<= 25;i++){
        if( out[i] != in[i]){
            if( out[i] - in[i] == 1){
                cnt_1++;
                oo = i;
                if( cnt_1 > 1) { flag = 0;return;}
            }
            else if( out[i]- in[i] == -1){
                cnt_ng++;
                if( cnt_ng > 1) { flag = 0;return;}
            }
            else{
                flag = 0;
                return;
            }
        }
    }
}

void dfs(int u){
    vis[u] = 1;
    int i;
    for(i= xlx1::head[u]; ~i ;i = xlx1::e[i].next){
        int &v = xlx1::e[i].v; int &w = xlx1::e[i].w;
        if( !vis[v]){
            dfs(v);
        }
    }
}

void check(){
    int i;
    For(i,0,25){
        if( in[i] && !vis[i]){
            printf("The door cannot be opened.\n");
            return;
        }
    }
    printf("Ordering is possible.\n");
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while( t-- ){
        init();
        if( flag ){
            dfs(oo);
            check();
        }
        else
            printf("The door cannot be opened.\n");
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
