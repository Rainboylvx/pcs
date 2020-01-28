/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 17日 星期二 17:04:20 CST
* problem:  loj-10049
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n;
char str[10000];

struct trie {
  int nex[100000][26], cnt;
  bool exist[100000];  // 该结点结尾的字符串是否存在

  void insert(char *s, int l) {  // 插入字符串
    int p = 0;
    for (int i = 0; i < l; i++) {
      int c = s[i] - '0';
      if (!nex[p][c]) nex[p][c] = ++cnt;  // 如果没有，就添加结点
      p = nex[p][c];
    }
    exist[p] = 1;
  }
  bool find(char *s, int l) {  // 是否有相同的前缀
    int i,p = 0; 
    for (i = 0; i < l; i++) {
      int c = s[i] - '0';
      if (!nex[p][c]) return 0;
      p = nex[p][c];
      if( exist[p] ) return 1;
    }
    return i == l; //是不是把自己找完了
  }
};
trie mytrie;
bool flag;
void init(){
    //memset(mytrie,0,sizeof(mytrie));
    memset(mytrie.nex,0,sizeof(mytrie.nex));
    memset(mytrie.exist,0,sizeof(mytrie.exist));
    mytrie.cnt = 0;
    flag = 0;
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%s",str);
        int len = strlen(str);
        // 查找
        if( !flag ) flag = mytrie.find(str,len);
        // 插入
        if( flag ) continue;
        mytrie.insert(str, len);
    }
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while( t-- ){
        init();
        if( flag) 
            printf("NO\n");
        else
            printf("YES\n");
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
