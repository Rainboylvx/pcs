/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 07月 07日 星期日 10:02:28 GMT
* problem: luogu-1314
*----------------*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 200005

typedef long long ll;

ll n,m,S;
int w[maxn],v[maxn];
int qs[maxn],qe[maxn];
int W;

/* 数据读取 */
void init(){
    scanf("%lld%lld%lld",&n,&m,&S);
    int i,j;
    for (i=1;i<=n;i++){
        scanf("%d%d",&w[i],&v[i]);
    }
    for (i=1;i<=n;i++){
        scanf("%d%d",&qs[i],&qe[i]);
    }
}

int main(){
    init();
    return 0;
}
