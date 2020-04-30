/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Tue 31 Mar 2020 06:39:31 PM CST
* problem:  loj-10105
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int T;
int n,m;
int start = 1000000;

int in[maxn],out[maxn];

/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline init(){ edge_cnt = -1; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
}
/* ========= 向量星 1 END =========*/

/* ======= 全局变量 END =======*/
void init(){
     xlx1::init(); 
     scanf("%d%d%d",&T,&n,&m);
     int i,u,v;
     For(i,1,m){
         scanf("%d%d",&u,&v);
         out[u]++;
         in[v]++;
         xlx1::addEdge(u, v);
         if( T == 1)
             xlx1::addEdge(v, u);
     }
}

bool vis[maxe];
stack<int> sta,ans;
stack<int> esta;

void Euler(int s){
    sta.push(s);
    while( !sta.empty() ){
        int x = sta.top(),i = xlx1::head[x];
        while( ~i && vis[i] ) i = xlx1::e[i].next;
        if( ~i ){
            int c = T == 1 ? (i/2)+1 : i+1;
            if( T == 1 && i %2 == 1) c = -c;
            esta.push(c);
            sta.push(xlx1::e[i].v);
            xlx1::head[x] = xlx1::e[i].next;
            vis[i] = 1;
            if( T ==1)
                vis[i^1] = 1;
        }
        else {
            sta.pop();
            if( !esta.empty()){
                ans.push(esta.top());
                esta.pop();
            }
        }
    }
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i;
    if( T == 1){
        For(i,1,n){
            //无向图 度为偶数
            if( (in[i]+out[i]) % 2 ==1){
                printf("NO");
                return 0;
            }
        }
        For(i,1,n){
            if( in[i]+out[i] !=0){
                start = i;
                break;
            }

        }
    }
    else {
            //有向图 入度等于出度
            For(i,1,n){
                if(in[i] != out[i]){
                    printf("NO");
                    return 0;
                }
            }
            For(i,1,n){
                if(in[i] != 0){
                    start = i;
                    break;
                }
            }

    }
    if( start != 1000000 )
        Euler(start);
    if( ans.size() != m){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    while(!ans.empty()){
        printf("%d ",ans.top());
        ans.pop();
    }
    printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
