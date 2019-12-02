#include <cstdio>

int n;
int a[110];
int b[110];
int main(){
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for(i=1;i<=n;i++){ // 枚举 第i数 可能吗
        
        for(j=1;j<=n;j++){
            for(k=j+1;k<=n;k++){
                if( j == i || k == i) continue;
            }
        }
    }

    return 0;
}

