#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
int n,m;

int g[100][100];

void init(){
}
/* ======= 全局变量 END =======*/


int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            scanf("%d",&g[i][j]);
            if( g[i][j] && i > j){
                printf("%d -> %d;\n",i,j);
            }
        }
    }
    return 0;
}
