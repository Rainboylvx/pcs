/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 11月 08日 星期五 15:07:46 CST
* problem:  poj-1741
*----------------*/
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

/* 快读 */
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}

/* ======= 全局变量 =======*/
const int maxn = 1e4+5;
int n,k;
bool del[maxn]; //点i是否删除
int root,ans;
int size[maxn];
int totalNodes; // n - 删除的点的个数
int dis[maxn];
int f[maxn];//存储在当前图下,以某个节点作为根节点时，得到的最大子树的大小
/* ======= 全局变量 END =======*/

/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int v,w,next;
}e[maxn<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

inline void addEdge(int u,int v,int w){
    e[++edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;

    e[++edge_cnt].v= u;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[v];
    head[v] = edge_cnt;
}
/* ================= 向量星 end =================*/

void getroot(int u,int fa){
    size[u] = 1;
    f[u] = 1;
    int i;
    for(i = head[u]; ~i;i=e[i].next){
        int v = e[i].v;
        if( v== fa || del[v]) continue;
            getroot(v, u);
            size[u] += size[v];
            f[u] = f[u] > size[v] ? f[u] : size[v];
    }
    f[u] = f[u] > totalNodes-size[u] ? f[u] : totalNodes-size[u];
    //f[u] = max(f[u],totalNodes-size[u]);
    if( f[u] < f[root]) root = u;
}

int dep[maxn];
void get_dep(int u,int fa){
    dep[++dep[0]] = dis[u];
    int i;
    for(i = head[u]; ~i;i = e[i].next){
        int v = e[i].v;
        if( v == fa || del[v]) continue;
        dis[v] = dis[u]+e[i].w;
        get_dep(v, u);
    }
}
void quicksort(int l,int r){
    if( l < r) {
    int s=l,t=r;
    int key =dep[l]; // 取第一个值为key
    
    while(s < t){
        while( s <t && dep[t] >= key) --t;// 如果a[t] >= key,t下标不停变小,直到a[t] < key
        if(s < t) dep[s++] = dep[t];        //停下来的时候,看一看,是不是到中点,如果不是 交换值
        while(s<t && dep[s] <= key) ++s;  //如果dep[s] <= key  s的下标不停变大,直到dep[s] > key
        if(s<t ) dep[t--] = dep[s];         //停下来的时候,看一看,是不是到了中点,如果不是,交换值
    }
    dep[s] = key;  //上面while停止的时候,一定是s ==t
    quicksort(l,s-1);
    quicksort(s+1,r);
}
}

int calc(int u,int len){
    dep[0] = 0;
    dis[u] = len;
    get_dep(u, 0);
    //sort(dep+1,dep+1+dep[0]);
    quicksort(1, dep[0]);
    int cnt = 0;
    int l = 1 , r = dep[0];
    while(l < r){
        if( dep[l] + dep[r] <= k){
            cnt+= r-l;
            l++;
        }
        else
            r--;
    }
    return cnt;
}

void do_job(int u){
    ans += calc(u, 0);
    del[u] = 1;  //删除点u,得到多棵树
    int i;
    for(i = head[u];i != -1;i = e[i].next){
        int v = e[i].v;
        if( !del[v]){ //没有被删除
            ans -= calc(v, e[i].w);
            f[0] = totalNodes = size[v];//考虑连通的某棵子树，其总的大小
            root = 0;
            getroot(v, 0);
            do_job(v);
        }
    }
}

void init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
    memset(del,0,sizeof(del));
    ans = 0;
    root = 0;
    totalNodes =n;
    f[root] = 0x7fffffff;
     int u,v,w;
     int i;
     for(i=1;i<n;i++){
         u = read(),v = read(),w= read();
         addEdge(u, v,w);
     }
}


int main(){
    //===================
    while(1){
        n = read();
        k = read();
        if( !n && !k ) break;
        init();
        getroot(1,0);
        do_job(root);
        printf("%d\n",ans);
    }

    //=================== 
    return 0;
}
