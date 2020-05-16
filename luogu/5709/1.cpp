/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 11日 星期一 17:52:32 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int m,t,s;

int main(){
    scanf("%d%d%d",&m,&t,&s);
    int cnt =  s / t;
    if( s % t ) cnt ++;
    if( cnt <= m)
        printf("%d\n",m-cnt);
    else
        printf("%d\n",0);
    return 0;
}
