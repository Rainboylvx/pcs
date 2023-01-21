/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 03日 星期一 21:56:34 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e9;
int n,m;
bool flag[maxn+5];

int main(){
    int i,j;
    int cnt=0;
    for(i=2;i<=maxn;i++){
        if( flag[i] == 0) {
            //printf("%d\n",i);
            cnt++; 
            if( i > maxn/i) continue;
            for(j=i*i;j<=maxn;j+=i)
                flag[j] =1;
        }
    }
    printf("%d\n",cnt);

    return 0;
}
