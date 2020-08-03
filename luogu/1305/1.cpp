#include <cstdio>

int n;
struct node { int l,r; } tree[100];

inline int idx(char c){
    if( c == '*') return 0;
    return c-'a'+1;
}
int root;
int fa[100];

void dfs(int u){
    if( !u ) return;
    printf("%c",u+'a'-1);
    dfs(tree[u].l);
    dfs(tree[u].r);
}

int main(){
    scanf("%d",&n);
    int i,j;
    char tmp[100];
    for(i=1;i<=n;++i){
        scanf("%s",tmp+1);
        tree[idx(tmp[1])].l = idx(tmp[2]);
        tree[idx(tmp[1])].r = idx(tmp[3]);
        fa[idx(tmp[2])]= fa[idx(tmp[3])]= idx(tmp[1]);
        root = idx(tmp[1]);
    }
    while( fa[root]!=0) root = fa[root];
    dfs(root);
    return 0;
}

