/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 20:20:28 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;


int main(){
    string s;
    int ans=0;
    while(getline(cin,s) ){
        for( int i =0;i< s.length();i++)
            if( s[i] != ' ' && s[i] != '\n'){
                ans++;
            }
    }
    cout << ans;

    return 0;
}

// linux \n
// windows \r\n
//
// unix => linux
// mac 
// windows
