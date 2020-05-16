// ========== tarjan 求强连通分量
namespace Tarjan_QLT {
    int dfn[maxn],low[maxn],color[maxn];
    bool instack[maxn];
    int idx,color_cnt;
    std::stack<int> sta;
    void init(){
        memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));
        memset(instack,0,sizeof(instack));
        color_cnt = idx = 0;
    }
    void tarjan(int u){
        dfn[u] = low[u] = ++idx;
        sta.push(u);
        instack[u] = 1;
        int i;
        for( i =head[u]; ~i ;i = e[i].next){
            int &v = e[i].v;
            if( !dfn[v]){ //没有访问过
                tarjan(v);
                low[u] = std::min(low[u],low[v]); //<u,v> 是树边
            }
            else if( instack[v]){ //已经访问,且未输出
                low[u] = std::min(low[u],dfn[v]);
            }
        }

        //强连通分量子树的跟
        if( dfn[u] == low[u]){
            color_cnt++;
            int t = -1;
            do {
                t = sta.top(); sta.pop();
                instack[t] = 0;
                color[t] = color_cnt;
            }
            while( t != u);
        }
    }
    void work(int n){
        int i;
        for( i =1;i<=n;i++){
            if( !dfn[i]) tarjan(i);
        }
    }
}
// ========== tarjan 求强连通分量 END
