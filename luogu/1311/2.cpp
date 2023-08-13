/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 26日 星期三 17:01:24 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,k,p;
/* 定义全局变量 */
int f[maxn];
int a[maxn]; //颜色
int b[maxn]; // 消费
int color[55][200005];

void init()
{
    std::cin >> n >> k >> p;
    for(int i=1;i<=n;++i){
        std::cin >> a[i] >> b[i];
        int &cnt = color[a[i]][0];
        cnt++;
        color[a[i]][cnt] = i;
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    // 求f群组
    if( b[n] <= p)
        f[n] = n;
    else
        f[n] = n+1;

    for(int i =n-1;i>=1;i--) {
        if( b[i] <= p)
            f[i] = i;
        else
            f[i] = f[i+1];
    }
    for(int i=1;i<=n;++i){
        cout << f[i] << " ";
    }
    return 0;
}
