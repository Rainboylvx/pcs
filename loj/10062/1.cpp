/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 09日 星期六 08:21:12 CST
* problem: loj-10062
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;


/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
char str[maxn];
int indgree[maxn];

/* ======= 全局变量 END =======*/
//=================  AC 自动机 BEGIN
namespace AC {
    const int CH_SIZE = 2;    // 支持的字母数
    const char START_CH = '0'; // 起始的字母

    int tot = 1;     // 点的计数
    struct ch_node { // 点的定义
        int e[CH_SIZE]; // 边的数量
        bool end;       // 单词的结束
        int next;       // 失配指针
        //int len;    // 单词的长度
    } ch[maxn];

    inline int get_N(char c){return c - START_CH;} //得到字符对应的数字

    void ac_init(){ tot = 1; memset(ch,0,sizeof(ch)); }

    void build_ch(char *s){ // 建立Trie树
        int len = strlen(s), u = 1;
        for( int i = 0;i < len ; ++i){
            int c = get_N(s[i]);
            if( !ch[u].e[c] ) ch[u].e[c] = ++tot;
            u = ch[u].e[c];
        }
        ch[u].end = 1;
    }
    
    void bfs_next(){    // 建立 状态图
        for(int i = 0;i< CH_SIZE ; ++i) ch[0].e[i] = 1; //虚拟0号结点
        queue<int> q; q.push(1); //建立队列
        ch[1].next = 0;     //结点1的失配指针
        while( !q.empty() ){
            int u = q.front(); q.pop();
            int k = u;
            if(ch[ ch[k].next ].end ) ch[k].end = 1;
            for( int i = 0;i < CH_SIZE; ++i){
                int &child = ch[u].e[i];
                if( !child ) child  = ch[ ch[u].next ].e[i];
                else {
                    q.push(child);
                    ch[ child ].next = ch[ ch[u].next ].e[i];
                    // 当前的失配 = 「父亲的失配指向的点」的同样孩子
                }
                indgree[child]++;
            }
        }
    }
}
//=================  AC 自动机 END
using namespace AC;


/* ================= 拓扑排序 =================*/
int kahn(){
    stack<int> sta;
    //count用于计算输出的顶点个数
    int count=0;
    int i,j,k;
    //把入度为0的顶点入栈
    for (i=1;i<=tot;i++){
        if( indgree[i] == 0 && ch[i].end == 0) sta.push(i);
    }

    while (!sta.empty()) {//如果栈为空，则结束循环
        int t = sta.top(); sta.pop();
        count++;
        // t点周围的点,入度-1
        for(i=0 ;i < CH_SIZE ;++i){
            int v = ch[t].e[i];
            indgree[v]--;
            if( indgree[v] == 0 && ch[v].end == 0) //如果入度减少到为0，则入栈
                sta.push(v);
        }
    }
    return count;
}
/* ================= 拓扑排序 end =================*/


void init(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        scanf("%s",str);
        build_ch(str);
    }
    bfs_next();
}

/* //超时
 *bool vis[maxn];
 *bool dfs(int u){
 *    vis[u] = 1;
 *    int i;
 *    For(i,0,CH_SIZE-1){
 *        int child = ch[u].e[i];
 *        if( ch[child].end ) continue;
 *        if( vis[child]) { return 1; }
 *        if( dfs(child) ) return 1;
 *        vis[child] =  0;
 *    }
 *    return 0;
 *}
 */


int all_safe_node = 0;


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for( i =1;i<=tot;i++) if(!ch[i].end) {
        //printf("safe %d %d\n",i,indgree[i]);
        all_safe_node++;
    }
    else {
        for(j=0;j< CH_SIZE;++j ){
            indgree[ ch[i].e[j] ]--;
        }
    }
    int cnt = kahn();
    bool ret = cnt < all_safe_node;
    //printf("%d\n",all_safe_node);
    //printf("%d\n",cnt);
    if( ret) 
        printf("TAK\n");
    else
        printf("NIE\n");


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
