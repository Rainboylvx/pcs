/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 30日 星期三 13:28:54 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int k;

queue<pair<int,int> > q;
#define mp make_pair

bool vis[100000*5];
int bfs(){
    vis[n] = 1;
    q.push(mp(n,0));

    while ( !q.empty() ) {
        pair<int, int> h = q.front(); q.pop();
        if( h.first == k) return h.second;

        //1 -1
        int t = h.first-1;
        if( t >= 0 && vis[t] == 0) {
            q.push(mp(t,h.second+1));
            vis[t] = 1;
        }

        //2 +1
        t = h.first+1;
        if( t <= k && vis[t] ==0 ){
            q.push(mp(t,h.second+1));
            vis[t] = 1;
        }

        //3 *2
        t = h.first*2;
        if(t<=500000 && vis[t] ==0 ){
            q.push(mp(t,h.second+1));
            vis[t] = 1;
        }
    }
    return -1;
}

int main(){
    scanf("%d%d",&n,&k);
    if( n >=k ){
        printf("%d",n-k);
        return 0;
    }
    int ans = bfs();
    printf("%d",ans);
    return 0;
}
