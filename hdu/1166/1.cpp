#include <bits/stdc++.h>
using namespace std;


int n;
int tree[(50000<<2)+5];

inline int lson(int rt){ return rt<<1; }
inline int rson(int rt){ return (rt<<1)|1;}

#define mid ((l+r)>>1);


void pushup(int rt){
    tree[rt] = tree[rson(rt)] + tree[lson(rt)];
}

//l ,r [1,3]
//l r [1,2]
void build(int l,int r,int rt){
    if(l == r){
        scanf("%d",&tree[rt]);
        return;
    }

    int m =(l+r)>>1;
    build(l,m,lson(rt));
    build(m+1,r,rson(rt));
    pushup(rt);
}


void dfs(int l,int r,int rt){
    if( l == r){
        printf("%d: %d\n",rt,tree[rt]);
        return ;
    }
        printf("%d: %d\n",rt,tree[rt]);
    int m =(l+r)>>1;
    dfs(l,m,lson(rt));
    dfs(m+1,r,rson(rt));
}

void update(int pos,int add,int l,int r,int rt){
    if( l == r){
        tree[rt] += add;
        return ;
    }

    int m = (l+r) >>1;
    //l ->m
    if( pos <=m)
        update(pos,add,l,m,lson(rt));
    else
        update(pos,add,m+1,r,rson(rt));
    pushup(rt);
}

int query(int L,int R,int l,int r,int rt){
    if(L<=l && r <=R){
        return tree[rt];
    }

    int m = (l+r)>>1;
    int ans = 0;
    if( L <= m)
        ans += query(L,R,l,m,lson(rt));
    if (m+1 <= R)
        ans += query(L,R,m+1,r,rson(rt));
    return ans;
}



char str[100];
int main(){
    int T;
    scanf("%d",&T);
    int idx=0;
    while(T--){
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",++idx);
        while(1){
            int i,j,k;
            scanf("%s",str);
            if(str[0] == 'Q'){
                scanf("%d%d",&i,&j);
                int ans = query(i,j,1,n,1);
                printf("%d\n",ans);
            }
            else if ( str[0]=='A'){
                scanf("%d%d",&i,&j);
                update(i,j,1,n,1);
            }
            else if(str[0]=='S'){
                scanf("%d%d",&i,&j);
                update(i,-j,1,n,1);
            }
            else if( str[0] == 'E')
                break;
        }

    }
    return 0;
}
