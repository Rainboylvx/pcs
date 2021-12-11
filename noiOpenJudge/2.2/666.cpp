/* 
 * 0 0 7
 * 0 1 6
 * 组合
 * */
int t;
int n,m;
#include <cstdio>

int cnt = 0;
void dfs(int dep,int pre,int remaind){
    if( remaind < pre) return;
    if( dep == m){
        if( remaind >= pre){
            cnt++;
        }
        return ;
    }
    int i;
    for(i = pre;i<=remaind;i++){
        dfs(dep+1,i,remaind-i);
    }
}

int main(){
    scanf("%d",&t);
    int i;
    for (i=1;i<=t;i++){
        cnt = 0;
        scanf("%d%d",&n,&m);
        dfs(1,0,n);
        printf("%d\n",cnt);
    }
    return 0;
}
