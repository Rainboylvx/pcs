/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 10 Feb 2020 10:05:32 AM CST
* problem: luogu-1120
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 100;
int n,m;
vector<int>   v;
int cnt;
int sum;
int _max = -1;
bool vis[maxn];
int cnt_stick; //木棍的根数
int _next[maxn];

void init(){
    scanf("%d",&n);
    int i,j;
    For(i,1,n){
        scanf("%d",&j);
        if (j <= 50) {
            v.push_back(j);
            sum += j;
            _max = max(_max,j);
        }
    }
    n = v.size();
}
/* ======= 全局变量 END =======*/
int at[maxn];
int stat = 44;
int max_dep = -1;
bool dfs(int dep,int pre,int left){

    //边界
    if(dep == n+1){
        if( left == stat) return 1;
        return 0;
    }
    if(n-dep+1 < cnt_stick) return 0;
    if( pre == n) 
        return 0;

    int i,max_idx,max_val = -1;
    if( pre == -1){ //一个新的组合
        cnt_stick --;
        // 找到最大得值
        for( i = 0;i<n;i++)
            if( !vis[i]) break;
        max_idx = i;
        max_val = v[i];
        vis[i] = 1;
        at[dep] = v[i];

        int nxt = i;
        if( stat -v[i] == 0)
            nxt = -1;
        if( dfs(dep+1,nxt,stat - v[i]) )
            return 1;
        cnt_stick++;
        vis[i] = 0;
        return 0; // 3.
    }
    
    for( i =pre+1;i<n;i++){
        if( vis[i] || v[i] > left) continue;
        vis[i] = 1;
        at[dep] = v[i];
        #ifdef DEBUG
            if( left-v[i] == 0 && max_dep < dep)
            //if(1)
            {
                int j;
                printf("%4d: ",dep);
                For(j,1,dep){
                    printf("%d ",at[j]);
                }
                printf("\n");
                max_dep = dep;
            }
        #endif
        int next_left = left - v[i];
        int nxt = i;
        if( !next_left) {
            nxt = -1;
            next_left = stat;
        }
        if( dfs(dep+1,nxt,next_left))
            return 1;
        vis[i]  = 0;
        if( next_left == stat) return 0;
        int j = _next[i];
        if( j== -1) return 0;
        i = j-1;
    }
    return 0;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    sort(v.begin(), v.end(), greater<int> ());
    int i;
    _next[v.size()-1] = -1;
    for( i = v.size()-1;i>0;i--){
        if( v[i-1] == v[i])
            _next[i-1] = _next[i];
        else
            _next[i-1] = i;
    }
    for(i = _max ; i <= sum /2 ;i++){
        if( sum % i != 0 ) continue;
        //printf("->%d\n",i);
        cnt_stick = sum / i;
        //memset(vis,0,sizeof(vis));
        stat = i;
        int ret = dfs(1,-1,stat);
        if( ret ){
            printf("%d\n",i);
            break;
        }
    }
    if( i > sum/2)
        printf("%d\n",sum);
    //For(i,1,n){
        //printf("%d ",at[i]);
    //}
    //=================== 
    #ifdef DEBUG
        printf("\n Total Time: %lf ms\n",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    #endif
    return 0;
}
