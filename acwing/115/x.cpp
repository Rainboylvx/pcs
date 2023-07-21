/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 01日 星期六 21:28:19 CST */
#include <bits/stdc++.h>
#include "base.hpp"
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
    
    int n,root;
    in >> n >> root;
    std::cout << n << " " << root << '\n' ;
    for(int i=1;i<=n;++i){
        int t;
        in >> t;
        std::cout << t << " " ;
    }
    std::cout << '\n' ;
    for(int i=1;i<=n-1;++i){
        int u,v;
        in >> u;
        in >> v;
        std::cout << u <<" "<< v << std::endl;
    }
    return 0;
}
