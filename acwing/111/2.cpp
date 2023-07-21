/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 02日 星期日 17:49:38 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

using node = std::pair<int,int>;

struct range {
    int l,r;
    int i;
    bool operator<(range& b)
    {
        if( l == b.l)
            return r < b.r;
        return l < b.l;
    }
};
range a[maxn];
int ans;
int pos[maxn];

void init()
{
    std::cin >> n;
    for(int i=1;i<=n;++i){
        std::cin >> a[i].l >> a[i].r;
        a[i].i = i;
    }
}

std::priority_queue<node, std::vector<node>, std::greater<node>> pq; //小根堆


int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    sort(a+1,a+1+n);
    // for(int i=1;i<=n;++i){
    //     std::cout << a[i].l << " " << a[i].r << "\n";
    // }

    ans=1;
    pos[ a[1].i ] = 1;
    int cnt = 1;
    pq.push(std::make_pair(a[1].r,1));

    for(int i=2;i<=n;++i){
        int l = a[i].l;
        int r = a[i].r;

        auto top = pq.top();
        
        if( top.first < l ) {
            pos[a[i].i] = top.second;
            pq.pop();
            pq.push(std::make_pair(r, top.second));
        }
        else {
            cnt++;
            ans++;
            pos[a[i].i] = cnt;
            pq.push(std::make_pair(r,cnt));
        }
    }
    std::cout << ans << "\n";
    for(int i=1;i<=n;++i){
        std::cout << pos[i] << "\n";
    }
    return 0;
}
