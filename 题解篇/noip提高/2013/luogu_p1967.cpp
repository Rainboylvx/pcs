#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量
int n,m,q;


//链式前向星存树
struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    void add(int u,int v,int w=0){
        e[edge_cnt] = {u,v,w,h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u,int v,int w=0){
        add(u,v,w); add(v,u,w);
    }
    edge& operator[](int i) {
        return e[i];
    }
} e;

using edge = linkList::edge;
edge e2[maxe]; //next 是边的id
int edge_idx; //存边


struct Lca {
    int N,d[maxn],f[maxn][50]; //f[i][j] i点的2^j祖先
    int g[maxn][50]; // i 到2^j的祖先上的最大值

    // 初始化，算出的理论跳的最远可能，与f[][]
    inline void init(){
        for(N=0; (1<<(N+1)) < n ;N++);
    }

    //树上的遍历来求 f[][] 与d[]每个点的深度
    void dfs(int u,int fa,int dep){
        d[u] = dep;
        f[u][0] = fa;
        // 显示u点到root路径上的点都已经求出来f[][]
        for(int j=1;j<=N;++j) f[u][j] = f[ f[u][j-1] ][j-1];
        for(int j=1;j<=N;++j) 
            g[u][j] = std::min(g[u][j-1],g[ f[u][j-1] ][j-1]);
        for(int i=e.h[u];~i;i=e[i].next){
            int &v = e[i].v;
            if( v == fa) continue; //是父亲 就什么也不做
            g[v][0] = e[i].w; //设定 到父亲的距离
            dfs(v,u,dep+1);
        }
    }

    int work(int a,int b){
        if( d[a] > d[b]) swap(a,b); //保证b是深的点
        int ret = 0x7f7f7f7f;
        for(int i=N;i>=0;--i){ // b 跳到和a一样深
            if( d[ f[b][i] ] >= d[a]) // a深度以下是可行区域,包括a
            {
                // 某个点向上跳
                ret = std::min(ret,g[b][i]);
                b = f[b][i];
            }
        }
        if( a == b) return ret; //在同一条链上

        for(int i=N;i>=0;--i){ // 同时跳
            if( f[a][i] != f[b][i] ){ //不相同就跳
                                      //
                ret =  std::min(ret,g[a][i]);
                ret =  std::min(ret,g[b][i]);
                a = f[a][i];
                b = f[b][i];

        }
        }

        ret =  std::min(ret,g[a][0]);
        ret =  std::min(ret,g[b][0]);
        return ret;
        // return f[a][0]; //返回停下来时候的父亲，就是lca
    }
} lca;

void init() {
    //读取
    std::cin >> n >> m;
    int u,v,w;
    for(int i=1;i<=m;++i){
        std::cin >> u >> v >> w;
        // e.add2(u,v,w);
        // int e_id = e.edge_cnt-1; //最后一条边的编号
        e2[i] = {u,v,w,1};
    }
    std::cin >> q;
}

//并查集
template<int size>
struct DisjointSet {
    int fa[size+5];
    DisjointSet() { 
        for(int i=0;i<size+5;++i)
            fa[i] = i;
    }
    int find(int u){
        if( u  == fa[u]) return u;
        return fa[u] = find(fa[u]);
    }
    inline void merge(int u,int v){
        int rx = find(u);
        int ry = find(v);
        if( rx != ry)
            fa[rx] = ry;
    }
};

DisjointSet<maxn> joinSet;

void Kruskal(){
    for(int i =1 ;i<=m ;i++){ //遍历每条边
        int u =e2[i].u, v =e2[i].v, w =e2[i].w; 
        int eid = e2[i].next;

        int f1 =joinSet.find(u),f2 = joinSet.find(v);
        if( f1 != f2){ //不再同一个集合
            e.add2(e2[i].u,e2[i].v,e2[i].w);
            //选这条边
            // std::cout << u <<" "<< v <<" "<< w << std::endl;
            joinSet.fa[f2] = f1;
        }
    }
}


int main(){
    init(); //读取数据
    std::sort(e2+1,e2+m+1, [](edge& a,edge& b){
            return a.w > b.w;
    }); //边从大到小排序
    

    //对所有的边一起做 Kruskal
    //虽然这些图可以不连通,但不影像结果

    Kruskal();

    // 记录每个点父亲 fa[i]
    // 记录每个点到父亲的距离 fa[i]
    lca.init(); //初始化
    for(int i =1;i<=n;i++) {
        if( lca.d[i] == 0) { //没有访问过
            lca.dfs(i, 0, 1); //这里点的父亲必须是0!!!
        }
    }

    for(int i=1;i<=q;++i){
        int u,v;
        std::cin >> u >> v;
        if( joinSet.find(u) != joinSet.find(v) ) {
            std::cout << -1 << "\n";
        }
        else { //查询
            int ans = lca.work(u, v);
            std::cout << ans << "\n";

        }
    }
    return 0;
}


