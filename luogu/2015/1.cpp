#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define N 210

struct _node {
    int l,r; //左右孩子的编号
    int val; //值
    int cnt; //以这个点为根的子树的点的数量
} node[N];

//边集数组
int head[N]; //每个点为起点的边的编号
struct _e {
    int s,t; //起点,终点
    int v; //值
    int next; // 同起点的下一条边
}e[N<<1];
int cnt= 1; //计数

void add_edge(int s,int t,int v){
    e[cnt].s = s; e[cnt].t = t; e[cnt].v = v;
    e[cnt].next = head[s];
    head[s] = cnt;
    cnt++;
}

int n,q;


// f[i][x]  = max{ f[il][x1] + f[i][x2]} x1+x2 = x-1,
// f[i][1] = node[i].val
// f[i][0] = 0
// ans f[n][q+1]
int f[N<<1][N] = {0};

bool vis[N] = {0}; //是否已经访问过
int build_tree(int idx){
    vis[idx] =1;

    int i;
    int cnt= 0;
    int t= 1;
    bool isleft = true;
    for(i=head[idx];i!=-1;i=e[i].next){
        int u = e[i].t;
        if( vis[u] == 0){
            if(isleft){
                node[idx].l = u;
                node[u].val = e[i].v; //数值
                cnt +=build_tree(u);
                isleft = false;
            }
            else {
                node[idx].r = u;
                node[u].val = e[i].v; //数值
                cnt+= build_tree(u);
            }
        }
    }
    node[idx].cnt =t+cnt;
    return t+cnt;
}

//测试用
void bfs_fi(int x){
    printf("%d %d\n",x,node[x].val);
    if(node[x].l !=0)
        bfs_fi(node[x].l);
    if(node[x].r !=0)
        bfs_fi(node[x].r);
}

//dp()
int dfs_dp(int idx,int b)//b 保留
{
    f[idx][1] = node[idx].val;
    if( b == 0)
        return 0;
    if( f[idx][b] != 0) //已经算过了
        return f[idx][b];
    int i;
    int l = node[idx].l;
    int r = node[idx].r;
    for(i=0;i<b;i++){
        //左右 子树 i, b-i-1
        // 比较它要保留的 数量要大
        if( node[l].cnt >=i and node[r].cnt >= (b-i-1)){
            int a1 = dfs_dp(l,i);
            int a2 = dfs_dp(r,b-i-1);
            f[idx][b] = max(f[idx][b],a1+a2+node[idx].val);
        }

    }
    return f[idx][b];
}


int main(){
    memset(head,-1,sizeof(head));

    scanf("%d%d",&n,&q);
    int i,j;
    int s,t,v;
    for(i=1;i<n;i++){ //边集数组
        scanf("%d%d%d",&s,&t,&v);
        add_edge(s,t,v);
        add_edge(t,s,v);
    }
    //建树
    build_tree(1);
    //for(i=1;i<=n;i++)
        //printf("%d %d \n",i,node[i].cnt);
    dfs_dp(1,q+1);
    printf("%d",f[1][q+1]);

    return 0;
}
