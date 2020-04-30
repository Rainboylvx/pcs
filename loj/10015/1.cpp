/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 08 Apr 2020 04:22:51 PM CST
* problem: loj-10015
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;
struct node { int x,y; };
node a[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
}

bool can_connect(node &a,node &b,int len){
    int dis = abs(a.x-b.x) + abs(a.y-b.y);
    return ((dis+1)>> 1) <= len;
    //return dis <= 2*len;
}

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
using namespace BCJ;
/* ================= 并查集 end =================*/

/* 使用: 首先定义EF::check函数 
 * EF::work(int l,int r)            二分
 * EF::work(double l,double r)      二分-double
 * EF::work3(double l,double r)     三分,凸性函数机值问题,例如一元二次方程
 *
 * EF::work 区间[l,r) 内第一个不满足check()的位置
 *  if check(mid) => mid < key 则找到第一个 >=key 的位置 
 *  if check(mid) => mid <=key 则找到第一个 >key  的位置 
 *  核心思想:[l,r)是满足check的区间,不停缩小[l,r)
 * */
namespace EF {
    bool check(int mid);    //函数声明
    int work(int l,int r){
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid)) l = mid+1;
            else r = mid;
        }
        return l;
    }
    /*
     *double work(double l,double r){
     *    double eps = 1e-8;
     *    while(r-l >eps){
     *        double mid = (l+r) /2;
     *        if( check(mid)) l = mid;
     *        else r = mid;
     *    }
     *    return r;
     *}
     */
    /*
     *double work3(double l,double r){
     *    double eps = 1e-8;
     *    while(r-l >= eps){
     *        double m1 = l+(r-l)/3 ,m2 = r-(r-l)/3;
     *        if( check(m1) <check(m2)) l = m1;
     *        else r = m2;
     *    }
     *    return r;
     *}
     */
}
using namespace EF;

// check=> 不能连通,true
bool EF::check(int mid){
    bcj_init(n);
    int i,j;
    for(i=1;i<n;i++){
        for(j=i+1;j<=n;j++){
            if( can_connect(a[i], a[j], mid)){
                merge(i, j);
            }
        }
    }
    int t= find(1);
    For(i,2,n){
        if( find(i) != t) return 1;
    }
    return 0;
}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    //printf("%d\n",check(1));
    //printf("%d\n",check(2));
    int ans =work(0, int(1e9));
    printf("%d\n",ans);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
