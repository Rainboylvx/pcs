/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 23日 星期六 23:45:52 CST
* problem:  loj-10136
*----------------*/
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(3,"Ofast","inline")
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-fhoist-adjacent-loads")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 5e5+5;
const int maxe = 1e6+5;
int n,m;

int read() {
    int s = 0;
    bool f = false;
    char c = getchar();
    while (c < '0' || c > '9')
        f |= (c == '-'), c = getchar();
    while (c >= '0' && c <= '9')
        s = (s << 3) + (s << 1) + (c ^ 48), c = getchar();
    return f ? -s : s;
}

/* ======= 全局变量 END =======*/
/* ========= 向量星 1 =========*/
namespace xlx1 {
    int head[maxn],edge_cnt = 1;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt++; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 1 END =========*/
using namespace xlx1;
//============= 树上倍增 BEG
int lca;
namespace BZ_LCA {
    const int SIZ = 19;
    int f[maxn][SIZ+1],len[maxn][SIZ+1],dep[maxn];
    using namespace xlx1;
    void dfs_init(int u ,int d,int fa,int w=0){
        dep[u] = d; f[u][0] = fa; len[u][0] = w;
        for(int i= 1;i<=SIZ;++i){
            f[u][i] = f[f[u][i-1]][i-1];
            //len[u][i] = len[u][i-1]+len[f[u][i-1]][i-1];
        }
        for(int i=head[u];i;i=e[i].next){
            int v =e[i].v ;//w = e[i].w;
            if( v == fa) continue;
            dfs_init(v,d+1,u,w);
        }
    }
    int find_lca(int u,int v){
        if( dep[u] < dep[v]) swap(u,v); //保证u点的深度深
        for(int i=SIZ;i>=0;--i){
            if( dep[f[u][i]] < dep[v]) continue; //不跳的区域
            u = f[u][i];
        }
        if(u == v) return u;
        for(int i=SIZ;i>=0;--i){
            if( f[u][i] == f[v][i] ) continue;
            u = f[u][i]; v = f[v][i];
        }
        return f[u][0];
    }
    int get_dis_normal(int u,int v,int lca){ return dep[u]+dep[v]-(dep[lca]<<1); }
    int get_dis(int u,int v){
        int sum = 0;
        if( dep[u] < dep[v]) swap(u,v); //保证u点的深度深
        for(int i=SIZ;i>=0;--i){
            if( dep[f[u][i]] < dep[v]) continue; //不跳的区域
            sum+=len[u][i];
            u = f[u][i];
        }
        if(u == v) {lca = u;return sum;}
        for(int i=SIZ;i>=0;--i){
            if( f[u][i] == f[v][i] ) continue;
            sum+=len[u][i];
            sum+=len[v][i];
            u = f[u][i];
            v = f[v][i];
        }
        lca = f[u][0];
        return sum+len[u][0]+len[v][0];
    }
}
//============= 树上倍增 END

void init(){
     //xlx1::xlx_init(); 
     //scanf("%d%d",&n,&m);
     n = read(); m = read();
     int i,u,v;
     For(i,1,n-1){
         //scanf("%d%d",&u,&v);
         u = read(); v= read();
         add(u, v);
     }
     using namespace BZ_LCA;
     dfs_init(1, 1, 0,1);
     int t;
     For(i,1,m){
         //scanf("%d%d%d",&u,&v,&t);
         u=read();v = read();t = read();
         int NODE,ans,tlca;
         int a1,a2,a3,tsum;
         int tt;

         tlca= find_lca(u, v);
         lca = find_lca(t, tlca);
         tsum = get_dis_normal(u, v, tlca) + get_dis_normal(t,tlca,lca);
         NODE = tlca;

         tlca= find_lca(u, t);
         lca = find_lca(v, tlca);
         tt = get_dis_normal(u, t, tlca) + get_dis_normal(v,tlca,lca);
         if( tt < tsum){
             tsum = tt;
             NODE = tlca;
         }

         tlca= find_lca(v, t);
         lca = find_lca(u, tlca);
         tt = get_dis_normal(v, t, tlca) + get_dis_normal(u,tlca,lca);
         if( tt < tsum){
             tsum = tt;
             NODE = tlca;
         }

         printf("%d %d\n",NODE,tsum);

     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
