/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 11月 05日 星期二 14:48:17 CST
* problem: luogu-2419
*----------------*/
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e2+5;
int n,m;
int indgree[maxn]; //点的入度
stack<int> sta; // kahn 用的栈
int del_count = 0; //kahn 处理过的点的数量
/* ======= 全局变量 END =======*/


/* ================= 向量星 =================*/
struct xlx{
    typedef struct  { int u,v,w,next;} node;
    int edge_cnt=0;
    vector<int> head;
    vector<node> e;

    /* 构造函数,点的数量 */
    xlx(int n){
        head = vector<int> (n,-1);
    }

    void add_edge(int u,int v,int w){
        e.push_back({.u = u ,.v = v ,.w = w ,.next = head[u]});
        head[u] = edge_cnt;
        edge_cnt++;
    }

    void add_edge(int u,int v){
        e.push_back({.u = u ,.v = v ,.w = 0 ,.next = head[u]});
        head[u] = edge_cnt;
        edge_cnt++;
    }

    /* 遍历u周围的点 */
    template<class UnaryPredicate>
    void forEach(int u,UnaryPredicate p){
        int i;
        for(i = head[u];i!=-1;i = e[i].next){
            p(e[i].u,e[i].v,e[i].w);
        }
    }
};
/* ================= 向量星 end =================*/
xlx x1(maxn),x2(maxn); //正反


/* ================= 拓扑排序 =================*/
bool vis[maxn];
int vis_cnt = 0;
void dfs(int u){
    vis[u] = 1;
    vis_cnt++;
    auto p = [&](int u,int v,int w){
        if( !vis[v])
            dfs(v);
    };
    x2.forEach(u, p);
}
int kahn(){
    //count用于计算输出的顶点个数
    int count=0;
    int i,j,k;
    //把入度为0的顶点入栈
    for (i=1;i<=n;i++){
        if( indgree[i] == 0)
            sta.push(i);
    }

    while (!sta.empty()) {//如果栈为空，则结束循环
        int u = sta.top(); sta.pop();
        int left = sta.size();

        bool flag = 0;
        // u点周围的点,入度-1
        auto lamb = [&](int u,int v,int w){
            indgree[v]--;
            if(indgree[v] == 0)
                sta.push(v);
            x2.add_edge(v, u);
        };
        x1.forEach(u,lamb);
        del_count++;
        memset(vis,0,sizeof(vis));
        vis_cnt = 0;
        dfs(u);
        if( left == 0 && vis_cnt == del_count)
            count++;
    }

    return count;
}
/* ================= 拓扑排序 end =================*/


void init(){
     scanf("%d%d",&n,&m);
     int i,u,v;
     for(i=1;i<=m;i++){ // 建图
         scanf("%d%d",&u,&v);
         x1.add_edge(u, v);
         indgree[v]++;
     }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ans = kahn();
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
