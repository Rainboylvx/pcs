/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 02月 01日 星期六 09:23:03 CST
* problem:  loj-10157
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e4+5;
int val[maxn];
int n,m;
int f[maxn][2];
bool is_leaf[maxn];


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
    memset(f,-1,sizeof(f));
    scanf("%d",&n);
    int i,j;
    int u,k,m,t;
    For(i,1,n){
        scanf("%d%d%d",&u,&k,&m);
        val[u] = k;
        For(j,1,m){
            scanf("%d",&t);
            addEdge(u, t);
            addEdge(t, u);
        }
    }
}
/* ======= 全局变量 END =======*/
void dfs_find_lead(int u,int fa){
    int i;
    int son=0;
    for(i= head[u]; ~i ;i =e[i].next){
        int &v = e[i].v; int &w = e[i].w;
        if( v == fa) continue;
        son++;
        dfs_find_lead(v,u);
    }
    if( son == 0) is_leaf[u] = 1;
}

int dfs(int u,int fa,bool put,bool pre){
    if( is_leaf[u] && pre == 0) return val[u];
    if( is_leaf[u] && pre == 1) return 0;
    if( f[u][put] != -1) return f[u][put];
    int child = 0;
    int i,j,ret = 0,hav_put= 0;
    int min_sub = 0x7f7f7f7f;
    for(i= head[u];~i;i = e[i].next){
        int v = e[i].v;
        if( v == fa) continue;
        child++;
        if( put){
            ret += min(
                    dfs(v,u,0,put),
                    dfs(v,u,1,put)
                    );
        }
        else {
            int v_put = dfs(v,u,1,put);
            int v_no_put = dfs(v,u,0,put);
            if( v_put <= v_no_put){
                hav_put++;
                ret+=v_put;
            }
            else {
                min_sub = min(min_sub,v_put-v_no_put);
                ret+=v_no_put;
            }
        }
    }

    if( child == 0){
        return f[u][put] = put ? val[u] : 0;
    }

    if( !put  && hav_put == 0){
        ret += min_sub;
    }

    f[u][put] = put ? ret+val[u] : ret;
    return f[u][put];
}

template <typename T>
void combine_inner(T &data, int start, int n, int m, 
    int depth, T temp, std::vector<T> &result)
{
    if (depth == m - 1)
    {
        //最内层循环 将temp加入result
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i];
            result.emplace_back(temp);
        }
    }
    else
        for (int i = start; i < n - (m - depth - 1); ++i)
        {
            temp[depth] = data[i];//每层输出一个元素
            combine_inner(data, i + 1, n, m, depth + 1, temp, result);
        }
}
 
//T可以调入vector<int>, string等，需要支持下标[]操作及size()函数
template <typename T>
std::vector<T> combine(T& data, int m)
{
    if (m <= 0) return{};
    int depth = 0;
    std::vector<T> result;
    T temp(m, 0);
    combine_inner(data, 0, data.size(), m, depth, temp, result);
    return std::move(result);
}

bool fu[maxn];

bool all_fu(){
    int i;
    For(i,1,n) if( !fu[i]) return 0;
    return 1;
}

bool check(int v){
    memset(fu,0,sizeof(fu));
    int i,j;
    For(i,1,n){
        if( v & (1<<(i-1)) ){
            fu[i] = 1;
            for(j= head[i]; ~j ;j =e[j].next){
                int &v = e[j].v; int &w = e[j].w;
                fu[v] = 1;
            }
        }
    }
    return all_fu();
}

int get_ans(int v){
    int i,j=0;
    For(i,1,n){
        if( v & (1<<(i-1))){
            j += val[i];
        }
    }
    return j;
}
 
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //暴力枚举
    int i;
    int ans = 0x7f7f7f7f;
    int t;
    for(i=1;i<=(1<<n)-1;i++){
        if(check(i)){
            if( ans > get_ans(i)){
                ans = get_ans(i);
                t = i;
            }
        }
    }
    printf("%d\n",ans);
    //For(i,1,n){
        //if( t &(1<<(i-1)))
            //printf("%d ",i);
    //}
    //printf("\n");


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
