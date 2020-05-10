/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 06 May 2020 08:21:16 AM CST
* problem: loj-10061
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
char s[1000];

int vis[12*50+5][(1<<12)]; // 状态
struct node_t {
    int step;       // 步数
    int id;         // 哪个点
    int state;      // 状态
    string s;
};

/* ======= 全局变量 END =======*/
//=================  AC 自动机 BEGIN
namespace AC {
    const int CH_SIZE = 26;    // 支持的字母数
    const char START_CH = 'A'; // 起始的字母

    int tot = 1;     // 点的计数
    struct ch_node { // 点的定义
        int e[CH_SIZE]; // 边的数量
        int end;       // 单词的结束,同样表示哪个字符串的结束
        int next;       // 失配指针
        //int len;    // 单词的长度
        bool real[CH_SIZE];
    } ch[maxn];

    inline int get_N(char c){return c - START_CH;} //得到字符对应的数字

    void ac_init(){ tot = 1; memset(ch,0,sizeof(ch)); }

    int word_cnt = 0;
    void build_ch(char *s){ // 建立Trie树
        int len = strlen(s), u = 1;
        for( int i = 0;i < len ; ++i){
            int c = get_N(s[i]);
            if( !ch[u].e[c] ) ch[u].e[c] = ++tot;
            ch[u].real[c] = 1;
            u = ch[u].e[c];
        }
        ch[u].end |= (1<<word_cnt);
        word_cnt++;
    }
    
    void bfs_next(){    // 建立 状态图
        for(int i = 0;i< CH_SIZE ; ++i) ch[0].e[i] = 1; //虚拟0号结点
        queue<int> q; q.push(1); //建立队列
        ch[1].next = 0;     //结点1的失配指针
        while( !q.empty() ){
            int u = q.front(); q.pop();
            for( int i = 0;i < CH_SIZE; ++i){
                int &child = ch[u].e[i];
                if( !child ) child  = ch[ ch[u].next ].e[i];
                else {
                    q.push(child);
                    ch[ child ].next = ch[ ch[u].next ].e[i];
                    // 当前的失配 = 「父亲的失配指向的点」的同样孩子
                }
            }
        }
    }
}
//=================  AC 自动机 END
using namespace AC;

void init(){
    scanf("%d",&n);
    int i,j;
    For(i,1,n){
        scanf("%s",s);
        build_ch(s);
    }
    bfs_next();
}

void get_ans(){
    int i=0,cnt=0,u =0;
    while(cnt < n){
        for(i=0;i<26;i++){
            if( !ch[u].real[i] ) continue;
            break;
        }
    }
}

//通过bfs得到答案
void bfs(){
    queue<node_t> q;
    q.push({0,1,0});
    vis[1][0] = 1;

    while( !q.empty()){
        
        node_t h = q.front();q.pop();
        //printf("%d,%d  ",h.id,h.step);
        //cout << bitset<12> (h.state) << endl;

        if( h.state == (1<<n)-1) { 
            //printf("yes\n");
            //printf("%d\n",h.step);
            printf("%s\n",h.s.c_str());
            //printf("\n");
            ;break;}

        int i,u = h.id;
        for( i = 0 ;i < 26 ;i++){
            int v = ch[u].e[i];
            if( vis[v][h.state] ) continue;
            int state = h.state,k = v;
            vis[v][state] = 1;
            while( k > 1){
                state |= ch[k].end;
                k = ch[k].next;
            }
            vis[v][state] = 1;
            q.push({h.step+1,v,state,h.s+char(i+'A')});
        }
    }
    //printf("no");
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    memset(s,0,sizeof(s));
    bfs();


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
