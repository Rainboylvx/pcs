#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    int a,b=0;
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&a);
        if( b < a){
            b = a;
        }
    }
    printf("%d\n",b);
    return 0;
}

