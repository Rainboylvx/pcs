#include <cstdio>

const int maxn = 1e5+5;
int f[maxn];
#define mod 100003

int n,m;
int main(){
    scanf("%d%d",&n,&m);
    f[0] = 1;
    f[1] = 1;
    int i,j;
    for(i=2;i<=m;++i){
        for(j=0;j<=i-1;++j){
            f[i] = (f[i]+ f[j]) %mod;
        }
    }
    for(i=m+1;i<=n;i++){
        for(j=1;j<=m;++j){
            f[i] =(f[i]+ f[i-j]) % mod;
        }
    }
    printf("%d\n",f[n]);
    return 0;
}

