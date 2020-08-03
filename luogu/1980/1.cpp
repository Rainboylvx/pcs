#include <cstdio>

int main(){
    int n,x;
    scanf("%d%d",&n,&x);
    int i,j,ans = 0;
    for(i=1;i<=n;i++){
        int t = i;
        for( ; t ; ){
            int g = t % 10;
            if( g == x)
                ans++;
            t /= 10;
        }
    }
    printf("%d\n",ans);
    return 0;
}
