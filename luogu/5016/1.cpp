/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 31日 星期五 20:47:13 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
typedef long long ll;
ll n;
ll a[maxn];
ll m,p,s1,s2;

ll Long,Hu;


int main(){
    cin >> n;
    int i,j;
    for(i=1;i<=n;++i){
        cin >> a[i];
    }
    cin >> m >> p >> s1 >> s2;
    a[p] += s1;
    for(i=1;i<=n;++i){
        if( i < m ){
            Long += (m-i)*a[i];
        }
        else if( i > m) {
            Hu += (i-m)*a[i];
        }
    }
    //cout << Long << " " << Hu << endl;
    ll _min = 0x7f7f7f7f7f7f7f7f;
    ll idx,tl,th;
    for( i=1; i<= n;i++){
        if( i <=m ){
            tl = Long + (m-i)*s2;
            th = Hu;
        }
        else  {
            tl = Long;
            th = Hu + (i-m)*s2;
        }
        if( abs(tl-th) < _min ){
            _min = abs(tl-th);
            idx = i;
        }
    }
    cout << idx;

    return 0;
}
