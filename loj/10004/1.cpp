/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 10:54:05 AM CST
* problem: loj-10004
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
struct node {
    int t,w;
    bool operator<(const node &b){
        return  w> b.w;
    }
};
node a[maxn];
bool vis[maxn];
vector<int> drop;
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&m);
    scanf("%d",&n);
    int i;
    For(i,1,n) scanf("%d",&a[i].t);
    For(i,1,n) scanf("%d",&a[i].w);

    sort(a+1,a+1+n);

    int j;
    For(i,1,n){
        int t = a[i].t;
        int w = a[i].w;
        bool flag = 0;
        for( j = t ;j >=1;j--)
            if( !vis[j]){
                vis[j] = 1;
                flag = 1;
                break;
            }
        if( !flag) drop.push_back(w);
    }
    int ans = m - accumulate(drop.begin(), drop.end(),0);
    printf("%d\n",ans);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
