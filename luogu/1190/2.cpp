/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 04日 星期二 11:35:35 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int s[105];
int a[10005],cnt=1;


int main(){
    cin >> n >> m;
    int i,j;
    for(i=1;i<=n;++i){
        cin >> a[i];
    }
    for( i =1; ; i++){
        for(j=1;j<=m;j++){
            if( s[j] == 0){
                if( cnt <= n) //cnt指向下一个要取的人
                    s[j] = a[cnt++]-1;
            }
            else s[j]--;
        }
        if( cnt > n){
            int sum = 0;
            for(j=1;j<=m;++j) sum += s[j];
            if( sum == 0){
                cout << i;
                return 0;
            }
        }
    }

    return 0;
}
