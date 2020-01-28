#include <cstdio>

int n,p;
const int maxn = 3e6+5;
int inv[maxn];
int main(){
    inv[1] = 1;
    scanf("%d%d",&n,&p);
    int i;
    printf("%d\n",1);
    for(i=2;i<=n;++i){
        inv[i] =(long long)(p - p/i) *inv[p % i] % p;
        printf("%d\n",inv[i]);
    }
    return 0;
}

