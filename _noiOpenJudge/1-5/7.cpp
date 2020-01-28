#include <cstdio>

int main(){
    int i;
    int n;
    scanf("%d",&n);
    int a,b,c;
    int e=0,f=0,g=0;
    for (i=1;i<=n;i++){
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        e += a;
        f += b;
        g += c;
    }
    printf("%d %d %d %d",e,f,g,e+f+g);
    return 0;
}

