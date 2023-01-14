/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 04月 03日 星期日 14:39:27 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

int __sum__; //应该加起的和是,原始长度
int a[100];
int vis[100];

int tot = 0;

bool dfs(int dep,int rest,int pre,int real_pre){ // pre 排除等效冗余
    tot++;
    if( dep == n+1 ){
        return __sum__ == rest;
    }
    for(int i=1;i<=n;++i){
        if( vis[i] == 0 && rest >= a[i]){
            if(pre < a[i]) continue;
            int next_rest = rest- a[i];
            int next_pre = a[i];
            if(  next_rest == 0) {
                next_pre = __sum__+1;
                next_rest = __sum__;
            }
            vis[i] = 1;
            //printf("dep :%d -->%d\n",dep,a[i]);
            bool ret = dfs(dep+1,next_rest,next_pre,a[i]);
            if( ret == true)
                return true;
            //不成功 优化2 
            vis[i] = 0;
            int j;
            for( j = i;  j<=n; ++j){
                if(a[j] != a[i]) break;
            }
            i = j-1;
        }
        //优化3
        if( dep == 1 && i == 1 ) {
            return false;
        }
        //优化4
        if(real_pre == __sum__){
            return false;
        }
    }
    return false;
}



int main(int argc,char * argv[]){
    while ( 1 ) {
        memset(vis,0,sizeof(vis));
        tot = 0;
        std::cin >> n;
        if( n == 0) break;
        int Max = -1,sum = 0;
        for(int i=1;i<=n;++i) {
            std::cin >> a[i];
            if( Max < a[i]) Max = a[i];
            sum += a[i];
        }
        sort(a+1,a+1+n,greater<int>());
        //for(int i=1;i<=n;++i){
            //printf("->%d ",a[i]);
        //}
        bool flag = 0;
        for(int i=Max;i<sum;++i){
            __sum__ = i;
            if( dfs(1,__sum__,Max+1,-1) ){
                std::cout << i << std::endl;
                flag= 1;
                break;
            }
        }
        if( flag == 0)
            std::cout << sum << std::endl;

        //std::cout << "tot : " << tot  << "\n";


    }
    return 0;
}
