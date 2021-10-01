/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 07月 30日 星期五 14:49:47 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */
int a[maxn];
int pre[maxn];

int sum(int l,int r){
    return pre[r] - pre[l-1];
}
int ans = -0x7f7f7f7f;
int func(){
    for(int s1=1;s1<=n-1;++s1){
        for(int t1=s1;t1<=n-1;++t1){
            for(int s2=t1+1;s2<=n;++s2){
                for(int t2=s2;t2<=n;++t2){
                    int t = sum(s1,t1) +sum(s2,t2);
                    ans = max(t,ans);
                }
            }
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while ( T-- ) {
        scanf("%d",&n);
        for(int i=1;i<=n;++i) {
            scanf("%d",&a[i]);
            pre[i] = pre[i-1] + a[i];
        }
        printf("%d\n",func());
    }
    return 0;
}
