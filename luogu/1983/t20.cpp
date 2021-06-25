/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 05月 11日 星期二 09:57:36 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

vector<vector<int>> v(100);
int isTrain[100];
int Contain[100];

bool check(int num){
    int snum = Contain[ v[num][0] ]; //起始的数字
    for (int i = v[num][0]+1;i <= v[num].back();i++) {
        // 这个数 > i 要停 且不属于 自己
        if( Contain[i] >= snum && std::find(v[num].begin(), v[num].end(), i) == v[num].end()){
            return 0;
        }
        
    }
    return 1;
}

void dfs(int dep,int pre){
    if( dep == n+1){
        for(int i=1;i<=n;++i){
            if( isTrain[i] == 0)
                Contain[i] = 1;
            //printf("%d ",Contain[i]);
        }
        vector<bool> result;
        for(int j=1;j<=m;++j){
            auto ans = check(j);
            //printf("-->%d: %d\n",j,ans);
            result.push_back(ans);
        }
        if( std::all_of(result.begin(), result.end(), [](bool a) { return a;})){
            printf("=======================================>\n");
            for(int i=1;i<=n;++i){
                printf("%d ",Contain[i]);
            }
            printf("\n");
            printf("\n");
            printf("\n");
        }

        return;
    }
    for(int i=pre;i>=1;--i){
        Contain[dep] = i;
        dfs(dep+1,i);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        int cnt;
        scanf("%d",&cnt);
        for(int j=1;j<=cnt;++j){
            int t;
            scanf("%d",&t);
            v[i].push_back(t);
            isTrain[t] = 1;
        }
    }
    dfs(1,m);

    return 0;
}
