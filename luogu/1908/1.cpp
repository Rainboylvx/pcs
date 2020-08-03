// 动态开点线段树,不使用离散化
#include <bits/stdc++.h>
using namespace std;

#define XXX 1e9

/* ======= 全局变量 =======*/ int n;
long long ans;
const int maxn = 1e7+5;

// 动态开点线段树 内存池
int root,cnt; //线段树的根,结点计数
struct _tree{ int val,l,r; } tree[maxn];

/* ======= 全局变量 END =======*/

void newnode(int &p,int val){
    p = ++cnt;
    tree[p].val = val;
    tree[p].l = tree[p].r = 0;
}

inline void push_up(int p){
    tree[p].val = tree[ tree[p].l ].val + tree[ tree[p].r ].val ;
}

/* 单点更新*/
void update(int &u ,int L,int R,int pos,int val){
    if( !u )     //建立点
        newnode(u, 0);
    if( L == R ) {//叶子结点
        tree[u].val += val;return;
    }
    int m = (L+R) >> 1;
    if( pos<=m ) //在左边
        update(tree[u].l, L,m,pos,val);
    else
        update(tree[u].r, m+1,R,pos,val);
    push_up(u);
}

/* 区间求和 */
int query_sum(int u,int L,int R,int l,int r){
    /* 边界: 这个点不存在 */
    if( !u ) return 0;
    /* 边界: 完全包含 */
    if( l <= L && R <=r)
        return tree[u].val;

    int m = (L+R) >> 1;
    int sum = 0;
    if( l <= m)
        sum+= query_sum(tree[u].l, L, m, l, r);
    if( r > m )
        sum+= query_sum(tree[u].r, m+1, R, l, r);
    return sum;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d",&n);
    int i,t;
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        ans += query_sum(root, 1, XXX, t+1, XXX);
        update(root, 1, XXX, t, 1);
    }
    printf("%lld\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
