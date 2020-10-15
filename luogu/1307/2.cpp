/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 04日 星期二 09:52:38 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
string s;


int main(){
    cin >> s;
    int end = 0;
    if( s[0] == '-'){
        cout << '-';
        end = 1;
    }
    int i;
    bool flag = 0; //0表示 没有非0元素输出
    for( i =s.length()-1;i>=end;i--){
        if( s[i] == '0' && flag == 0 )
            continue;
        else {
            flag = 1;
            cout << s[i];
        }
    }

    return 0;
}
