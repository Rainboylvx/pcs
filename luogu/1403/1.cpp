#include <cstdio>

int n ,ans;
int main(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;++i){
        ans += n/i;
    }
    printf("%d\n",ans);
    return 0;
}

