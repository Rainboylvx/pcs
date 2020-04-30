/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 10:33:58 PM CST
* problem: loj-10005
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

priority_queue<int,vector<int>, less<int> > q; //大根
priority_queue<int,vector<int>, greater<int> > qs; //小根

/* ======= 全局变量 END =======*/
void init(){
    while( !q.empty()) q.pop();
    while( !qs.empty()) qs.pop();
    int i,t;
    For(i,1,n){
        scanf("%d",&t);
        q.push(t);
        qs.push(t);
    }
    while(q.size() >= 2) {
        int t1 = q.top(); q.pop();
        int t2 = q.top(); q.pop();
        q.push(t1*t2+1);
    }
    int a = q.top(); q.pop();

    while(qs.size() >= 2) {
        int t1 = qs.top(); qs.pop();
        int t2 = qs.top(); qs.pop();
        qs.push(t1*t2+1);
    }
    int b = qs.top(); qs.pop();
    printf("%d\n",abs(a-b));
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while (1) {
        scanf("%d",&n);
        if( n == 0) break;
        init();
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
