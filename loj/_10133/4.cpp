#include<bits/stdc++.h>
#define gc getchar()
using namespace std;
typedef long long ll;
const int N = 1e5+10;
const int M = 3e5+10;
const int BIT = 18;
const ll inf=2147483647000000;//inf 开大
inline int read() {
    int x = 0; char c = gc;
    while(c < '0' || c > '9') c = gc;
    while(c >= '0' || c >= '9') x = x * 10 + c - '0', c = gc;
    return x;
}
int n,m;
struct Edge{
    ll u{},v{},w{};
    bool in = false;
    void scan(){u=read(),v=read(),w=read();}
    bool operator<(const Edge& a)const{
        return w<a.w;
    }
} e[M];
ll cnt = 0,head[N],nxt[M<<1],v[M<<1],w[M<<1];
void addEdge(int a,int b,int c){
    nxt[++cnt] = head[a],v[cnt] = b,w[cnt] = c,head[a] = cnt;
}
int bf[N];
int find(int x){
    return bf[x]==x?x:bf[x]=find(bf[x]);
}
ll mst = 0;
void kmst(){
    sort(e+1,e+1+m);
    ll now = 0,i = 0,u,v,fu,fv;
    while(++i<=m&&now!=n-1){
        u = e[i].u,v=e[i].v,fu = find(u),fv = find(v);
        if(fu!=fv){
            bf[fu] = fv;
            now++;
            e[i].in = true;
            mst += e[i].w;
            addEdge(u,v,e[i].w);
            addEdge(v,u,e[i].w);
        }
    }
}
ll dep[N],f[N][BIT+2],ma[N][BIT+2],mb[N][BIT+2];
void dfs(ll u){
    int i;
    for(i=1;i<=BIT;i++){
        f[u][i]=f[f[u][i-1]][i-1];
        ma[u][i]=max(ma[u][i-1],ma[f[u][i-1]][i-1]);
        //ma肯定为两段路径分别的ma的较大值
        mb[u][i]=max(mb[u][i-1],mb[f[u][i-1]][i-1]);
        //先令mb为两段路径分别的mb的较大值
        //这个 if 非常重要！不然的话，要是边权最大的边有很多，就会使次大边权也为最大值
        if(ma[u][i-1]!=ma[f[u][i-1]][i-1])
            mb[u][i]=max(mb[u][i],min(ma[u][i-1],ma[f[u][i-1]][i-1]));
    }
    for(i = head[u];i;i=nxt[i]){
        if(!dep[v[i]]){
            f[v[i]][0] = u;
            ma[v[i]][0] = w[i];
            mb[v[i]][0] = -INF;
            dep[v[i]] = dep[u]+1;
            dfs(v[i]);
        }
    }
}
ll lca(ll x,ll y){
    if(dep[x]<dep[y]) swap(x,y);
    for(int i = BIT;i>=0;i--)
        if(dep[f[x][i]]>=dep[y])x = f[x][i];
    if(x==y)return x;
    for(int i = BIT;i>=0;i--){
        if(f[x][i]^f[y][i]){
            x = f[x][i],y = f[y][i];
        }
    }
    return f[x][0];
}
ll findMax(ll x,ll y,ll c){
    ll ans = -INF;
    for(int i = BIT;i>=0;i--){
        if(dep[f[x][i]]>=dep[y]){
            if(c!=ma[x][i])
                ans=max(ans,ma[x][i]);
            else
                ans=max(ans,mb[x][i]);
            x=f[x][i];
        }
    }
    return ans;
}
int main(){
    n = read(),m = read();
    for(int i = 1;i<=n;i++){
        bf[i] = i;
    }
    for(int i = 1;i<=m;i++)e[i].scan();
    kmst();
    dep[1] = 1,ma[1][0]=0,mb[1][0]=-INF;
    dfs(1);
    ll inc = INF;
    for(int i = 1;i<=m;i++){
        if(!e[i].in){
            ll a = e[i].u,b=e[i].v,c=e[i].w;
            ll l = lca(a,b);
            ll um = findMax(a,l,c),vm = findMax(b,l,c);
            //printf("%d %d %d %d %d %d\n",a,b,c,l,um,vm);
            inc = min(inc,(ll)c-max(um,vm));
        }
    }
    cout << inc+mst<<endl;
    return 0;
}
