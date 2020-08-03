/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 24日 星期日 09:38:11 CST */
#include <bits/stdc++.h>
using namespace std;

char str[100];
int a[100];
int main(){
    scanf("%s",str+1);
    for(int i = 1;i<=12;i++){
        if( str[i] == '-') continue;
        a[ ++a[0] ] = str[i]-'0';
    }
    if( str[13] == 'X') a[++a[0]] = 10;
    else a[++a[0]] = str[13] -'0';

    int sum = 0;
    for(int i=1;i<=9;i++) sum = sum + i*a[i];

    if( sum % 11 == a[10] ) {
        printf("Right");
        return 0;
    }

    for(int i=1;i<=12;i++) printf("%c",str[i]);

    if( sum %11 == 10) printf("X");
    else printf("%c",'0'+(sum%11));

    return 0;
}
