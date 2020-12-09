/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 09日 星期三 10:52:35 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,h;
int f[maxn],d[maxn],t[maxn];
/* 定义全局变量 */

int get_ans(int end,int left){
    if( left <= 0 ) return 0;
    priority_queue<pair<int,int> > pq;
    for(int i=1;i<=end;++i) pq.push(make_pair(f[i], i));
    int cnt=0;
    for(  ; left != 0 ; left--){
        if( pq.top().first <= 0){
            pq.pop();
            continue;
        }
        int val = pq.top().first;
        int i = pq.top().second;
        cnt += val;
        pq.push(make_pair(val-d[i], i));
        pq.pop();
    }
    return cnt;
}

int main(){
    scanf("%d%d",&n,&h);
    h = h *60 /5;
    for(int i=1;i<=n;++i) scanf("%d",&f[i]);
    for(int i=1;i<=n;++i) scanf("%d",&d[i]);
    for(int i=2;i<=n;++i) scanf("%d",&t[i]);
    int ans = 0;
    int sum = 0;
    for(int i=1;i<=n;++i){
        sum += t[i];
        int left = h - sum;
        ans = max(ans , get_ans(i, left));
    }
    printf("%d",ans);
    return 0;
}
