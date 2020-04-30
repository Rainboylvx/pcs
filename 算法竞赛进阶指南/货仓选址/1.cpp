/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Wed 01 Apr 2020 12:26:51 AM CST
* problem: acwing-106
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

vector<int>   v;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m;

/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i,t;
    For(i,1,n){
        scanf("%d",&t);
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    int len = v.size();
    int p;
    if( len % 2 == 1){ //奇数
        p = (1+len)/2-1;
    }
    else { //偶数
        p = len /2 - 1;
    }
    int ans = 0;
    for (const auto& e : v) {
        ans += abs( e - v[p]);
    }
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
