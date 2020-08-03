#include <cstdio>
const int maxn = 1e6+5;
int pre[maxn]; //前缀和
int notp[maxn]; //不是素数

int n,m;

void ola(){
    int i,j;
    for(i =2;i<=maxn;i++){
        if(!notp[i] ) {
            pre[i] = pre[i-1] +1;
            notp[ ++notp[0] ] = i;
        }
        else
            pre[i] = pre[i-1];
        for(j=1;j<=notp[0] && i*notp[j] < maxn;j++){
            notp[ notp[j]*i] = 1;
            if( i % notp[j] == 0) break;
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    ola();
    int i,l,r;
    for(i=1;i<=n;++i){
        scanf("%d%d",&l,&r);
        if( l < 1 || l > m || r < 1 || r >m){
            printf("Crossing the line\n");
        }
        else
            printf("%d\n",pre[r]-pre[l-1]);

    }
    return 0;
}

