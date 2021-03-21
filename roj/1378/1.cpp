/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 02月 16日 星期二 14:44:13 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int s;
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

int dis[maxn];
bool inque[maxn];
queue<int> q;
void spfa(){
    memset(dis,0x3f,sizeof(dis));
    q.push(s);
    inque[s] = 1;
    dis[s] = 0;
    while ( !q.empty() ) {
        int u = q.front();
        q.pop();
        inque[u] = 0;
        int i;
        for(i=e.h[u];~i;i=e[i].next){
            int &v = e[i].v, &w = e[i].w;
            if( dis[v] > dis[u]+ w){
                dis[v] = dis[u] + w;
                if( inque[v] == 0){
                    q.push(v);
                    inque[v] = 1;
                }
            }
        }
    }
}

int main(){
    scanf("%d",&n);
    scanf("%d",&s);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            int t;
            int ans = scanf("%d",&t);
            if( ans == 1){
                e.add(i,j,t);
            }
        }
    }
    spfa();
    for(int i=1;i<=n;++i){
        if(i == s) continue;
        printf("(%d -> %d) = %d\n",s,i,dis[i]);
    }
    return 0;
}
