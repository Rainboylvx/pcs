/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 09日 星期日 17:39:29 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

//小根堆
priority_queue<int,vector<int>,greater<int> > q;


int main(){
    scanf("%d",&n);
    int i,j,t;
    int ans=0; //赚的钱
    scanf("%d",&t);
    q.push(t); // 先存入第一个股票
    for(i=2;i<=n;++i){
        scanf("%d",&t);
        if( t >  q.top()) {
            ans += t - q.top();
            q.pop();
        }
        q.push(t);
    }
    printf("%d\n",ans);
    return 0;
}
