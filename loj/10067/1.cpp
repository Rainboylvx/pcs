/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 13日 星期三 15:10:56 CST
* problem:  loj-10067
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
int cnt[maxn]; //每个集合点的数量


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
    inline void bcj_init(int x){ for(int i=1;i<=x;i++) fa[i] = i; }
    int find(int x){ if( x == fa[x]) return x; return fa[x] = find(fa[x]); }
    void merge(int x,int y){
        int fx = find(x);
        int fy = find(y);
        if( fx == fy) return;
        fa[fy] =fx;
        cnt[fx] += cnt[fy];
    }
}

/* ================= 并查集 end =================*/

void init(){
    xlx1::xlx_init(); 
    scanf("%d",&n);
    int i,j;
    int u,v,w;
    For(i,1,n-1){
        scanf("%d%d%d",&u,&v,&w);
        addEdge(u, v,w);
    }
}

using namespace BCJ;

bool cmp(_e a,_e b){ return a.w < b.w;}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    bcj_init(n);
    sort(e+1,e+1+edge_cnt,cmp);
    long long ans = 0;
    int i;
    for(i=1;i<=n;++i){ cnt[i] = 1; }
    for( i =1;i<=edge_cnt;i++){
        ans += e[i].w;
        ans += (e[i].w+1)*((ll)cnt[ find(e[i].u) ] * (ll)cnt[ find(e[i].v) ]-1);
        merge(e[i].u,e[i].v);
    }
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
