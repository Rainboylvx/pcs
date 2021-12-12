/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 12月 12日 星期日 15:45:13 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int c[maxn],u[maxn];
int outdegree[300];
int indegree[300];

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
} e1,e2;

template<int N>
struct Kahn {
    int indgree[N]; //存点的入度的
    int seq[N]; //排序好的序列
    int idx=0; //下标
    stack<int> sta;

    /**
     * n : 最大的那个点的编号
     * 最小点的编号默认是1
     */
    void work(int n,linkList& e){
        for(int i=1;i<=n;i++)
            if( indgree[i] == 0) 
                sta.push(i);
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
Kahn<200> kahn;

int main(int argc,char * argv[]){
    std::cin >> n >> m;
    for(int i=1;i<=n;++i){
        std::cin >> c[i] >> u[i];
    }
    for(int i=1;i<=m;++i){
        int u,v,w;
        std::cin >> u >> v >> w;
        //std::cout << u <<" "<< v <<" "<< w << std::endl;
        e1.add(u,v,w);
        kahn.indgree[v]++;
        outdegree[u]++;
        indegree[v]++;
        e2.add(v,u,w);
    }
    //std::cout << "===" << std::endl;
    //for(int i=1;i<=n;++i){
        //if( outdegree[i] == 0)
            //std::cout << "out " << i  << " " << outdegree[i] << '\n';
    //}

    kahn.work(n, e1);
    for(int i=1;i<=n;++i){
        int x = kahn.seq[i];
        //std::cout << x << std::endl;
        for(int j = e2.h[x] ; j!=-1 ;j  = e2[j].next){
            int v = e2[j].v; //前一个点
            int w = e2[j].w; //前一个点
            if( c[v] <= 0) continue;
            c[x] += w*c[v];
        }
        if(indegree[x] !=0) //不是第一层的点
            c[x] -= u[x];
        //std::cout << "c " ;
        //std::cout << indegree[x] << " " ;
        //std::cout << x <<" "<< c[x] << std::endl;
    }
    bool allzero = 1;
    for(int i=1;i<=n;++i){
        if(outdegree[i] == 0){
            if( c[i] !=0){
                allzero = 0;
                break;
            }
        }
    }
    if(allzero)
        std::cout << "NULL" ;
    else {
        for(int i=1;i<=n;++i){
            if(outdegree[i] == 0 && c[i] > 0){
                //仅输出最后状态大于 0 的输出层神经元状态
                std::cout << i <<" "<< c[i] << std::endl;
            }
        }
    }
    return 0;
}
