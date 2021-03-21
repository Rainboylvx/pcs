/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 07日 星期日 09:52:20 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量
int p[10000];
bool pp[10000];
int cnt = 0; //有多少个质数
bool isp(int a){
    for(int i=2;i< a;i++){
        if( a % i == 0) return 0;
    }
    return 1;
}
int s;
int main(){
    scanf("%d",&s); // n is s
    for(int i=2;i<=s;i++){
        if( isp(i) ){
            cnt++;
            p[cnt] = i;
            pp[i] = 1;
        }
    }
    int ans = -1;
    for(int i = 1;i<=cnt;i++){
        int a = p[i];
        int b = s - a;
        if( pp[b]==1){
            if( ans < a*b)
                ans = a*b;
        }
    }
    printf("%d",ans);

    return 0;
}
