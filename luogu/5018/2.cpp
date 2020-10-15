/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 11日 星期二 14:48:08 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+5;
int n,m;
struct NODE {
    int l,r,v;
};
NODE node[maxn];
int son[maxn];
int ans = -1;

void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i) scanf("%d",&node[i].v);
    for(i=1;i<=n;++i) scanf("%d%d",&node[i].l,&node[i].r);
}

bool dfs_cmp(int u1,int u2){
    if( u1 == -1 && u2 ==-1) return 1;
    if( node[u1].v != node[u2].v ) return 0;
    return dfs_cmp(node[u1].l,node[u2].r) && dfs_cmp(node[u1].r,node[u2].l);
}

void dfs_son(int u){
    if( u == -1) return;
    son[u] =1;
    dfs_son(node[u].l);
    dfs_son(node[u].r);
    son[u] += ( son[node[u].l]+ son[node[u].r]);
}

//bool dfs_change(int u){
    //if( u == -1) return 1;
    ////dfs_change(node[u].l);
    ////dfs_change(node[u].r);
    //bool flag = 0;
    //if( lret  && rret){
        //flag = dfs_cmp(node[u].l, node[u].r);
    //}
    //if( flag ){
        //ans = max(ans,son[u]);
    //}
    //swap(node[u].l,node[u].r);
    //return flag;
//}

int main(){
    init();
    dfs_son(1);
    int i;
    for( i =1;i<=n;i++){
        if( dfs_cmp(node[i].l, node[i].r))
            ans = max(ans,son[i]);
    }
    printf("%d\n",ans);
    return 0;
}
