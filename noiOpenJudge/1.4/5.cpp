//1.4-5
#include <cstdio>

int main(){
    long long x,y;
    scanf("%ld%ld",&x,&y);
    if( x > y)
        printf(">");
    else if ( x == y)
        printf("=");
    else
        printf("<");
    return 0;
}

