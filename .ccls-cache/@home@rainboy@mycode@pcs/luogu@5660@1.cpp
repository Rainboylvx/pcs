/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 30日 星期四 01:13:13 CST */
#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin >> s;
    int len = s.length();
    int cnt = 0;
    for( int i = 0 ;i < len ;i++){
        if( s[i] == '1')
            cnt++;
    }
    cout << cnt;
    return 0;
}
