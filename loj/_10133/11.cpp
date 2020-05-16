/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 13日 星期三 22:16:17 CST
* problem:  loj-10133
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

/* ========= 向量星 2 =========*/
namespace xlx2 {
    int head[maxn],edge_cnt = 0;
    struct _e{ int u,v,w,next; }e[maxe];
    void inline xlx_init(){ edge_cnt = 0; memset(head,-1,sizeof(head)); } 
    void addEdge(int u,int v,int w=0){ e[++edge_cnt] = { .u = u,.v=v,.w=w,.next =head[u]}; head[u] = edge_cnt; }
    void add(int u,int v,int w=0){ addEdge(u, v,w); addEdge(v, u,w);}
}
/* ========= 向量星 2 END =========*/

void init(){
    using namespace xlx1;
     xlx1::xlx_init(); 
     scanf("%d%d",&n,&m);
     int i,j;
     int u,v,w;
     For(i,1,m){
         scanf("%d%d%d",&u,&v,&w);
         addEdge(u, v,w);
     }
}

/* ================= 并查集 =================*/
namespace BCJ {
    int fa[maxn];
    inline void bcj_init(int x){ for(int i=1;i<=x;i++) fa[i] = i; }
    int find(int x){ if( x == fa[x]) return x; return fa[x] = find(fa[x]); }
    void merge(int x,int y){ fa[find(x)] = find(y); }
}
/* ================= 并查集 end =================*/



/* ============  树上倍增 BEG ============ */
namespace bz_tree {
    using namespace xlx2;
    const int size = 19;
    int f[maxn][size+1],dep[maxn];
    int m[maxn][size+1]; // 区间的最大值
    int m2[maxn][size+1]; // 区间的第2大值
    void dfs(int u,int fa,int w){
        dep[u] = dep[fa]+1, f[u][0] = fa;
        m[u][0] = w,m2[u][0] = 0;
        for(int i = 1;i <= size ; ++i){
            f[u][i] = f[f[u][i-1]][i-1];
            m[u][i] = max(m[u][i-1],m[f[u][i-1]][i-1]);
            m2[u][i] = max(m2[u][i-1],m2[f[u][i-1]][i-1]);
            if( m[u][i] == m[u][i-1])
                m2[u][i] = max(m2[u][i],m[f[u][i-1]][i-1]);
            else
                m2[u][i] = max(m2[u][i],m[u][i-1]);
        }
        for(int i= head[u]; ~i ;i = e[i].next) if( e[i].v != fa) {
            dfs(e[i].v,u,e[i].w);
        }
    }

    pair<int,int> find_lca(int u,int v){
        if(dep[u] < dep[v]) std::swap(u,v); // 让u的深度大
        int _max = 0,_max2=0;
        int pre_max = 0;
        for(int i=size; i>=0 ; --i)  //跳到同一层
            if( dep[f[u][i]] >= dep[v] ) {
                //do somthing here
                _max = max(_max,m[u][i]);
                pre_max = _max;
                _max2 = max(_max2,m2[u][i]);
                u = f[u][i];
            }
        if( u == v) return {_max,_max2}; //在一条线上
        for(int i = size; i>=0; --i){
            if( f[u][i] != f[v][i]){
                //do somthing here
                _max = max(_max,m[u][i]);
                _max = max(_max,m[v][i]);
                _max2 = max(_max2,m2[u][i]);
                _max2 = max(_max2,m2[v][i]);
                if(_max == pre_max){
                    _max2 = max(_max2,m[u][i]);
                    _max2 = max(_max2,m[v][i]);
                }
                else if( _max == m[u][i]){
                    _max2 = max(_max2,pre_max);
                    _max2 = max(_max2,m[v][i]);
                }
                else {
                    _max2 = max(_max2,pre_max);
                    _max2 = max(_max2,m[u][i]);
                }
                u = f[u][i], v = f[v][i];
            }
        }
        //return f[u][0];
        _max = max(_max,m[u][0]);
        _max = max(_max,m[v][0]);
        if(_max == pre_max){
            _max2 = max(_max2,m[u][0]);
            _max2 = max(_max2,m[v][0]);
        }
        else if( _max == m[u][0]){
            _max2 = max(_max2,pre_max);
            _max2 = max(_max2,m[v][0]);
        }
        else {
            _max2 = max(_max2,pre_max);
            _max2 = max(_max2,m[u][0]);
        }

        return {_max,_max2};
    }
}
/* ============  树上倍增 END ============ */

namespace sec_mst {
    using namespace xlx1;
    using namespace BCJ;
    bool choose[maxe]; //选中为mst上的边
    vector<int> v[maxn]; // 每个BCJ集合
    bool cmp( _e a,_e b) {return a.w < b.w;}
    long long kruskal(int n){
        xlx2::xlx_init(); 
        for(int i = 1;i<=edge_cnt ;++i) { fa[i] = i; v[i].push_back(i);}
        sort(e+1,e+1+edge_cnt,cmp); //对边从小到大排序
        long long ans = 0,cnt = 0; //答案，选边的数量
        for(int i = 1; i<=edge_cnt ; ++i){
            int u =e[i].u, v =e[i].v, w =e[i].w; 
            int f1 =find(u),f2 = find(v);
            if( f1 != f2){    //不再同一个集合
                ans+=w; cnt++; choose[i] = 1;
                fa[f2] = f1;
                //printf("%d %d\n",u,v);
                xlx2::add(u,v,w); //建立新的树
            }
            if( cnt == n-1) break;
        }
        if( cnt < n -1) return -1;
        return ans;
    }
    long long sec_mst(int n){
        long long mst = kruskal(n);
        printf("mst = %lld\n",mst);
        bz_tree::dfs(1, 0,0);  // 建立 倍增树
        int inc = 0x7fffffff;
        for( int i =1;i<=edge_cnt;i++){
            if( choose[i]) continue;
            int u = e[i].u,v = e[i].v,w = e[i].w;
            pair<int,int> _m = bz_tree::find_lca(u, v);
            printf("%d %d %d %d %d\n",u,v,w,_m.first,_m.second);
            if(w == _m.first) inc = min(inc,w-_m.second);
            else inc = min(inc,w-_m.first);
            printf("----> inc  %d\n",inc);
        }
        printf("%lld\n",mst+inc);
        return -1;
    }
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    sec_mst::sec_mst(n);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
