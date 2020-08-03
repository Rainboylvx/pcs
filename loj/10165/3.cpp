/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 29日 星期五 14:56:13 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;


int num[100];
bool check(int n){

    num[0] = 0;
    while(n) num[++num[0]] = n%10,n/=10;

    if( num[0] <= 1) return 1;
    for(int i=num[0]-1;i>=1;i--){
        if( abs(num[i]-num[i+1]) < 2) return 0;
    }
    return 1;
}

int main(){
    scanf("%d",&n);
    //scanf("%d",&m);
    int cnt=0;
    int i;
    for(i=0;i<=n;i++)
        if(check(i))
            printf("%d:  %d\n",++cnt,i);

    return 0;
}
