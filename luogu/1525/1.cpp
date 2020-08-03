#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int _min = 999999999;
#define MAX(A,B) (A> B ?A : B)
const int maxn = 20005;
const int maxm = 1e5+5;


int n,m;

bool color[maxn];
bool vis[maxn];
int _max=-1;
/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[maxm<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}

/* 函数重载 */
void addEdge(int u,int v){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/


void init(){
    xlx_init();
    scanf("%d%d",&n,&m);
    int i,j;
    int a,b,c;
    for(i=1;i<=m;++i){
        scanf("%d%d%d",&a,&b,&c);
        addEdge(a,b,c);
        addEdge(b,a,c);
        _max = MAX(_max,c);
        _min = min(_min,c);
    }
}



bool dfs(int u,bool pre,int val){
    vis[u] = 1;
    color[u] = !pre;

    int i;
    for(i= head[u]; ~i; i= e[i].next){
        int v = e[i].v;
        int w = e[i].w;
        if( w <= val )  continue;
        if( !vis[v]){
            if( !dfs(v,color[u],val) )
                return 0;
        }
        else if( color[v] == color[u])
                return 0;
    }
    return 1;
}

bool check(int val){
    memset(color,0,sizeof(color));
    memset(vis,0,sizeof(vis));
    int i;
    for( i =1;i<=n;i++){
        if(!vis[i]){
            if( !dfs( i,0,val))
                return 0;
        }
    }
    return 1;
}

int first_ge(){
    int l = 0 ,r = _max;

    while( l < r){
        int m = (l + r ) >>1;

        if( !check(m)){
            l = m+1;
        }
        else 
            r = m;
    }
    return l;
}


int main(){
    init();
    int ans = first_ge();
    printf("%d\n",ans);
    printf("%d\n",_min);
    return 0;
}

