#include <cstdio>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)


const int maxn = 40000+5;
int sum;
int n;
int flag[maxn],prime[maxn],phi[maxn];
void eulr(int n){
    phi[1] = 1;
    int i,j;
    For(i,2,n){
        if( flag[i] == 0){
            prime[++ prime[0] ]= i;
            phi[i] = i -1;
        }
        for(j=1 ;j <= prime[0] && i*prime[j] <= n ;j++){
            flag[i * prime[j]] = 1;
            if( i % prime[j] == 0){
                phi[i*prime[j]] =phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]] = phi[i]*phi[prime[j]];
        }
    }
}

int main(){
    scanf("%d",&n);
    if( n == 1) {
        printf("%d\n",0);
        return 0;
    }
    eulr(n-1);
    int i ;
    For(i,1,n-1){
        sum += phi[i];
    }
    int ans = sum*2+1;
    printf("%d\n",ans);
    return 0;
}

