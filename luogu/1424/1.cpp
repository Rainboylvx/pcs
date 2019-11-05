#include <cstdio>

int main(){
    
    double pre = 2;
    double sum = 2;
    double x;
    scanf("%lf",&x);

    if( x <= 2.0){
        printf("1");
        return 0;
    }

    int i;
    for(i=2; 1 ;i++){

        sum += pre * 0.98;
        pre = pre *0.98;

        if( sum >= x){
            break;
        }
    }

    printf("%d",i);
    return 0;
}
