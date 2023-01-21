/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 02日 星期日 13:55:23 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int a,b,L;

int gcd(int a,int b){
    if( b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    cin >> a >> b >> L;
    double t1 = a*1.0 / b;
    double t3 = 9999999999;
    int i,j;
    int ansi,ansj;
    for( i =1;i<=L;i++){
        for( j =1;j<=L;j++){
            if( gcd( i,j) != 1) continue;
            double t2 =  i*1.0 / j;
            if( t2 >= t1){
                if( t3 > t2 - t1){
                    t3 = t2- t1;
                    ansi = i,ansj = j;
                }
            }
        }
    }
    cout << ansi<< " " << ansj ;

    return 0;
}
