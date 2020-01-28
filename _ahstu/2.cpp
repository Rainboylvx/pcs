/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 17日 星期五 16:50:16 CST
* problem:  安徽ACM2018-题目B
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <set>
using namespace std;

#define maxn 200005


int n,idx;
set<string> s;
map<string,int> m;


int indgree[maxn];
stack<int> sta; //栈


bool vis[maxn];
/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
struct _e{
    int u,v,w,next;
}e[maxn<<1];

void inline xlx_init(){
    edge_cnt = 0;
    memset(head,-1,sizeof(head));
}

void addEdge(int u,int v){
    edge_cnt++;
    e[edge_cnt].u = u;
    e[edge_cnt].v= v;
    e[edge_cnt].next = head[u];
    head[u] = edge_cnt;
}
/* ================= 向量星 end =================*/

int get_idx(string &str){
    if( s.count(str) == 1){
        return m[str];
    }
    else {
        s.insert(str);
        m[str] = idx;
        return idx++;
    }

}

void init(){
    xlx_init();
    memset(vis,0,sizeof(vis));
    memset(indgree,0,sizeof(indgree));
    idx = 1;
    s.clear();
    m.clear();
    string t1,t2;
    scanf("%d",&n);

    int i;
    for (i=1;i<=n;i++){
        cin >> t1 >> t2;
        int id1 = get_idx(t1);
        int id2 = get_idx(t2);
        addEdge(id1,id2);
        indgree[id2]++;
    }
}


/* 进行环的判定 */
/* ================= 拓扑排序 =================*/
int kahn(){
    //count用于计算输出的顶点个数
    int count=0;
    int i,j,k;
    //把入度为0的顶点入栈
    for (i=1;i<idx;i++){
        if( indgree[i] == 0)
            sta.push(i);
    }

    while (!sta.empty()) {//如果栈为空，则结束循环
        int t = sta.top();
        sta.pop();
        //printf("%d ",t); //输出
        count++;

        // t点周围的点,入度-1
        for(i=head[t];i!=-1;i = e[i].next){
            int v = e[i].v;
            indgree[v]--;
            if( indgree[v] == 0) //如果入度减少到为0，则入栈
                sta.push(v);
        }
    }

    return count;
}
/* ================= 拓扑排序 end =================*/





int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init(); //数据读取 与初始化
        int c = kahn();
        if( c == idx-1)
            printf("Passed\n");
        else
            printf("Failed\n");

    }
    return 0;
}
