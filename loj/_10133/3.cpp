#include<cstdio>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
inline int read()
{
	int ret=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9')
		ret=(ret<<1)+(ret<<3)+ch-'0',
		ch=getchar();
	return ret;
}
 
int n,m,cnt,num,t1,t2,ans;
ll s;
const int N=1e6+5;
int ff[N],he[N],to[N],nxt[N],w[N],dep[N];
int lg[N],f[N][21],d1[N][21],d2[N][21];
bool fl[N];
struct NA{
	int u,v,w;
}e[N];
 
bool cmp(NA i,NA j)
{
	return i.w<j.w;
}
 
int find(int x)
{
	return ff[x]==x?x:ff[x]=find(ff[x]);
}
 
inline void add(int u,int v,int k)
{
	to[++cnt]=v;
	nxt[cnt]=he[u];
	w[cnt]=k;
	he[u]=cnt;
}
 
void dfs(int fa,int u)
{
	dep[u]=(!fa)?0:dep[fa]+1;
	f[u][0]=fa;
	for(int i=1;i<=lg[dep[u]];i++)
	{
		f[u][i]=f[f[u][i-1]][i-1];
		d1[u][i]=max(d1[u][i-1],d1[f[u][i-1]][i-1]);
		d2[u][i]=max(d2[u][i-1],d2[f[u][i-1]][i-1]);
		if(d1[u][i-1]!=d1[u][i]) 
			d2[u][i]=max(d2[u][i],d1[u][i-1]);
		if(d1[f[u][i-1]][i-1]!=d1[u][i])
			d2[u][i]=max(d2[u][i],d1[f[u][i-1]][i-1]);
	}
	for(int e=he[u];e;e=nxt[e])
	{
		int v=to[e];
		if(v!=fa)
			d1[v][0]=w[e],
			dfs(u,v);
	}
}
 
void LCA(int u,int v)
{
	if(dep[u]>dep[v]) swap(u,v);
	t1=t2=0;
	while(dep[u]<dep[v])
	{
		if(t1<d1[v][lg[dep[v]-dep[u]]])
			t2=t1,t1=d1[v][lg[dep[v]-dep[u]]];
		else if(t1!=d1[v][lg[dep[v]-dep[u]]])
			t2=max(t2,d1[v][lg[dep[v]-dep[u]]]);
		else t2=max(t2,d2[v][lg[dep[v]-dep[u]]]);
		v=f[v][lg[dep[v]-dep[u]]];
	}
	for(int i=lg[dep[u]];i>=0;i--)
		if(f[u][i]!=f[v][i])
		{
			if(t1<d1[v][i])
				t2=t1,t1=d1[v][i];
			else if(t1!=d1[v][i])
				t2=max(t2,d1[v][i]);
			else t2=max(t2,d2[v][i]);
			v=f[v][i];
			if(t1<d1[u][i])
				t2=t1,t1=d1[u][i];
			else if(t1!=d1[u][i])
				t2=max(t2,d1[u][i]);
			else t2=max(t2,d2[u][i]);
			u=f[u][i];
		}
	if(u!=v) 
	{
		if(t1<d1[v][0])
			t2=t1,t1=d1[v][0];
		else if(t1!=d1[v][0])
			t2=max(t2,d1[v][0]);
		else t2=max(t2,d2[v][0]);
		if(t1<d1[u][0])
			t2=t1,t1=d1[u][0];
		else if(t1!=d1[u][0])
			t2=max(t2,d1[u][0]);
		else t2=max(t2,d2[u][0]);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) ff[i]=i;
	num=0;
	for(int i=1;i<=m;i++)
	{
		int f1=find(e[i].u),f2=find(e[i].v);
		if(f1!=f2) 
		{
			s+=e[i].w;
			ff[f1]=f2;
			add(e[i].u,e[i].v,e[i].w); //建立树
			add(e[i].v,e[i].u,e[i].w);
			cnt++;
			fl[i]=1;
		}
		if(num==n-1) break;
	}
    //printf("mst= %lld\n",s);
	lg[0]=-1; // ?
	for(int i=1;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	dfs(0,1); // ?
	ans=2e9;
	for(int i=1;i<=m;i++)
		if(!fl[i]){
			//printf("%d %d %d\n",e[i].u,e[i].v,e[i].w);
			//printf("%d %d\n",t1,t2);
			LCA(e[i].u,e[i].v),
			ans=min(ans,e[i].w-((e[i].w==t1)?t2:t1));
			//printf("ans = %d\n",ans);
			//printf("%d\n",e[i].w-((e[i].w==t1)?t2:t1));
		}
	printf("%lld\n",s+ans);
	return 0;
}
