/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 20:03:33 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

string s;
int main(){
    int ans=0;
    // 1. cin >> 读字符串的时间,yudao 空白字符的时候就会停止 \t \n  " "
    // 2. cin 从文件里的读的时候 到达文件的末尾,就会返回 0
    while (cin >> s) {
        ans += s.length();
    }
    printf("%d\n",ans);
    return 0;
}
