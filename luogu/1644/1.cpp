#include <cstdio>

int n,m;
int cnt = 0;

int fx[] = {1,2,2,1};
int fy[] = {2,1,-1,-2};

bool in_map(int x,int y){
    if( x >= 0 && x <= m && y >= 0 && y <= n)
        return 1;
    return 0;
}

void dfs(int x,int y){
    if( x == m && y == n){
        cnt++;
        return ;
    }
    int i;
    for(i=0;i<4;i++){
        int nx = x+fx[i];
        int ny = y+fy[i];
        if( in_map(nx,ny)){
            dfs(nx,ny);
        }
    }
}

void init(){
    scanf("%d%d",&n,&m);
}
int main(){
    init();
    dfs(0,0);
    printf("%d",cnt);
    return 0;
}
