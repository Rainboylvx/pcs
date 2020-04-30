/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 29 Apr 2020 09:19:44 PM CST
* problem: loj-10059
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int len_s;
int n,m;
char s[maxn];
struct list_node {
    char c; int u;
}ans[maxn];
int ans_cnt = 0;

namespace AC {
    const int size = 26;
    const char START_CH = 'a';

    int tot = 1; // 点的计数
    struct ac_node {
        int e[size]; // 指向下一个点的边
        int end;     // 单词的结束
        int next;    // 失配指针
        int end_len;
    }ch[maxn];

    inline int GET_N(char c){ return c - START_CH;}

    void ac_init(){
        tot = 1;
        memset(ch,0,sizeof(ch));
    }

    // 建立trie树
    void build(char *s){
        int len = strlen(s), u = 1;
        for( int i = 0 ;i < len;++i ){
            int c = GET_N(s[i]);
            if( !ch[u].e[c] ) ch[u].e[c] = ++tot;
            int t = u;
            u = ch[u].e[c];
        }
        ch[u].end = 1; // 单词结束标记
        ch[u].end_len = len;
    }

    // 建立失配指针
    void bfs_next(){
        for(int i = 0 ; i < size ;++i) ch[0].e[i] = 1;
        queue<int> q; q.push(1); //队列
        ch[1].next = 0;

        while( !q.empty() ){
            int u = q.front();q.pop();
            for( int i = 0;i< size; ++i){
                if( !ch[u].e[i]) ch[u].e[i] = ch[ ch[u].next ].e[i];
                else {
                    int child = ch[u].e[i];
                    q.push(child);
                    ch[ child ].next = ch[ ch[u].next ].e[i];
                }
            }
        }
    }


    //查找
    void find(char *s){
        int u = 1, len = strlen(s);
        for(int i=0;i<len;++i){
            int c= GET_N(s[i]);
            u = ch[u].e[c];
            int k = u;
            ans[++ans_cnt] = {s[i],u};
            if( ch[k].end){ //结束 ???????????
                ans_cnt -= ch[k].end_len;
                u = ans[ans_cnt].u;
            }
        }
    }

}
using namespace AC;

/* ======= 全局变量 END =======*/
char tmp[maxn];
void init(){
    scanf("%s",s);
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%s",tmp);
        build(tmp);
    }
    bfs_next();
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    find(s);
    int i;
    for(i = 1 ;i<=ans_cnt;++i)
        printf("%c",ans[i].c);
    printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
