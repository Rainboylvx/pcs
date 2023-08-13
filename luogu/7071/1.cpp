/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 31日 星期一 13:45:42 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

void init()
{
    cin >> n >> m;
}

int a[maxn];
int idx;

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    std::cin >> n;

    if( n & 1)
    {
        std::cout << -1 << std::endl;
    }
    else {

        //进行拆分
        n >>=1; //去除最后一个1
        for(int i = 1 ; n ;i++){
            if( n & 1) {
                a[++idx] = 1 << i;
            }
            n >>=1;
        }
        for(int i = idx ;i>=1;i--)
            std::cout << a[i] << " " ;
    }
    return 0;
}
