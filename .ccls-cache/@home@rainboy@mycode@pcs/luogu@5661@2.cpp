/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 30日 星期四 01:46:45 CST */
#include <bits/stdc++.h>
using namespace std;

int a[] = {0,1,3,7,8,10};

int main(){
    // [ ),[1,3)
    int l = lower_bound(a+1,a+5+1,2)-a;
    printf("%d\n",l);

    return 0;
}
