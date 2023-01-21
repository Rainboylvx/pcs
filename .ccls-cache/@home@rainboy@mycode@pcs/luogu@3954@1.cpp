/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 01日 星期六 09:35:52 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
// 0.2 = 2/10

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int ans = (a/10) * 2 + (b/10)*3 + (c/10)*5;
    cout << ans;

    return 0;
}
