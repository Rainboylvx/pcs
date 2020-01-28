#include <cstdio>
int A,B;
const int mod = 9901;
typedef  long long ll;
int p[10001],n[10001];

/* 快速幂 */
ll power( ll p ,ll n){
}

ll sum(ll p,ll n){
}


int main(){
    scanf("%d%d",&A,&B);
    // 分解整数A
    int k = 0;
    int i;
    for(i=2;i*i <=A;){
        if( A % i == 0){
            p[++k] = i;
            n[k] = 0;
            while( A%i == 0){
                n[k]++;
                A/=i;
            }
        }
        //奇偶
        if( i == 2) i++;
        else i+=2;
    }
    //特殊判断,A是质数
    if(A != 1){
        p[++k] = A;
        n[k] = 1;
    }
    ll ans = 1; //约数和
    for(i=1;i<=k;++i){
        
    }

    return 0;
}

