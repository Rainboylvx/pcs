#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int T,n,tot;
int r[10000],t[10005],g[10000],head[10000];
struct node
{
	int v,w,nex;
}edge[1000001];
void Add(int x,int y,int z)
{
	edge[++tot].nex=head[x];edge[tot].v=y;edge[tot].w=z;head[x]=tot;
}
void dos(int x)
{
	memset(head,0,sizeof(head));
    Add(0,24,x);
	for(int i=1;i<=24;i++)
	{
		Add(i-1,i,0);
		Add(i,i-1,-g[i]);
	} 
	for(int i=1;i<=16;i++)
	{
		Add(i,i+8,r[i+8]);
	}
	for(int i=17;i<=24;i++)
	{
		Add(i,i-16,r[i-16]-x);
	}
}
queue<int>q;
int dis[100],num[100];
bool vis[100];
bool SPFA(int x)
{
	memset(dis,-0x7f,sizeof(dis));
	memset(num,0,sizeof(num));
	memset(vis,0,sizeof(vis));
	while(!q.empty()) q.pop();
	dis[0]=0;
	q.push(0);
	vis[0]=1;
	num[0]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nex)
		{
			int y=edge[i].v,z=edge[i].w;
			if(dis[y]<dis[u]+z)
			{
				dis[y]=dis[u]+z;
					num[y]++;
					if(num[y]>24) return 0;
				if(!vis[y]) 
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	//printf("%d\n",dis[24]);
	if(dis[24]==x) return 1;
	return 0;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=24;i++)	scanf("%d",&r[i]),g[i]=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&t[i]);
			g[t[i]+1]++;
		}
		bool flag=0;
		for(int i=0;i<=n;i++)
		{
			tot=0;
			dos(i);
			if(SPFA(i))
			{
				printf("%d\n",i);
				flag=1;
                break;
			}
		}
		if(!flag) printf("No Solution\n"); 
	}
	return 0;
} 
