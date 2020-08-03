#include <cstdio>
const int maxn = 1e5+5;
int t,ans=1,n,m;
int main(){
    scanf("%d%d",&n,&m);
    int i;
    int s = 0;
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        if( s + t > m) ans++,s=t;
        else s+=t;
    }
    printf("%d\n",ans);
    return 0;
}

