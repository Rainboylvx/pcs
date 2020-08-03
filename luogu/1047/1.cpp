#include <cstdio>

const int maxn = 1e4+5;

int l,m;
int a[maxn];
int main(){
    scanf("%d%d",&l,&m);
    int t1,t2;
    int i,j;
    for(i=1;i<=m;i++){
        scanf("%d%d",&t1,&t2);
        for(j=t1;j<=t2;j++){
            a[j] = 1;
        }
    }
    int ans = 0;
    for(i=0;i<=l;i++){
        if( a[i] == 0)
            ans++;
    }
    printf("%d\n",ans);
    return 0;
}

