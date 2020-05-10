#include <cstdio>

int n,m,p;
int fa[5005];

int find(int u){
    if( fa[u]== u) return u;
    return fa[u]=find(fa[u]);
}

void merge(int u,int v ){
    int fu = find(u);
    int fv = find(v);
    if( fu == fv) return;
    fa[fv] = fu;
}

int main(){
    scanf("%d%d%d",&n,&m,&p);
    int i,x,y,z;
    for(i=1;i<=n;++i){
        fa[i] = i;
    }
    for(i=1;i<=m;++i){
        scanf("%d%d",&x,&y);
        merge(x, y);
    }
    for(i=1;i<=p;++i){
        scanf("%d%d",&x,&y);
        if( find(x) == find(y))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}

