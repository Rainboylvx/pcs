/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 10:23:33 CST
* problem: hdu-1754
*----------------*/
#include <bits/stdc++.h>
using namespace std;

int n,m;

#define maxn 200005

int tree[maxn<<2];

inline int lson(int rt){ return (rt<<1);}
inline int rson(int rt){ return (rt<<1)|1;}

void pushup(int rt){
    tree[rt] = max(tree[lson(rt)],tree[rson(rt)]);
}

void build(int l,int r,int rt){
    if( l == r ){
        scanf("%d",&tree[rt]);
        return;
    }
    int m = (l+r)>>1;
    build(l, m, lson(rt));
    build(m+1, r, rson(rt));
    pushup(rt);
}

void update(int p,int f,int l,int r,int rt){
    if( l == r ){
        tree[rt] = f;
        return;
    }
    int m = (l+r)>>1;
    if( p <= m)
        update(p,f,l,m,lson(rt));
    else
        update(p,f,m+1,r,rson(rt));
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(L <=l && R >=r){
        return tree[rt];
    }

    int m = (l+r) >>1;
    int a1=0,a2=0;
    if( L <=m)
        a1 = query(L,R,l,m,lson(rt));
    if( R > m)
        a2 = query(L,R,m+1,r,rson(rt));
    return max(a1,a2);
}
void init(){
    build(1, n, 1);
    int i,j,k;
    char t[100];
    for (i=1;i<=m;i++){
        scanf("%s",t);
        scanf("%d%d",&j,&k);
        if( t[0] == 'U')
            update(j, k, 1, n, 1);
        else{
            int ans = query(j,k,1,n,1);
            printf("%d\n",ans);
        }
    }
}

int main(){
    while( scanf("%d%d",&n,&m)!=EOF){
        init();
    }
    return 0;
}
