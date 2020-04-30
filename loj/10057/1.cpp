/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 19 Apr 2020 09:40:52 AM CST
* problem: loj-10057
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
int ans;

/* ======= 全局变量 END =======*/

namespace AC {

    //trie树,每个单词出现的次数,失配指针
    int trie[maxn][26],cntword[maxn],next[maxn],tot=1;
    int bo[maxn]; // 是否是单词

    void ac_init(){
        tot=1;
        memset(bo,0,sizeof(bo));
        memset(trie,0,sizeof(trie));
        memset(next,0,sizeof(next));
    }

    void build_trie(char *s){  // 建立trie树
        int len = strlen(s), u = 1;
        for(int i=0; i<len; ++i){
            int c = s[i] -'a';
            if( !trie[u][c]) trie[u][c] = ++tot;
            u = trie[u][c];
        }
       bo[u]++;
    }
    void  bfs_next(){
        for(int i =0;i<=25;++i) trie[0][i] = 1;
        queue<int> q; q.push(1); //队列
        next[1] = 0;             //根的失配指针
        while( !q.empty()){
            int u = q.front(); q.pop();
            for(int i = 0;i <= 25; ++i){
                if( !trie[u][i]) trie[u][i] = trie[next[u]][i]; // 优化
                else {
                    q.push(trie[u][i]);
                    int v = next[u]; 
                    next[ trie[u][i] ] = trie[v][i];
                }
            }
        }
    }

    void find( char *s){
        int u = 1, len=strlen(s);
        for(int i = 0; i <=len ;++i){
            int c = s[i] - 'a';
            int k = trie[u][c];
            while( k > 1){
                ans += bo[k];
                bo[k] = 0;
                k = next[k];
            }
            u = trie[u][c];
        }
    }
}
using namespace AC;

char s[maxn];
void init(){
    ans = 0;
    ac_init();
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%s",s);
        build_trie(s);
    }
    bfs_next();
    scanf("%s",s);
    find(s);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        printf("%d\n",ans);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
