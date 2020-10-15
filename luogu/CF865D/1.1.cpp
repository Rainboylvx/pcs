/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 09日 星期日 17:39:29 CST */
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll maxn = 1e5+5;
ll n,m;

//小根堆

typedef priority_queue<ll,vector<ll>,greater<ll> > HEAP;
HEAP q1; //无前趋
HEAP q2; //有前趋



int main(){
    scanf("%lld",&n);
    ll i,j,t;
    ll ans=0; //赚的钱
    scanf("%lld",&t);
    q1.push(t); // 先存入第一个股票，待卖
    for(i=2;i<=n;++i){
        scanf("%lld",&t);
        if( !q1.empty() && !q2.empty() ){ //都非空
            if( q1.top() < q2.top()){
                if( t > q1.top()){
                    ans += t-q1.top();
                    q1.pop();
                    q2.push(t);
                }
                else
                    q1.push(t);
            }
            else {
                if( t > q2.top()){
                    ans += t- q2.top();
                    q1.push(q2.top());
                    q2.pop();
                    q2.push(t);
                }
                else
                    q1.push(t);
            }
        }
        else if( !q1.empty() && q2.empty()){
            if( t > q1.top()){
                ans += t-q1.top();
                q1.pop();
                q2.push(t);
            }
            else
                q1.push(t);
        }
        else if( q1.empty() && !q2.empty()){
            if( t > q2.top()){
                ans += t- q2.top();
                q1.push(q2.top());
                q2.pop();
                q2.push(t);
            }
            else q1.push(t);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
