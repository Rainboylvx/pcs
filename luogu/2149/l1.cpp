/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 08月 05日 星期五 23:44:59 CST */
#include <bits/stdc++.h>
#include "utils/graphviz.hpp"
using namespace std;
using namespace DOT;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量
                                     //

graphviz<DI> graph;

int n,m;
int X1,Y1,X2,Y2;
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
    bool find(int u,int v){
      for(int i = 0;i < edge_cnt;i++)
        if( e[i].u == u && e[i].v == v)
          return 1;
      return 0;
    }
    edge& operator[](int i){
        return e[i];
    }
    void sort(){
        std::sort(e,e+edge_cnt,[](edge &e1,edge& e2){ return e1.w < e2.w; });
    }
} e;

struct Dijkstra {
    int dis[maxn];
    bool vis[maxn];
    typedef pair<int,int> P; //第一个存dis，第二个存点编号
    priority_queue<P,vector<P>,greater<P>> q; //优先队列
    Dijkstra(){ //格构函数
        memset(dis,0x7f,sizeof(dis)); //所有的点都是0x7f7f7f7f 代表无穷大
        memset(vis,0,sizeof(vis));    //所有点都是没有标记的
        //注意这里起点也未标记的
    }

    void init(){
        memset(dis,0x7f,sizeof(dis)); //所有的点都是0x7f7f7f7f 代表无穷大
        memset(vis,0,sizeof(vis));    //所有点都是没有标记的
    }

    void work(int s,linkList& e){
        dis[s] = 0; 
        q.push(make_pair(0, s)); //把起点加入

        while ( !q.empty() ) { //当优先队列不空时
            int u = q.top().second;
            q.pop();
            if( vis[u] ) continue; //这个点已经标记过了，什么也不做
            vis[u] = 1; //标记这个点

            //用新标记的点去更新它周围的末标记点
            for(int i=e.h[u];~i;i=e[i].next){
                int &v = e[i].v, &w = e[i].w;
                if( vis[v] == 0 && dis[v] > dis[u]+w){
                    dis[v] = dis[u] + w;
                    q.push(make_pair(dis[v], v)); //新更新的点加入队列
                }
            }
        }
    }
} dijkstra1;

//数据读取

linkList e2; //存x1 y1 的最短路 形成的图
linkList e3; //存x1 y1 的最短路 形成的图


void init(){
  std::cin >> n >> m;
  std::cin >> X1 >> Y1 >> X2 >> Y2;
  for(int i=1;i<=m;++i){
    int u,v,w;
    std::cin >> u >> v >> w;
    e.add2(u,v,w);
  }
}

//建立由最短路 组成的图
void build_shortest_graph(int t,int dis[],linkList & e2){
  e.for_each(t, [&e2,&dis](int u,int v,int w){
      if( dis[v] + w == dis[u]) { //是从 v 过来的w
        if(e2.find(v, u) == 0)
          e2.add(v, u,w);
        build_shortest_graph(v ,dis ,e2);
      }
  });
}

int main(int argc,char * argv[]){
  init();
  //求 x1 y1 的 shortest path
  dijkstra1.work(X1, e);
  std::cout << 
    dijkstra1.dis[Y1]
    << std::endl;


  build_shortest_graph(Y1, dijkstra1.dis, e2);

  ////输出e2中的图
  //for(int i = 0 ;i < e2.edge_cnt ;i++){
    //std::cout << e2[i].u << " " << e2[i].v <<" "<< e2[i].w << std::endl;
  //}

  dijkstra1.init();
  dijkstra1.work(X2, e);

  build_shortest_graph(Y2, dijkstra1.dis, e3);

  //输出e3中的图
  for(int i = 0 ;i < e3.edge_cnt ;i++){
    std::cout << e3[i].u << " " << e3[i].v <<" "<< e3[i].w << std::endl;
  }
  
  // 暴力求最短 公共路
  // 综合e2 e3 创建新的graph 来肉眼找规律

  return 0;
}
