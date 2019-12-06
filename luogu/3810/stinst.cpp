/* 线段树套线段树  */
/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 05日 星期四 14:56:18 CST
* problem:  luogu-3810
*----------------*/
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxlen = 200010;
int n,k;
int cnt; //去重用
int ans[maxn]; // 存答案


struct ele {
    int a,b,c,w,f;
    bool operator<(const ele &y){
        if( a != y.a ) return a < y.a;
        if( b != y.b) return b <y.b;
        return c < y.c;
    }
}e[maxn];

struct node{
    int lc,rc,val;
}stx[maxn<<1],sty[(int)1e8];//竟然不超内存???
int rootx,rooty[maxn<<1]; //线段树y 的根
int cntx,cnty; //线段树 计数

/* 第三维 线段树 插入 */
void st_y_ins(int &u,int l,int r,int pos){
    if( u == 0) u = ++cnty;
    sty[u].val += e[pos].w; //这一条链上的点都加
    if( l == r) return;
    int mid = (l+r) >>1;
    if( e[pos].c <= mid ) st_y_ins(sty[u].lc, l, mid, pos);
    if( e[pos].c > mid) st_y_ins(sty[u].rc, mid+1, r, pos);
}

/* 第三维 线段树 查询 */
int st_y_query(int u,int l,int r,int x,int y){
    if( u == 0) return 0;
    if(x <= l && r <= y) return sty[u].val;
    int mid = (l+r) >> 1;
    int res = 0;
    if( x <= mid ) res+= st_y_query(sty[u].lc, l, mid, x, y);
    if( y > mid ) res += st_y_query(sty[u].rc,mid+1,r,x,y);
    return res;
}

void dfs_st_y(int root){
    if( !root ) return;
    printf("val : %d : %d \n",root,sty[root].val);
    if( sty[root].lc ){
        printf("l : %d -> %d \n",root,sty[root].lc);
        dfs_st_y(sty[root].lc);
    }
    if( sty[root].rc ){
        printf("r : %d -> %d \n",root,sty[root].rc);
        dfs_st_y(sty[root].rc);
    }
}

/* 第二维 线段树 插入 */
void st_x_ins(int &u,int l,int r,int pos){
    if( u == 0) u = ++cntx;
    st_y_ins(rooty[u],1,maxlen,pos);
    if( l == r) return ;
    int mid = (l+r) >>1;
    if(e[pos].b <=mid)
        st_x_ins(stx[u].lc, l, mid, pos);
    else
        st_x_ins(stx[u].rc, mid+1, r, pos);
}

/* 第二维 线段树 查询 */
int st_x_query(int u,int l,int r,int x){
    if( k == 0) return 0;
    if( 1 <=l && r <= e[x].b) 
        return st_y_query(rooty[u], 1, maxlen, 1,e[x].c);
    int mid = (l+r) >> 1;
    int res = 0;
    if( 1 <= mid ) res += st_x_query(stx[u].lc, l,mid, x);
    if( e[x].b > mid ) res += st_x_query(stx[u].rc, mid+1, r, x);
    return res;
}


/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d",&n,&k);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].c);
        e[i].w = 1;
    }
    sort(e+1,e+n+1);   //排序
    cnt = 1;
    for(i=2;i<=n;i++){ //去重
        if( e[i].a == e[cnt].a && e[i].b == e[cnt].b && e[i].c == e[cnt].c ){
            e[cnt].w++;
        }
        else
            e[++cnt] = e[i];
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init(); //数据读取 与 排序去重
    int i;
/*
 *    #ifdef DEBUG
 *        //输出排序后的数组
 *        for(i=1;i<=cnt;i++){
 *            printf("%d %d %d %d\n",e[i].a,e[i].b,e[i].c,e[i].w);
 *        }
 *
 *    #endif
 */
    for( i =1 ;i<= cnt; i++){
        st_x_ins(rootx, 1, maxlen, i);   //先插入
        int res = st_x_query(rootx,1,maxlen,i); //然后查询
        //ans[res]++;
        ans[res-1] += e[i].w;
        //printf("%d %d\n",res,ans[res-1]);
    }
    for(i=0;i<n;i++){
        //printf("%d\n",ans[i]-1 == -1 ? 0 : ans[i]-1);
        printf("%d\n",ans[i]);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
