#include <bits/stdc++.h>
using namespace std;

int m[100][100];
bool vis[100][100];

int max_dep = 100;
int fx[][2] = { 1,0, -1,0, 0,-1, 0,1 };

struct pos {
    int x,y;
};
vector<pos> v1(100),v2(100);

void init(){
    int i,j;
    for (i=1;i<=5;i++){
        for (j=1;j<=5;j++){
            scanf("%d",&m[i][j]);
        }
    }
    memset(vis,0,sizeof(vis));
}

bool in_map(int x,int y){
    if( x >=1 && y <= 5 && x<=5 && y >=1)
        return 1;
    return 0;
}


void dfs(int x,int y,int dep){
    if(x == 5 && y == 5){
        if( dep < max_dep){
            max_dep = dep;
            v1[dep] = {x,y};
            copy(v1.begin(),v1.end(),v2.begin());
        }
        return;
    }

    vis[x][y] =1;
    v1[dep] = {x,y};

    int i;
    for (i=0;i<4;i++){
        int nx = x + fx[i][0];
        int ny = y + fx[i][1];

        if( in_map(nx,ny) && !vis[nx][ny] && m[nx][ny] == 0){
            dfs(nx,ny,dep+1);
            vis[nx][ny] = 0;
        }
    }
}


int main(){
    init();
    dfs(1,1,1);
    int i;
    for( i =1;i<=max_dep;i++){
        pos &p = v2[i];
        printf("(%d, %d)\n",p.x-1,p.y-1);

    }
    return 0;
}
