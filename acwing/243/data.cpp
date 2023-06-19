#include <cstdio>
#include <iostream>
#include <cyaroncpp/cyaron.hpp>

using ll = long long;
using namespace std;
using namespace cyaron;

int main(){
    ll n,m;
    n = 100000,
    m = 100000,
    printf("%lld %lld\n",n,m);
    for(int i=1;i<=n;++i){
        printf("%lld ",RND(ll(-167101660),ll(167101660)));
    }
    printf("\n");
    for(int i=1;i<=m;++i){
        int a = RND(0,1);
        int l = RND(1,n);
        int r = RND(l,n);
        if( a == 0) {
            printf("Q %lld %lld\n",l,r);
        }
        else {
            printf("C %lld %lld %lld\n",l,r,RND(-10000,10000));
        }
    }
    return 0;
}
