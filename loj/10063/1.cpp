/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 04 May 2020 03:39:22 PM CST
* problem: loj-10063
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
vector<int> pre[60*100+5]; //每个点的前驱点
char s[105];
int f[10010][10010]; // f[i][j] 走i步到达点j的 不可读 的方案数目
const int mod = 10007;

/* ======= 全局变量 END =======*/

//=================  AC 自动机 BEGIN
namespace AC {
    const int CH_SIZE = 26;    // 支持的字母数
    const char START_CH = 'A'; // 起始的字母

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
            if( ch[ ch[u].next ].end ) ch[u].end = 1;
            for( int i = 0;i < CH_SIZE; ++i){
                int &child = ch[u].e[i];
                if( !child ) {
                    child  = ch[ ch[u].next ].e[i];
                    pre[child].push_back(u);
                }
                else {
                    pre[child].push_back(u);
                    q.push(child);
                    ch[ child ].next = ch[ ch[u].next ].e[i];
                    // 当前的失配 = 「父亲的失配指向的点」的同样孩子
                }
            }
        }
    }

    void find( char *s){
    }
}
//=================  AC 自动机 END
using namespace AC;

void init(){
    scanf("%d%d",&n,&m);
    int i,j;
    For(i,1,n){
        scanf("%s",s);
        build_ch(s);
    }
    bfs_next();
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j,k;
    //for(i=1;i<=tot;i++){
        //sort(pre[i].begin(),pre[i].end());
        //vector<int>::iterator it = unique(pre[i].begin(),pre[i].end());
        //pre[i].erase(it, pre[i].end());
    //}


    f[0][1] = 1; //边界
    for(i = 1;i<=m;i++){ //枚举步
        for(j=1;j<=tot;j++){ //枚举点 
            for (const auto& e : pre[j]) { // 枚举前驱
                if( !ch[e].end){
                    f[i][j] +=  f[i-1][e];
                    f[i][j] %= mod;
                }
            }
        }
    }
    int cnt = 0;
    For(i,1,tot){
        if( !ch[i].end){
            cnt += f[m][i];
            cnt %= mod;
        }
    }
    int ans=1;
    //printf("%d\n",cnt);
    For(i,1,m){
        ans *= 26;
        ans %= mod;
    }
    //printf("%d\n",ans);
    //printf("%d\n",cnt);
    //printf("%d\n",ans);
    printf("%d\n", ((ans-cnt) % mod + mod) %mod );
    //printf("%d\n", ((ans-cnt) % mod));

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
