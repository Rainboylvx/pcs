/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Fri 28 Feb 2020 04:29:54 AM EST
* problem: loj-10065
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

const int maxn = 505;
int n,k;

vector<pair<int,int> >   v;

/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,next;
    double w;

    bool operator<(const _e &b){
        return w < b.w;
    }
}e[maxn*maxn];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v,double w){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].w=w;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/

double get_len(
        pair<int,int> a,
        pair<int,int> b
        ){
    int l1 = a.first- b.first;
    int l2  = a.second - b.second;
    return sqrt( l1*l1+l2*l2);
}

void init(){
     xlx_init(); 
     scanf("%d%d",&n,&k);
     int i,j;
     int t1,t2;
     For(i,1,n){
         scanf("%d%d",&t1,&t2);
         v.push_back(make_pair(t1,t2));
     }
     For(i,0,n-1){
         For(j,i+1,n-1){
             double len = get_len(v[i], v[j]);
             addEdge(i+1, j+1, len);
         }
     }

     //排序
     sort(e+1,e+1+edge_cnt);
}
/* ======= 全局变量 END =======*/

/* ================= 并查集 =================*/
namespace BCJ {
    int fa[maxn];
    inline void bcj_init(int x){ //并查集 初始化
        int i;
        for(i=1;i<=x;i++) fa[i] = i;
    }
    int find(int x){ //查找 and 压缩
        if( x == fa[x]) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }
    
    void merge(int x,int y){ //合并
        int fx = find(x);
        int fy = find(y);
        fa[fx] = fy;
    }
}
/* ================= 并查集 end =================*/


//============== kruskal算法
vector<double>   v1;
int kruskal(){
    int ans = 0;
    int i,j;
    int k=0 ;
    for(i=1;i<=n;i++) BCJ::fa[i] = i; //并查集初始化
    for(i=1;i<=edge_cnt;i++){
        int f1 = BCJ::find(e[i].u);
        int f2 = BCJ::find(e[i].v);
        if( f1 != f2){
            v1.push_back(e[i].w);
            ans += e[i].w;
            BCJ::fa[f1] = f2;
            k++;
            if( k == n-1) break; //选n-1条边
        }
    }
    if( k < n-1)
        return -1; //返回不可能
    else 
        return ans;
}
//============== kruskal算法 END



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    kruskal();
    if( k <=1)
        printf("%.2lf\n",v1.back());
    else{
        k--;
        printf("%.2lf\n",v1[n-1-k-1]);
    }
    //for (const auto& e : v1) {
        //std::cout << e << " ";
    //}
    //printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
