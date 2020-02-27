/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 20 Feb 2020 08:59:54 PM CST
* problem: loj-10000
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
int n,m;
typedef pair<int, int> HT; //活动
vector<HT> ht;


void init(){
    scanf("%d",&n);
    int i;
    For(i,1,n){
        int t1,t2;
        scanf("%d%d",&t1,&t2);
        ht.push_back(make_pair(t2, t1));
    }
    sort(ht.begin(),ht.end());
}
/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int cnt = 1;
    int pre = 0;
    if( n == 0){
        printf("%d\n",0);
        return 0;
    }
    int i;
    for( i = 1;i<n;i++){
         if( ht[i].first > ht[pre].first && ht[i].second >= ht[pre].first){
             cnt++;
             pre = i;
         }
    }
    printf("%d\n",cnt);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
