#include <cstdio>
#include <algorithm>
using namespace std;


int a,b;

bool gcd(int a,int b){
    if( a % b == 0){
        return 1;
    }
    return !gcd(b, a %b );
}

int main(){
    int t;
    //scanf("%d",&t);
    //while(t--){
        scanf("%d%d",&a,&b);
        if( a < b) swap(a,b);
        if( gcd(a,b))
            printf("Stan wins\n");
        else {
            if(a /b > 1)
                printf("Stan wins\n");
            else
                printf("Ollie wins\n");
        }
    //}


    return 0;
}


