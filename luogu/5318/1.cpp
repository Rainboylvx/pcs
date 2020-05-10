#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

struct {int v,next;} e[maxe];
int head[maxn];
int edge_cnt=0;

void addedge(int u,int v){
    e[++edge_cnt] = { v,head[u]};
    head[u] = edge_cnt;
}

struct node {int u,v;} a[maxe];

bool cmp(node a,node b){
    if( a.u == b.u) return a.v > b.v;
    return a.u > b.u;
}

bool vis[maxn];

void dfs(int u){
    vis[u] = 1;
    printf("%d ",u);
    for( int i = head[u] ; i!=-1 ;i = e[i].next){
        int v = e[i].v;
        if( vis[v]) continue;
        dfs(v);
    }
}

void bfs(int s){
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    while( !q.empty()){
        int u = q.front(); q.pop();
        printf("%d ",u);
        for(int i = head[u] ;i !=-1 ;i = e[i].next){
            int v = e[i].v;
            if( vis[v]) continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}


int main(){
    memset(head,-1,sizeof(head));
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=m;++i){
        scanf("%d%d",&a[i].u,&a[i].v);
    }
    sort(a+1,a+m+1,cmp);
    for(i=1;i<=m;++i){
        //printf("%d %d\n",a[i].u,a[i].v);
        addedge(a[i].u, a[i].v);
    }
    dfs(1);
    printf("\n");
    memset(vis,0,sizeof(vis));
    bfs(1);
    return 0;
}

