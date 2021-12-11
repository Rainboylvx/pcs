#include <cstdio>
#include <cstring>


int a,b;

int gcd(int a,int b){
    if( b == 0)
        return a;
    return gcd(b, a%b);
}

int main(){
    scanf("%d%d",&a,&b);
    int ans = gcd(a,b);
    printf("%d\n",ans);
    return 0;
}
