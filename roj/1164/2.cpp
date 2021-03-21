/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 21日 星期日 10:29:25 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

void digit(int n,int k){
    if( k == m){
        printf("%d",n%10);
        return;
    }
    digit(n/10, k+1);
}
int main(){
    scanf("%d",&n);
    scanf("%d",&m);
    digit(n, 1);
    return 0;
}
