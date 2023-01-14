/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 01月 21日 星期五 09:17:34 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){	//构造函数
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    //遍历点u 周围点
    template<typename U>
    void for_each(int u,U func){
        for(int i = h[u] ; i !=-1;i = e[i].next)
            func(e[i].u,e[i].v,e[i].w); //u v w
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
    void sort(){
        std::sort(e,e+edge_cnt,[](edge &e1,edge& e2){ return e1.w < e2.w; });
    }
} e;

vector<int> node_0;

template<int N>
struct Kahn {
    int indgree[N]; //存点的入度的
    int seq[N]; //排序好的序列
    int idx=0; //下标
    stack<int> sta;

    void indegree_plus_1(int n){
        indgree[n]++;
    }

    /**
     * n : 最大的那个点的编号
     * 最小点的编号默认是1
     */
    void work(int n,linkList& e){
        for(int i=1;i<=n;i++)
            if( indgree[i] == 0){
                node_0.push_back(i);
                sta.push(i);
            }
        while ( !sta.empty()) {
            int u = sta.top();
            seq[++idx] = u; //排序
            sta.pop();
            for(int i = e.h[u]; i!=-1;i = e[i].next){
                int v = e[i].v;
                if( --indgree[v] == 0)
                    sta.push(v);
            }
        }
    }
};

Kahn<5000+5> kahn;

ll f[maxn];
int outdegree[maxn];

int main(int argc,char * argv[]){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        e.add(v,u);
        kahn.indegree_plus_1(u);
        outdegree[v]++;
    }
    for(int i=1;i<=n;++i){
        if( outdegree[i] == 0)
            f[i] = 1;
    }
    kahn.work(n, e);
    for(int j=kahn.idx;j>=1;--j){
        int u = kahn.seq[j];
        int k;
        for(k=e.h[u];~k;k=e[k].next){
            int &v = e[k].v, &w = e[k].w;
            f[u] += f[v];
            f[u] %= 80112002;
        }
    }
    ll ans = 0;
    for(int i=0;i<=node_0.size()-1;++i){
        int u = node_0[i];
        ans += f[u];
        ans %= 80112002;
    }
    printf("%lld",ans);
    return 0;
}
