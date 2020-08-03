/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 01月 10日 星期五 16:36:12 CST
* problem: luogu-4513
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 5e5+5;
int n,m;
int k,t1,t2,t;

//合并区间
struct node {
    int l,r,sum,_max; //区间和
    node operator+(const node &b){
        node n;
        n.sum = sum +b.sum;
        n._max = max(
                        max(_max,b._max),
                        r+b.l 
                );
        n.l = max(l,sum+b.l);
        n.r = max(b.r,b.sum+r);

        return n;
    }
};
/* ======= 全局变量 END =======*/


/* =====  线段树区间更新--lazy [区间加,区间求和] ====*/

/* 区间加,区间求和 的线段树 */
node st[maxn<<2]={0};    //线段树
//memeset(flag,0/-1,sizeof(flag))

inline int lson(int rt ){ return rt<<1;}
inline int rson(int rt ){ return (rt<<1)|1;}
/* 更新父亲 */
void pushup(int rt){
    st[rt] = st[lson(rt)] + st[rson(rt)];
}

/* 区间更新 -- lazy */
void update(int pos ,int val,int l,int r,int rt){
    if( l == r){
        st[rt]._max = val;
        st[rt].sum = val;
        st[rt].l = st[rt].r = st[rt].sum; 
        return;
    }
    int m = (l+r) >>1;
    if( pos <= m) update(pos, val, l, m, lson(rt));
    else update(pos, val, m+1, r, rson(rt));
    pushup(rt);
}

/* 区间查询 */
node query(int l1,int r1,int l,int r,int rt){
    if(l1<=l && r <= r1){//包含
        return st[rt];
    }

    node t,t1={0,0,inf3f},t2={0,0,inf3f};
    int m = (l+r)>>1;
    if(l1 <= m) t1= query(l1,r1,l,m,lson(rt));
    if(r1 > m ) t2= query(l1,r1,m+1,r,rson(rt));

    if( l1 <=m && r1 > m)
        return t1+t2;
    else if( l1 <=m)
        return t1;
    else
        return t2;
}

/* 建立线段树 */
void build(int l,int r,int rt){
    if( l==r){
        scanf("%d",&st[rt].sum);
        st[rt]._max = st[rt].sum;
        st[rt].l = st[rt].r = st[rt].sum; 
        return ;
    }
    int m = (l+r)>>1;
    build(l,m,lson(rt));
    build(m+1,r,rson(rt));
    pushup(rt);
}

/* ====== 线段树区间更新--lazy-- END ====*/



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    scanf("%d%d",&n,&m);
    build(1,n,1); //建树
    int i;
    For(i,1,m){
        scanf("%d%d%d",&k,&t1,&t2);
        if( k ==  1){
            if( t1 > t2) swap(t1, t2);
            node ans = query(t1, t2, 1, n, 1);
            printf("%d\n",ans._max);
        }
        else 
            update(t1, t2, 1, n, 1);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
