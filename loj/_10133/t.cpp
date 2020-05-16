const int maxn = 1e5+5;
/* ============  树上倍增 BEG ============ */
namespace bz {
    using namespace xlx1;
    const int size = 19;
    int f[maxn][size],dep[maxn];
    void dfs(int u,int fa){
        dep[u] = dep[fa]+1, f[u][0] = fa;
        for(int i = 0;i <= size ; ++i) f[u][i+1] = f[f[u][i]][i];
        for(i= head[u]; ~i ;i = e[i].next) if( e[i].v != fa) dfs(e[i].v,u);
    }

    int find_lca(int u,int v){
        if(dep[u] < dep[v]) std::swap(u,v); // 让u的深度大
        for(int i=size; i>=0 ; --i)  //跳到同一层
            if( dep[f[u][i]] >= dep[v] ) {
                //do somthing here
                u = f[u][i];
            }
        if( u == v) return u; //在一条线上
        for(int i = size; i>=0; --i){
            if( f[u][i] != f[v][i]){
                //do somthing here
                u = f[u][i], v = f[v][i];
            }
        }
        return f[u][0];
    }
}
/* ============  树上倍增 END ============ */
