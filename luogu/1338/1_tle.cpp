#include <cstdio>
const int maxn = 50005;
int a[maxn];
bool vis[maxn];
int choose[maxn];
int n,m;
typedef long long ll;
inline ll g(ll n){ return (n-1)*n/2; }

bool dfs(int dep,int cnt){
    if( dep > n){  //边界
        //int i;
        //for(i=1;i<=n;++i){
            //printf("%d ",choose[i]);
        //}
        return 1;
    }
    int i,les = 0; //les 小于选中的个数
    if( cnt == 0){
        for(i=1;i<=n;++i){
            if( !vis[i]) printf("%d ",i);
        }
        return 1;
    }
    for(i=1;i<=n;++i){
        if( vis[i]) continue;
        //如果选这个数
        ll s = g(n-dep)+les;
        if( s >= cnt){
            choose[dep] = i;
            vis[i] = 1;
            printf("%d ",i);
            if( dfs(dep+1,cnt-les))
                return 1;
            vis[i] = 0;
        }
        les++;
    }
    return 0;
}

int main(){
    scanf("%d%d",&n,&m);
    dfs(1,m);
    return 0;
}
