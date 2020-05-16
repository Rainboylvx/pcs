/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 11日 星期一 17:41:02 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
char s[10000];

int main(){
    scanf("%s",s);
    int len = strlen(s);
    for( len--; len >=0 ;len--)
        printf("%c",s[len]);


    return 0;
}
