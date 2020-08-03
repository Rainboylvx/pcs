/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 30日 星期六 21:56:11 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;


int dfs(int pos,int pre,int lead,int eq){
    if( pos == 0) return 1;
    int ed = eq ? num[pos] : 9;
    int ret =0;
    for(int i = 0;i<=ed;i++){
        if( lead )
            ret += dfs(pos-1,i, lead && i==0 , eq && i == ed);
        else if( abs(i-pre) >= 2)
            ret += dfs(pos-1,i, lead && i==0 , eq && i == ed);
    }
    return ret;
}

int main(){

    return 0;
}
