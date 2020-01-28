#include<cstdio>
#include<cstring>
#include<algorithm>
#define m(x) memset(x,0,sizeof x)
using namespace std;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
const int N=1e4+10;
struct node{
    int v,w,next;
}e[N<<1];
int n,K,tot,root,sum,ans,head[N],son[N],f[N],d[N],dep[N];
bool vis[N];
void add(int x,int y,int z){
    e[++tot].v=y;e[tot].w=z;e[tot].next=head[x];head[x]=tot;
    e[++tot].v=x;e[tot].w=z;e[tot].next=head[y];head[y]=tot;
} 
void get_root(int x,int fa){//寻找重心 
//重心，就是删掉此结点后，剩下的结点最多的树结点个数最小
    son[x]=1;f[x]=0;
    for(int i=head[x],v;i;i=e[i].next){
        if((v=e[i].v)==fa||vis[v]) continue;
        get_root(v,x);
        son[x]+=son[v];
        f[x]=max(f[x],son[v]); 
    }
    f[x]=max(f[x],sum-son[x]);
    if(f[x]<f[root]) root=x;
}
void get_deep(int x,int fa){
    dep[++dep[0]]=d[x];
    for(int i=head[x],v;i;i=e[i].next){
        if((v=e[i].v)==fa||vis[v]) continue;
        d[v]=d[x]+e[i].w;
        get_deep(v,x);
    }
}
int calc(int x,int now){
    d[x]=now;dep[0]=0;
    get_deep(x,0);
    sort(dep+1,dep+dep[0]+1);
    int t=0,l,r;
    for(l=1,r=dep[0];l<r;){
        if(dep[l]+dep[r]<=K){t+=r-l;l++;}
        else r--;
    }
    return t;
}
void work(int x){//分治 
    ans+=calc(x,0);
    vis[x]=1;
    for(int i=head[x],v;i;i=e[i].next){
        if(vis[v=e[i].v]) continue;
        ans-=calc(v,e[i].w);
        sum=son[v];
        get_root(v,root=0);
        work(root);
    }
}
void Cl(){
    ans=0;tot=0;root=0;
    m(head);m(vis);
}
int main(){
    while(1){
        Cl(),n=read(),K=read();
        if( !n && !K ) break;
        for(int i=1,x,y,z;i<n;i++) x=read(),y=read(),z=read(),add(x,y,z);
        sum=n;f[0]=0x7fffffff;
        get_root(1,0);
        work(root);
        printf("%d\n",ans);
    }
    return 0;
}
