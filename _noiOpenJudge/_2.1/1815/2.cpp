#include <stdio.h>
#include<string.h>
bool a[17][17]={0},b[17][17]={0};
int n,num;
bool press(){
    num=0;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n;j++){
            b[i][j]=(b[i-2][j]+b[i-1][j]+b[i-1][j-1]+b[i-1][j+1]+a[i-1][j])%2;
            if(b[i][j])num++;
        }
    }
    for(int j=1;j<=n;j++){
        if((a[n][j]+b[n-1][j]+b[n][j]+b[n][j-1]+b[n][j+1])%2)return 0;
        if(b[1][j])num++;
    }
    return 1;
}
int main( ){
    scanf("%d",&n);
    char c;int min=1e5;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
        scanf("%c",&c);
        if(c==' '||c=='\n')j--;
        else a[i][j]=('y'-c)/2;
    }
    for(int i=0,l=1<<n;i<l;i++){
        for(int j=1;j<=n;j++)b[1][j]=i>>(n-j)&1;
        bool k=press();
        if(k)if(num<min)min=num;
    }
    if(min!=1e5)printf("%d",min);else printf("inf");
    return 0;
}
