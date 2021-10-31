/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 10月 31日 星期日 09:26:09 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

int a[100],aidx;
int b[100],bidx;
int main(int argc,char * argv[]){
    for(int i=1;i<=999;i++){

        int n = i;
        aidx = 0;
        int base = 7;
        while ( n !=0) {
            int ret = (n % base);
            n = n / base;
            a[aidx++] = ret;
        }

        n = i;
        bidx = 0;
        base = 9;
        while ( n !=0) {
            int ret = (n % base);
            n = n / base;
            b[bidx++] = ret;
        }
        if( aidx !=3 || bidx !=3) continue;

        bool flag = true;
        for(int j = 0;j<3;j++){
            if( a[j] != b[2-j]){
                flag = false;
                break;
            }
        }
        if( flag ){
            std::cout << i << std::endl;
            for(int j=2;j>=0;j--)
                std::cout << a[j] ;
            std::cout << std::endl;
            for(int j=2;j>=0;j--)
                std::cout << b[j] ;
            std::cout << std::endl;
        }

    }
    return 0;
}
