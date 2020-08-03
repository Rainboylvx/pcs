/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 06月 16日 星期二 09:43:19 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;


int main(){
    scanf("%d",&n);
    int cnt =0;
    int sum =0;
    int i,j,k;
    for(i=1;1;++i){
        for(j=1;j<=i;++j){
            sum += i;
            cnt++;
            if( cnt >= n ) {
                printf("%d\n",sum);
                return 0;
            }
        }
    }
    return 0;
}
