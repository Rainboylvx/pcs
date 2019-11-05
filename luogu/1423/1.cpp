#include <cstdio>

int main(){
    double x;
    scanf("%lf",&x);
    if( x == 0 ){
        printf("%d\n",0);
        return 0;
    }
    int i;
    double sum = 0;
    double pre = 2;
    for(i=1; 1 ;i++)
    {
        sum += pre;
        if( sum >= x){
            printf("%d",i);
            return 0;
        }
        pre = pre*0.98;
    }
    return 0;
}

