/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 06日 星期五 15:18:35 CST
* problem:  uva-548
*----------------*/
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
#define inf7f 0x7f7f7f7f
#define inf3f 0x3f3f3f3f
#define inf inf7f

const int maxn = 1e5+5;
int lmr[maxn]; // 中序
int lrm[maxn]; // 后序
int sum[maxn];
int ans,ans_node;
/* ======= 全局变量 END =======*/

int read_line_int(int a[]){
    int cnt=0;
    char c;
    while(1){
        scanf("%d",&a[++cnt]);
        int ret = scanf("%c",&c);
        if( c == '\n' || c == '\r')
            return cnt;
        if( ret == EOF )
            return EOF;
    }
}
void init(){
    memset(sum,0,sizeof(sum));
    ans = inf;
}

// a 中序起始下标 b 后序起始下标 len 长度 fa 父亲
void rebuild(int a,int b,int len ,int fa){
    int root = lrm[b+len-1];
    int i=a;
    while( root != lmr[i]) i++;
    sum[i] = sum[fa]+lmr[i];

    if( len == 1){ // 叶子结点
        if( sum[a] < ans){
            ans = sum[a];
            ans_node = lmr[a];
        }
        else if ( sum[a] == ans && ans_node > lmr[a]){
            ans_node = lmr[a];
        }
        return;
    }
    int lc_len = i-a;
    int rc_len = len-lc_len-1;
    if(lc_len > 0) { //左子树存在
        rebuild(a, b, lc_len , i);
    }
    if(rc_len > 0){ //右子树存在
        rebuild(i+1,b+lc_len,rc_len,i);
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while(1){
        init();
        int len = read_line_int(lmr);
        len = read_line_int(lrm);
        if( len == EOF) break;
        int i;
        rebuild(1, 1, len, 0);
        printf("%d\n",ans_node);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
