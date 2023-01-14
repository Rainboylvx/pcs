/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 02月 03日 星期四 19:25:50 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int a,b;
vector<int> v; // STL 视频 里
/* 定义全局变量 */


bool vis[300];

struct node {
    int x,s;
};

int bfs(int s){
    queue<node> q;
    q.push({s,0});
    vis[s] = 1;

    while ( !q.empty() ) {
        node h = q.front();
        q.pop();
        if( h.x == b) return h.s;

        //上
        int up = h.x + v[h.x];
        if( up <= n && vis[up] == 0){
            q.push({up,h.s+1});
            vis[up] = 1;
        }
        //下
        int down = h.x - v[h.x];
        if( down >= 1 && vis[down] == 0){
            q.push({down,h.s+1});
            vis[down] = 1;
        }

    }
    return -1;
}



int main(int argc,char * argv[]){
    std::cin >> n >> a >> b;
    v.push_back(0);
    for(int i=1;i<=n;++i){
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    std::cout << bfs(a) ;
    return 0;
}
