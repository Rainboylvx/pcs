/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 02日 星期日 13:31:39 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int a[105];

int main(){
    cin >> n;
    int i,j,k;
    for(i=1;i<=n;++i){
        cin >> a[i];
    }

    int ans=0;
    for( i =1;i<=n;i++){ //挑一个数,看这个数是否是其它数字的和
        bool flag = 0;
        for( j =1;j<=n;j++){  // 第一个数
            if( j == i) continue;
            for( k = j+1;k<=n;k++){ // 第二个数
                if( k == i) continue;
                // a[j] + a[k] =  a[i]
                if( a[j] + a[k] == a[i]){
                    ans++;
                    flag = 1;
                    break;
                }
            }
            if( flag == 1) break;
        }
    }
    cout << ans;



    return 0;
}
