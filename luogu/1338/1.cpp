#include <cstdio>

#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
const int maxn = 5e5+5;

typedef long long ll;
inline ll g(ll n){ return (n-1)*n/2; }

int n,m;
int a[maxn];
int head=1,last;
int main(){
    scanf("%d%d",&n,&m);
    last = n;
    int i;
    For(i,1,n){
        //能不能放第一位
        if( g(n-i) >=  m){
            a[head++]  = i;
        }
        else{
            a[last--]= i;
            m -= (n-i);
        }
    }
    For(i,1,n){
       printf("%d ",a[i]);
    }
    return 0;
}
