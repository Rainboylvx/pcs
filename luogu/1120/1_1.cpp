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
int _min = 100;
bool vis[maxn];

void init(){
    scanf("%d",&n);
    int i,j;
    For(i,1,n){
        scanf("%d",&j);
        if (j <= 50) {
            v.push_back(j);
            sum += j;
            _min = min(_min,j);
        }
    }
    n = v.size();
}
/* ======= 全局变量 END =======*/
int at[maxn];
int stat = 86;
int max_dep = -1;
bool dfs(int dep,int pre,int left,int tot){
    //边界
    if( dep == n+1){
        if( left == stat) return 1;
        return 0;
    }
    int i;
    for(i=pre+1;i<n;i++){
        if( vis[i] || v[i] > left ) continue;
        int nxt = left - v[i] ==0 ? -1 : i;
        at[dep] = v[i];
        vis[i] = 1;
        #ifdef DEBUG
            if( left-v[i] == 0 && max_dep < dep)
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

        if( nxt == n-1) nxt = 0;
        int nxt_left = left-v[i];
        if(!nxt_left) {
            nxt_left= stat;
            int cnt = n-dep;
            int l1 = sum - (tot + v[i]);
            //if( (n-dep) % (l1 / stat) !=0 ) 
                //return 0;
        }
        if( dfs(dep+1,nxt,nxt_left,tot+v[i]))
            return 1;
        vis[i] = 0;
    }
    return 0;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    sort(v.begin(), v.end(), greater<int> ());
    int i;
    int ret = dfs(1,-1,stat,0);
    printf("%d\n",ret);
    For(i,1,n){
        printf("%d ",at[i]);
    }
    printf("\n");
    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
