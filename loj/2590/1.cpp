
/* 
 * 建立一个基于的类与模板的 向量星
 * */

/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 09日 星期四 10:14:11 CST
*----------------*/
#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

#define maxn 100005
#define maxe 500005

int n,m;
int price[maxn];
int color[maxn];


int _max[maxn]; //高价
int _min[maxn]; //低价

int f[maxn]; //表示从1号连通量 到当前的最小值
int dp[maxn]; //表示从1号连通量 到当前点的最大收益
int flag[maxn];

struct xlx{
    int edge_cnt=0;
    vector<int> head;
    vector<int> V;
    vector<int> U;
    vector<int> W;
    vector<int> next;

    /* 构造函数,点的数量 */
    xlx(int n){
        head = vector<int> (n,-1);
    }

    void add_edge(int u,int v,int w){
        U.push_back(u);
        V.push_back(v);
        W.push_back(w);
        next.push_back( head[u]);
        head[u] = edge_cnt;
        edge_cnt++;
    }

    void add_edge(int u,int v){
        U.push_back(u);
        V.push_back(v);
        next.push_back( head[u]);
        head[u] = edge_cnt;
        edge_cnt++;
    }
};

xlx x1(maxn);
xlx x2(maxn);
xlx x3(maxn);


int dfn[maxn],low[maxn],vis[maxn],idx=0;
bool instack[maxn];
int cnt = 0;
stack<int> sta;

void tarjan(int u){
    vis[u] = 1;
    dfn[u] = low[u] = ++idx;
    instack[u] = 1;

    sta.push(u);

    int i;
    for(i= x1.head[u];i!=-1;i=x1.next[i]){
        int v = x1.V[i];
        if(vis[v] == 0){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if( instack[v]){
            low[u] = min(low[u],dfn[v]);
        }
    }

    if( dfn[u] == low[u]){
        cnt++;
        int t = -1;
        while(t !=u){
            t = sta.top();
            instack[t] = false;
            color[t] = cnt;
            sta.pop();
        }
    }
}

vector<int> _sort;
void top_sort(int u){
    vis[u] = 1;
    int i;
    for (i=x2.head[u]; i!=-1;i=x2.next[i]){
        int v = x2.V[i];
        if(vis[v] == 0)
            top_sort(v);
    }
    _sort.push_back(u);
}

void init(){
    memset(_min,0x7f,sizeof(_min));
    memset(_max,-1,sizeof(_max));
    memset(f,0x7f,sizeof(f));

    scanf("%d%d",&n,&m);
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&price[i]);
    }
    int t1,t2,t3;
    for (i=1;i<=m;i++){
        scanf("%d%d%d",&t1,&t2,&t3);
        x1.add_edge(t1,t2);
        if( t3 > 1)
            x1.add_edge(t2,t1);
    }
    
}

int main(){
    init();
    int i,j;
    for (i=1;i<=n;i++){
        if( !dfn[i])
            tarjan(i);
    }

    /* 计算连通量下的 _max _min */
    for (i=1;i<=n;i++){
        int col = color[i];
        _max[col] = max(_max[col],price[i]);
        _min[col] = min(_min[col],price[i]);
    }

    /* 建立图 */
    for(i=0;i<x1.edge_cnt;i++){
        int u = x1.U[i];
        int v = x1.V[i];
        if( color[u] !=color[v]){
            x2.add_edge(color[u],color[v]);
            x3.add_edge(color[v],color[u]);
        }
    }

    memset(vis,0,sizeof(vis));
    for(i=1;i<= cnt;i++){
        if( vis[i] == 0)
            top_sort(i);
    }

    std::reverse(_sort.begin(),_sort.end());
    /*
     *for( auto x : _sort)
     *    printf("%d ",x);
     */
    
    /* 进行dp */

    flag[color[1]] = 1;
    f[color[1]] = _min[color[1]];
    dp[color[1]] = _max[color[1]] - _min[color[1]];

    for(i=2;i<=cnt;i++){

        int u = _sort[i];

        for(j= x3.head[u];j!=-1;j=x3.next[j]){
            int v = x3.V[j];
            if( flag[v]){
                f[u] = min(f[v],_min[u]);
                int t = max(dp[v],_max[u] - f[u]);
                dp[u] = max(dp[u],t);
                flag[u] = 1;
            }
        }

        if( u == color[n])
            break;
    }
    printf("%d",dp[color[n]]);
    return 0;
}
