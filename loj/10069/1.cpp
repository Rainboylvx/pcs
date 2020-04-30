/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sat 29 Feb 2020 08:44:22 AM CST
* problem: loj-10069
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m,need;

struct e {
    int u,v,w;
    bool operator<(const e &b){
        return w < b.w;
    }
};

vector<e> wh; //白色的边
vector<e> bla; //黑色的边
int wh_cnt ,bla_cnt;

/* ================= 向量星 =================*/
int head[maxn];
int edge_cnt = 0;
void init(){
     scanf("%d%d%d",&n,&m,&need);
     int i;
     int u,v,w,nn;
     For(i,1,m){
         scanf("%d%d%d%d",&u,&v,&w,&nn);
         u++,v++;
         if( nn)
             bla.push_back({u,v,w});
         else
             wh.push_back({u,v,w});
     }
     sort(bla.begin(), bla.end());
     sort(wh.begin(), wh.end());
     wh_cnt = wh.size();
     bla_cnt = bla.size();
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
    
    void merge(int x,int y){ //合并
        int fx = find(x);
        int fy = find(y);
        fa[fx] = fy;
    }
}
/* ================= 并查集 end =================*/

//============== kruskal算法
int kruskal(int val,int &sum){
    sum = 0;
    int i,j;
    int k=0 ;
    BCJ::bcj_init(n);
    int h1 = 0,h2 = 0;
    int choose_wh_cnt = 0;
    while( h1 < wh_cnt || h2 < bla_cnt){
        e te;
        bool choose_wh = 0;
        if( h1 < wh_cnt && h2 < bla_cnt){
            te = wh[h1].w+val <= bla[h2].w ? choose_wh = 1, wh[h1++] : bla[h2++];
        }
        else if( h1 < wh_cnt){
            te  = wh[h1++];
            choose_wh  = 1;
        }
        else 
            te = bla[h2++];

        int f1 = BCJ::find(te.u);
        int f2 = BCJ::find(te.v);
        if( f1 != f2){
            sum += te.w;
            BCJ::fa[f1] = f2;
            k++;
            if( choose_wh ) choose_wh_cnt++;
            if( k == n-1) break; //选n-1条边
        }
    }
    if( k < n-1)
        return -1; //返回不可能
    else 
        return choose_wh_cnt;
}
//============== kruskal算法 END
int kruskal2(int val,int &sum){
    sum = 0;
    int i,j;
    int k=0 ;
    BCJ::bcj_init(n);
    int h1 = 0,h2 = 0;
    int choose_wh_cnt = 0;
    while( h1 < wh_cnt || h2 < bla_cnt){
        e te;
        bool choose_wh = 0;
        if( h1 < wh_cnt && h2 < bla_cnt){
            if( wh[h1].w+val <= bla[h2].w && h1<=need) {
                choose_wh = 1;
                te = wh[h1++];
            }
            else
                te =  bla[h2++];
        }
        else if( h1 < wh_cnt && h1 <= need){
            te  = wh[h1++];
            choose_wh  = 1;
        }
        else 
            te = bla[h2++];

        int f1 = BCJ::find(te.u);
        int f2 = BCJ::find(te.v);
        if( f1 != f2){
            sum += te.w;
            BCJ::fa[f1] = f2;
            k++;
            if( choose_wh ) choose_wh_cnt++;
            if( k == n-1) break; //选n-1条边
        }
    }
    if( k < n-1)
        return -1; //返回不可能
    else 
        return choose_wh_cnt;
}


//查找范围是[l,r), a[r] 永远 >= key
int first_ge(){
    int l,r,m;
    l = -100,r = 100;
    int ans;
    while( l != r  ) //表示l和r没有重合
    {
        m = (l+r) >>1; // 取中间位置
        int cnt = kruskal(m,ans);
        if(cnt >= need) //表示 [m+1,r) 满足条件
            l = m+1;
        else
            r = m;
    }
    //printf("%d\n",l);
    return l;
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int l = first_ge();
    int ans = 0;
    int choowhcnt = kruskal(l-1, ans);
    //printf("%d\n",ans);
    //printf("%d %d\n",l-1,need);
    printf("%d\n",ans+(choowhcnt-need)*(l-1));
    //printf("%d\n",choowhcnt);
    //printf("min_l =%d\n",l);
    //int choo2 = kruskal2(l-1, ans);
    //printf("%d %d\n",choo2,ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
