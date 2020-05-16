/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 12日 星期二 20:32:19 CST
* problem: loj-10066
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


/* ================= 并查集 =================*/
namespace BCJ {
    int fa[maxn];
    inline void bcj_init(int x){ for(int i=0;i<=x;i++) fa[i] = i; }
    int find(int x){ if( x == fa[x]) return x; return fa[x] = find(fa[x]); }
    void merge(int x,int y){ fa[find(x)] = find(y); }
}
/* ================= 并查集 end =================*/


// 传入点数，返回mst的值，不连通返回-1
namespace Kruskal {
    using namespace xlx1;
    bool cmp( _e a,_e b) {return a.w < b.w;}
    int work(int n){
        BCJ::bcj_init(n); //初始化
        sort(e+1,e+1+edge_cnt,cmp); //对边从小到大排序
        int ans = 0,cnt = 0; //答案，选边的数量
        n++; //多了个超级点 0

        for(int i = 1; i<=edge_cnt ; ++i){
            int u =e[i].u, v =e[i].v, w =e[i].w; 
            int f1 =BCJ::find(u),f2 = BCJ::find(v);
            if( f1 != f2){ //不再同一个集合
                //printf("%d %d %d\n",u,v,w);
                ans+=w;
                cnt++;
                BCJ::fa[f2] = f1;
            }
            if( cnt == n-1) break;
        }
        if( cnt < n -1) return -1;
        return ans;
    }
}

void init(){
     xlx1::xlx_init(); 
     scanf("%d",&n);
     int i,j;
     int u,v,w;
     For(i,1,n){
         scanf("%d",&w);
         addEdge(0,i,w);
     }
     For(i,1,n){
         For(j,1,n){
             scanf("%d",&w);
             if( i < j){
                 addEdge(i, j,w);
             }
         }
     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ans = Kruskal::work(n);
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
