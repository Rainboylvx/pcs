/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 04日 星期二 11:42:29 CST */
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
int idx=0;
int ans[maxn];


int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t;
    std::cin >> t;
    while ( t-- ) {
        int _id,n;
        {
            idx = 0;
            std::cin >> _id >> n;
            std::priority_queue<int>  d_max; // 大根
            std::priority_queue<int,std::vector<int>,std::greater<int>>  d_min; // 小根
            // 先加入 
            int v;
            std::cin >> v;
            d_max.push(v); //加入第一个元素
            ans[++idx] = v;
            for(int i=2;i<=n;++i){
                std::cin >> v;
                if( v > d_max.top())
                    d_min.push(v);
                else
                    d_max.push(v);

                //平衡两个堆
                if( d_max.size() < d_min.size())
                {
                    d_max.push(d_min.top());
                    d_min.pop();
                }

                if( d_max.size() != d_min.size() + (i & 1))
                {
                    d_min.push(d_max.top());
                    d_max.pop();
                }


                if( (i & 1) == 1) { //奇数
                    ans[++idx] = d_max.top();
                }
            }
            std::cout << _id <<" "<< idx << std::endl;
            for(int i=1;i<=idx;++i){
                std::cout << ans[i] << " ";
                if( i % 10 == 0)
                    std::cout << "\n";
            }
            if( idx %10 !=0) //注意这里有个小坑
                std::cout << "\n";
        }
    }
    
    return 0;
}
