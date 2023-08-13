/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 05月 16日 星期日 16:03:47 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

int cn[maxn];
int cn_cnt;

struct node {
    int x,t;
};

queue<node> q;


void init(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        int T,k,t;
        scanf("%d%d",&T,&k);
        
        while ( !q.empty() ) {
            if( T - q.front().t >= 86400){
                cn[q.front().x]--;
                if(cn[q.front().x] ==  0) cn_cnt--;
                q.pop();
            }
            else break;
        }

        for(int j=1;j<=k;++j){
            scanf("%d",&t);
            q.push({t,T});
            if( cn[t] == 0) cn_cnt++;
            cn[t]++;
        }
        /*
         *if( i == 3){
         *    printf("\n");
         *    printf("\n");
         *    for(int i=1;i<=5;++i){
         *        printf("%d ",cn[i]);
         *    }
         *    printf("\n");
         *    printf("\n");
         *}
         */
        printf("%d\n",cn_cnt);
    }
}

int main(){
    init();
    return 0;
}

