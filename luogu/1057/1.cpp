#include <cstdio>

int f[50][50];
int n,m;

void debug(int l){
    printf("%2d : ",l);
    int i;
    for(i=1;i<=n;++i){
        printf("%d ",f[l][i]);
    }
    printf("\n");
}
int main(){
    scanf("%d%d",&n,&m);
    f[0][1] = 1;
    int i,j;
    for(i=1;i<=m;++i){
        for(j=2;j<=n-1;++j){
                f[i][j] = f[i-1][j-1] + f[i-1][j+1];
        }
        if( 2!= n)
            f[i][1] = f[i-1][2]+f[i-1][n];
        else
            f[i][1] = f[i-1][2];

        if(n-1 != 1)
            f[i][n] = f[i-1][n-1]+f[i-1][1];
        else
            f[i][n] = f[i-1][n-1];
        //debug(i);
    }
    printf("%d\n",f[m][1]);
    return 0;
}

