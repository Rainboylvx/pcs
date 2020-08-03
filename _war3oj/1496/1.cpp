/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 09月 29日 星期日 15:50:21 CST
* problem: war3oj-1496
*----------------*/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3+5;
const int maxm = 1e4+5;
int max_w =0; // 最大的边


int n,p,k;
int dis[maxn];
int vis[maxn];
/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[maxm<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,int w){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}

/* 函数重载 */
void addEdge(int u,int v){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/

void init(){
    xlx_init();
    /* 读取数据 */
    scanf("%d%d%d",&n,&p,&k);
    int i;
    for(i=1;i<=p;i++){
        int t1,t2,t3;
        scanf("%d%d%d",&t1,&t2,&t3);
        addEdge(t1, t2,t3);
        addEdge(t2, t1,t3);
        max_w = max(max_w,t3);
    }
}



void dijkstra(int s,int len){
    typedef pair<int,int> pairii;
    priority_queue<pairii, vector<pairii>, greater<pairii> > q;
    memset(dis,0x3f,sizeof(dis));
    memset(vis,0,sizeof(vis));
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty()){
        int now=q.top().second;
        q.pop();
        if(vis[now])continue;
        vis[now]=1;
        for(int i=head[now];i!=-1;i=e[i].next){
            int w = e[i].w > len ? 1 :0;
            if(dis[e[i].v]>dis[now]+w){
                dis[e[i].v]=dis[now]+w;
                q.push(make_pair(dis[e[i].v],e[i].v));
            }
        }
    }
}

/* 判断是否成立 */
bool check(int len){
    dijkstra(1,len);
    if( dis[n] <= k)
        return 1;
    return 0;
}

//查找范围是[l,r), a[r] 永远 >= key
int first_g(int l,int r){
    int m;
    while( l != r  ) //表示l和r没有重合
    {
        m = (l+r) >>1; // 取中间位置
        if(!check(m)) //表示 [m+1,r) 满足条件
            l = m+1;
        else
            r = m;
    }
    return l;
}

int main(){
    init();
    /* 特判 */
    dijkstra(1,0);
    if( dis[n] == 0x3f3f3f3f){
        printf("-1");
        return 0;
    }

    int ans = first_g(0,max_w);
    printf("%d\n",ans);
    return 0;
}
