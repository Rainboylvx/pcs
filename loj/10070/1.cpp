/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 29 Feb 2020 07:54:52 PM CST
* problem: loj-10070
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int n,m;
const int maxn = 1e5+5;
int cnt;
struct _ee {
    int l,r,v;
    int w;
};
#define mod 31011

_ee ee[maxn];


struct e {
    int u,v,w;
    bool operator<(const e &b){
        return w < b.w;
    }
};

vector<e> ve;
void init(){
    scanf("%d%d",&n,&m);
    int i;
    int u,v,w;
    For(i,1,m){
        scanf("%d%d%d",&u,&v,&w);
        ve.push_back({u,v,w});
    }
    sort(ve.begin(),ve.end());
}
/* ======= 全局变量 END =======*/

/* ================= 并查集 =================*/
namespace BCJ {
    int fa[maxn];
    inline void bcj_init(int x){ //并查集 初始化
        int i;
        for(i=1;i<=x;i++) fa[i] = i;
    }
    int find(int x){ //查找 and 压缩
        if( x == fa[x]) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    int find_no_mer(int x){//查找 不压缩
        if( x == fa[x]) return x;
        return find_no_mer(fa[x]);
    }
    
    void merge(int x,int y){ //合并
        int fx = find(x);
        int fy = find(y);
        fa[fx] = fy;
    }
}
/* ================= 并查集 end =================*/


//============== kruskal算法
int kruskal(){
    int ans = 0;
    int i,j;
    int k=0 ;
    BCJ::bcj_init(n);
    for(i=0;i<m;i++){
        if( i == 0 ){
            ee[++cnt].l = i;
            ee[cnt].w = ve[i].w;
        }
        else if(ve[i].w != ve[i-1].w){
            ee[++cnt].l = i;
            ee[cnt].w = ve[i].w;
            ee[cnt-1].r = i-1;
        }

        int f1 = BCJ::find(ve[i].u);
        int f2 = BCJ::find(ve[i].v);
        if( f1 != f2){
            ee[cnt].v++;
            ans += ve[i].w;
            BCJ::fa[f1] = f2;
            k++;
            //if( k == n-1) break; //选n-1条边
        }
    }
    ee[cnt].r = m-1;
    if( k < n-1)
        return -1; //返回不可能
    else 
        return ans;
}
//============== kruskal算法 END
//

int sum ;

void dfs(int x,int now,int k){
    if( now == ee[x].r+1){
        if( k == ee[x].v) sum++;
        return;
    }
    int f1 = BCJ::find_no_mer(ve[now].u);
    int f2 = BCJ::find_no_mer(ve[now].v);
    if( f1 != f2){
        BCJ::fa[f1] = f2;
        dfs(x,now+1,k+1);
        BCJ::fa[f1] = f1;
        BCJ::fa[f2] = f2;
    }
    dfs(x,now+1,k);
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int kt = kruskal();
    if( kt == -1){
        printf("%d\n",0);
        return 0;
    }
    //printf("%d\n",kt);
    int i;
    BCJ::bcj_init(n);
    int ans = 1;
    For(i,1,cnt){
        //printf("%d %d %d\n",ee[i].l,ee[i].r,ee[i].v);
        sum = 0;
        //if(ee[i].v == 0 ) continue;
        dfs(i,ee[i].l,0);
        ans = (ans *sum ) % mod;
        int j;
        for(j=ee[i].l ; j<=ee[i].r;j++){ //dfs后,可能会分开
            int f1 = BCJ::find_no_mer(ve[j].u);
            int f2 = BCJ::find_no_mer(ve[j].v);
            if( f1 != f2)
                BCJ::fa[f1] = f2;
        }
    }
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
