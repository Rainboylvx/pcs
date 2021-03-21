//spfa
/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 04日 星期四 09:33:23 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,s,t;
queue<int> q;
int dis[maxn];
bool inque[maxn];
struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){	//构造函数
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    void add(int u,int v,int w=0){
        e[edge_cnt] = {u,v,w,h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u,int v,int w=0){
        add(u,v,w);
        add(v,u,w);
    }
    edge& operator[](int i){
        return e[i];
    }
} e;

int main(){
    scanf("%d%d%d%d",&n,&m,&s,&t);
    for(int i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        e.add2(u,v,w);
    }
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    q.push(s);
    inque[s] = 1;

    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        inque[u] = 0;
        for(int i = e.h[u]; i!=-1 ;i = e[i].next){
            int v = e[i].v , w = e[i].w;
            if( dis[v] > dis[u] + w){
                dis[v] = dis[u] +w;
                if( inque[v] == 0){
                    q.push(v);
                    inque[v] = 1;
                }
            }
        }
    }
    printf("%d",dis[t]);

    return 0;
}
