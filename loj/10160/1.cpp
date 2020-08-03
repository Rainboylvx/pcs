#include <cstdio>

#define N 6005
int n;
int h[N],fa[N]; //happy,father

int f[N][2] = {0};
bool vis[N][2] = {0};

int g[N][N]={0}; //存图,模拟邻接表
int root;

int max(int a,int b){
    if(a> b) return a;
    return b;
}

int dfs(int x,bool in){
    int  ans = 0;
    int i;
    if( vis[x][in] == 1) //已经算过
        return f[x][in];

    vis[x][in] = 1; //标记已经算过
    
    for(i=1;i<=g[x][0];i++){
        if( in )
            ans+= dfs(g[x][i],0);
        else
            ans+= max( dfs(g[x][i],0),dfs(g[x][i],1));
    }

    if( in ) ans+=h[x]; //如果参加了 要加上这个点的值

    f[x][in] = ans;

    return f[x][in];
}

int main(){
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;i++){
        scanf("%d",&h[i]);
        fa[i] = i; //初始化
    }

    for(i=1;i<n;i++){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        g[t2][ ++g[t2][0] ] = t1;
        fa[t1] = t2;
    }

    root = 1;
    while( fa[root] != root) root = fa[root]; //找到root点

    int a = dfs(root,0);
    int b = dfs(root,1);
    printf("%d",max(a,b));

    return 0;
}
