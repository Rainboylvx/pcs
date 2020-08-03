#include<cstdio>
#include<cstring>
#include<math.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int N=1e4+10;
const int M=4*1e4+10;
int dep[N],we[N];
int f[N][30];
int tot;
struct node
{
    int nex,to,w;
} val[M];
int fir[N];
int n,m;
void add(int x,int y,int z)
{
    val[++tot].w=z;
    val[tot].to=y;
    val[tot].nex=fir[x];
    fir[x]=tot;
}
void dfs(int u,int father)
{
    dep[u]=dep[father]+1;
    for(int i=0; i<25; i++)
        f[u][i+1]=f[f[u][i]][i];
    for(int i=fir[u]; i; i=val[i].nex)
    {
        int v=val[i].to;
        if(v==father)
            continue;
        f[v][0]=u;
        we[v]=we[u]+val[i].w;
        dfs(v,u);
    }
}
int LCA(int x,int y)
{
    if(dep[x]<dep[y])
        swap(x,y);
    for(int i=24; i>=0; i--)
    {
        if(dep[f[x][i]]>=dep[y])
            x=f[x][i];
        if(x==y)
            return x;
    }
    for(int i=24; i>=0; i--)
    {
        if(f[x][i]!=f[y][i])
        {
            x=f[x][i];
            y=f[y][i];
        }
    }
    return f[x][0];
}
int dis(int x,int y)
{
    return we[x]+we[y]-2*we[LCA(x,y)];
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1; i<=n-1; i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        add(x,y,z);
        add(y,x,z);
    }
    dfs(1,0);
    while(m--)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",dis(x,y));
    }
    return 0;
}
