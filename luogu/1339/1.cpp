/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 04日 星期四 09:28:10 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int s,t;
int dis[maxn];
struct Edge {
    int u,v,w;
}e[maxe];

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;++i){
        scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
    }
    memset(dis,0x7f,sizeof(dis));
    dis[s] = 0;
    for(int k=1;k<=n-1;++k){
        for(int i=1;i<=m;++i){
            int u = e[i].u;
            int v = e[i].v;
            int w = e[i].w;
            dis[v] = min(dis[v],dis[u]+w);
            dis[u] = min(dis[u],dis[v]+w);
        }
    }

    printf("%d",dis[t]);
    return 0;
}
