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
};
list<list_node> li;

namespace AC {
    const int size = 26;
    const char START_CH = 'a';

    int tot = 1; // 点的计数
    struct ac_node {
        int e[size]; // 指向下一个点的边
        int end;     // 单词的结束
        int next;    // 失配指针
        int fa;     //父亲
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
            ch[u].fa = t;
        }
        ch[u].end = 1; // 单词结束标记
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

    void print_li(){
        for (const auto& e : li) {
            printf("%c",e.c);
        }
        printf("\n");
    }

    //查找
    void find(){
        int u = 1;
            //len = strlen(s);
        li.push_front({0,1}); //占位用
        list<list_node>::iterator it = li.begin();
        it++;
        for( ; it != li.end(); ++it){
            //debug
            //printf("%c\n",(*it).c);
            int c= GET_N((*it).c);
            u = ch[u].e[c];
            it->u = u;
            int k = u;
            while( k > 1){
                if( ch[k].end){ //结束
                    int t=k;
                    list<list_node>::iterator itt = it;
                    list<list_node>::iterator itt_last = ++it;
                    while( t !=1 ){
                        itt--;
                        t = ch[t].fa;
                    }

                    u = itt->u;
                    it = itt;
                    itt++;
                    li.erase(itt, itt_last);
                    break;
                }
                k = ch[k].next;
            }
        }

        li.pop_front();
    }

}
using namespace AC;

/* ======= 全局变量 END =======*/
char tmp[maxn];
void init(){
    scanf("%s",s);
    int i;
    int len = strlen(s);
    len_s = len;
    For(i,0,len-1){
        li.push_back({s[i],0});
    }
    scanf("%d",&n);
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
    find();
    for (const auto& e : li) {
        printf("%c",e.c);
    }
    printf("\n");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
