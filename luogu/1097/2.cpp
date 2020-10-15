/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 04日 星期二 10:56:44 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int a[200005];


int main(){
    cin >> n;
    int i,j;
    for(i=1;i<=n;++i){
        cin >> a[i];
    }
    //[1,n+1) [1,n]
    sort(a+1,a+n+1);
    int cnt = 1;
    for(i=2;i<=n;i++){
        if(a[i] == a[i-1] ) cnt++;
        else {
            cout << a[i-1] << " " << cnt << endl;
            cnt=1;
        }
    }
    cout << a[n] << " " << cnt << endl;


    return 0;
}
