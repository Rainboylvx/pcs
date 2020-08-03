#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define inf 0x3f3f3f3f
#define MAXN 100005
#define ll long long
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
    int n,m,s,t,k;
int tot,head[MAXN],rhead[MAXN],x,y,z,cnt[MAXN],dis[MAXN];
bool vis[MAXN];
struct Edge{
    int to,next,w;
}edge[MAXN],redge[MAXN];
void addegde(int u,int v,int w){
    edge[tot].to=v;edge[tot].w=w;edge[tot].next=head[u];head[u]=tot;
    redge[tot].to=u;redge[tot].w=w;redge[tot].next=rhead[v];rhead[v]=tot++;
}
struct node{
    int x,w;
    node(int x,int w):x(x),w(w){}
    friend bool operator<(node n1,node n2){
        return n1.w+dis[n1.x]>n2.w+dis[n2.x];
    }
};
priority_queue<node>q;
queue<int>que;

void dijkstra(int s){
    typedef pair<int,int> pairI;
    priority_queue<pairI, vector<pairI>, greater<pairI> > q;
    memset(dis,0x3f,sizeof(dis));
    /* memset(vis,0,sizeof(vis)); */
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int now=q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        int i;
        for(i=rhead[now];i !=-1 ;i = redge[i].next){
            int v= redge[i].to;
            if( dis[v] > dis[now]+redge[i].w){
                dis[v] = dis[now]+redge[i].w;
                q.push(make_pair(dis[v], v));
            }
        }

    }
}

int astar_Kshort_path(int s){
    priority_queue< node> q;
    int cnt=0;
    if( s == t) k++;

    while( !q.empty()){
    }
    return -1;

}
int main(){
    while(~scanf("%d%d",&n,&m)){
        tot=0;
        memset(head,-1,sizeof(head));
        memset(rhead,-1,sizeof(rhead));
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            addegde(x,y,z);
        }
        scanf("%d%d%d",&s,&t,&k);
        dijkstra(t);
        if(dis[s]==inf){
            printf("-1\n");
            continue;
        }
        int ans = astar_Kshort_path();
        printf("%d\n",ans);
    }
    return 0;
}
