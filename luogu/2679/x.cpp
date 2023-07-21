/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 12日 星期三 12:20:25 CST */
#include <bits/stdc++.h>
#include "utils/log.hpp"
using namespace std;
typedef long long ll;

int n,m;
/* 定义全局变量 */

void init()
{
    cin >> n >> m;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(int i=1;i<=23;++i){
        log(i, i %2, (i-1)%2);
    }
    return 0;
}
