#include <iostream>
#include <cstring>

int f[10005];

int main(){
    memset(f,-1,sizeof(f));
    f[0] = 0;

    int v,n,c;
    scanf("%d%d%d",&v,&n,&c);


    //for(int j=0;j<=c;++j){
        //printf("%d ",f[j]);
    //}
    //printf("\n");

    for(int i=1;i<=n;++i){
        int k,m; //体积 体力
        scanf("%d%d",&k,&m);
        for(int j = c ;j >= m;j--){
            if( f[j-m] != -1 && f[j-m] + k > f[j])
                f[j] = f[j-m]+k;
        }
        //for(int j=0;j<=c;++j){
            //printf("%d ",f[j]);
        //}
        //printf("\n");
    }

    for(int i =0; i<= c ;i++){
        if( f[i] >= v){
            printf("%d",c-i);
            return 0;
        }
    }
    printf("Impossible");

    return 0;
}
