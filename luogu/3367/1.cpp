#include <cstdio>

int fa[10005];
int n,m;

int find(int u){
    if( fa[u] == u) return u;
    return fa[u] = find(fa[u]);
}

void merge(int u,int v){
    int fu = find(u);
    int fv = find(v);
    if( fu == fv) return;
    fa[fv] = fu;
}


int main(){
    scanf("%d%d",&n,&m);
    int z,x,y;
    int i;
    for(i=1;i<=n;++i) fa[i] = i;

    for(i=1;i<=m;++i){
        scanf("%d%d%d",&z,&x,&y);
        if( z == 1){
            merge(x, y);
        }
        else {
            if( find(x) == find(y)) 
                printf("Y\n");
            else 
                printf("N\n");
        }
    }

    return 0;
}

