#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


#define N 100 //点的数量

int n,m;
//边集数组
struct edge {
    int u,v,w;
}E[N];
int __size = 0;

void addEdge(int x,int y,int z){
    __size++;
    E[__size].u = x;
    E[__size].v = y;
    E[__size].w = z;
}

bool cmp(const edge &a,const edge &b){
    if( a.w > b.w)
        return false;
    return true;
}

//并查集
int fa[N];

int find(int x){
    int t =x;
    while(fa[t] != t) //不停的往上走
        t=fa[t];
    int i = x,j;//路径压缩，再走一便路程，把走过的点都指向根
    while(i != t){
        j= fa[i];
        fa[i] = t; // 把这个点指向根
        i = j;
    }
    return t;
}

int kruskal(int s){
    int ans = 0;
    int i,j;
    int k=0 ;
    for(i=1;i<=n;i++) fa[i] = i; //并查集初始化
    for(i=1;i<=m;i++){
        int f1 = find(E[i].u);
        int f2 = find(E[i].v);
        if( f1 != f2){
            ans += E[i].w;
            fa[f1] = f2;
            k++;
            if( k == n-1) break; //选n-1条边
        }
    }
    if( k < n-1)
        return -1; //返回不可能
    else 
        return ans;
}

int main(){
    scanf("%d%d",&n,&m);
    int i,j;
    //读入图
    for(i=1;i<=m;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addEdge(x,y,z);
    }
    sort(E+1,E+__size+1,cmp);
    int ans = kruskal(1);
    printf("%d",ans);
    return 0;
}
