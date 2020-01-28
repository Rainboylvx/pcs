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
int tot,head[MAXN],rhead[MAXN],x,y,z,cnt[MAXN],dist[MAXN];
bool vis[MAXN];
struct Edge{
    int to,next,w;
}edge[MAXN],redge[MAXN];
void addegde(int u,int v,int w){
    edge[tot].to=v;edge[tot].w=w;edge[tot].next=head[u];head[u]=tot;
    redge[tot].to=u;redge[tot].w=w;redge[tot].next=rhead[v];rhead[v]=tot++;
}
struct node{
    friend bool operator<(node n1,node n2){
        return n1.dist>n2.dist;
    }
    int x,dist;
};
priority_queue<node>q;
queue<int>que;
bool spfa(int s,int n){
    memset(vis,false,sizeof(vis));
    rep(i,1,n)dist[i]=inf;
    vis[s]=true;
    dist[s]=0;
    while(!que.empty())que.pop();
    que.push(s);
    memset(cnt,0,sizeof(cnt));
    cnt[s]=1;
    while(!que.empty()){
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=rhead[u];i!=-1;i=redge[i].next){
            int v=redge[i].to;
            if(dist[v]>dist[u]+redge[i].w){
                dist[v]=dist[u]+redge[i].w;
                if(!vis[v]){
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>n)return false;
                }
            }
        }
    }
    return true;
}
int main(){
    int n,m,s,t,k;
    while(~scanf("%d%d",&n,&m)){
        tot=0;
        memset(head,-1,sizeof(head));
        memset(rhead,-1,sizeof(rhead));
        while(m--){
            scanf("%d%d%d",&x,&y,&z);
            addegde(x,y,z);
        }
        scanf("%d%d%d",&s,&t,&k);
        spfa(t,n);
        if(dist[s]==inf){
            printf("-1\n");
            continue;
        }
        while(!q.empty())q.pop();
        node a;
        a.x=s,a.dist=dist[s];q.push(a);
        int ans=-1,num=0;
        if(s==t)k++;
        while(!q.empty()){
            node temp=q.top(),jiang;
            q.pop();
            if(temp.x==t){
                num++;
                if(num==k){
                    ans=temp.dist;
                    break;
                }
            }
            for(int i=head[temp.x];i!=-1;i=edge[i].next){
                int v=edge[i].to;
                jiang.x=v,jiang.dist=temp.dist-dist[temp.x]+dist[v]+edge[i].w;
                q.push(jiang);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
