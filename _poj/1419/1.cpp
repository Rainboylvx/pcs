/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 10月 24日 星期四 16:21:16 CST
* problem:  poj-1419
*----------------*/

#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e2+5;
int n,m;
int _map[maxn][maxn];
int dp[maxn];
int con_sta[maxn]; // 剩下的点是否和已经选的点连接
vector<int>  ans;
vector<int> max_ans;

int bstb = 0; //下界

void init(){
    memset(dp,0,sizeof(dp));
    memset(_map,0,sizeof(_map));
    scanf("%d%d",&n,&m);
    bstb = 0;
    int i,j,u,v;
    for(i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        _map[u][v] = _map[v][u] = 1;
    }

    //建立补图
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if( i == j) continue;
            _map[i][j] = !_map[i][j];
        }
    }
}
/* ======= 全局变量 END =======*/



void dfs(int u,int sum){
    ans.push_back(u);
    //更新下界
    if( sum > bstb)  {
        max_ans = ans;
        bstb = sum; 
    }
    int able = 0;
    int i,j;

    //只能放到dfs里
    int con_sta_bak[maxn]; // 剩下的点是否和已经选的点连接
    for(i=u+1;i<=n;i++){
        //保留上一层的状态
        con_sta_bak[i] = con_sta[i]; 
        if( con_sta[i]) able++;
    }
    if( able + sum <= bstb) return;
    for(i=u+1;i<=n;i++){
        //
        if( !con_sta_bak[i]) continue;
        //
        if(dp[i] + sum <= bstb) continue;

        for(j=i+1;j<=n;j++){
            //下一层的状态
            con_sta[j] = con_sta_bak[j] & _map[i][j];
        }
        dfs(i,sum+1);
        ans.pop_back();
    }
}

int max_tuan(){
    bstb = dp[n] = 1;
    max_ans.clear();
    max_ans.push_back(n);
    int i,j;
    for(i=n-1;i>=1;i--){ 
        for(j=i+1;j<=n;j++){
            con_sta[j] = _map[i][j];
        }
        ans.clear();
        dfs(i,1);
        dp[i] = bstb;
    }
    return bstb;
}


int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        init();
        int ans = max_tuan();
        printf("%d\n",ans);
        vector<int>::iterator it = max_ans.begin();
        printf("%d",*it);
        for(it++ ; it!=max_ans.end();it++){
            printf(" %d",*it);
        }
        printf("\n");
    }

    return 0;
}
