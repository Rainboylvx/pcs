/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 26 Apr 2020 08:57:27 AM CST
* problem: loj-10058
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;

char s1[maxn*100];
char a[maxn][101];

int fa[maxn];
int word_cnt,end_world[maxn],len_word[maxn];
bool fail[maxn]; //这个位置是失配点
int flag[maxn]; //标记
int word_idx[maxn];

int _map[26]; //字符对应的数字
#define GET_N(c) _map[c-'A']

/* ======= 全局变量 END =======*/
namespace AC {

    //trie树,每个单词出现的次数,失配指针
    int ch[maxn][4],cntword[maxn],next[maxn],tot=1;
    int bo[maxn]; // 是否是单词
    const char START_CHAR = 'A';

    void ac_init(){ 
        tot=1;  //结点从1开始编号
        memset(bo,0,sizeof(bo));
        memset(ch,0,sizeof(ch));
        memset(next,0,sizeof(next));
    }

    void build(char *s){  // 建立ch树
        int len = strlen(s), u = 1;
        word_cnt++;
        len_word[word_cnt] = len;
        for(int i=0; i<len; ++i){
            int c = GET_N(s[i]);
            if( !ch[u][c]) ch[u][c] = ++tot;
            fa[ ch[u][c] ]  = u; //记录父亲
            u = ch[u][c];
        }
       bo[u]++;
       end_world[word_cnt] = u;
    }
    void  bfs_next(){
        for(int i =0;i<4;++i) ch[0][i] = 1;
        queue<int> q; q.push(1); //队列
        next[1] = 0;             //根的失配指针
        while( !q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0;i < 4; ++i){
                if( !ch[u][i]) ch[u][i] = ch[next[u]][i]; // 优化
                else {
                    q.push(ch[u][i]);
                    int v = next[u]; 
                    next[ ch[u][i] ] = ch[v][i];
                }
            }
        }
    }

    void find( char *s){
        int u = 1, len=strlen(s);
        for(int i = 0; i <len ;++i){
            //int c = _map[s[i] - START_CHAR];
            int c = GET_N(s[i]);
            u = ch[u][c];
            int k = u;
            while( k > 1){
                if( flag[k]) break;
                flag[k] = 1;
                k = next[k]; //
            }
        }
    }
}
using namespace AC;

void init(){
    _map['N'-'A'] = 0;
    _map['E'-'A'] = 1;
    _map['S'-'A'] = 2;
    _map['W'-'A'] = 3;
    scanf("%d%d",&n,&m);
    scanf("%s",s1);
    int i;
    For(i,1,m){
        scanf("%s",a[i]);
        build(a[i]);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    bfs_next();
    find(s1);

    //查找答案
    int i;
    for( i = 1 ;i<= word_cnt ;i++){
        int cnt = 0;
        int e = end_world[i];
        while( flag[e] == 0 && e != 1){
            cnt++;
            e = fa[e];
        }
        printf("%d\n",len_word[i]-cnt);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
