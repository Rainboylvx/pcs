#include <cstdio>

int ans;
int a[100];
int n,k;

/* dep 深度 */
void dfs(int dep){
    if( dep == k+1){
        if( n == 0) ans++; 
        return ;
    }

    int i;
    int av = n / (k-dep+1);
    for( i= a[dep-1];i <=av;i++){ //上下界
        n -= i;
        a[dep] = i;
        dfs(dep+1);
        n += i;
    }
}

int main(){
    scanf("%d%d",&n,&k);
    a[0] = 1;// 初始条件,a[0] 最为虚拟点
    dfs(1);
    printf("%d\n",ans);
    return 0;
}

