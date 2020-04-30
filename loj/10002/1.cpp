/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Sun 05 Apr 2020 06:56:11 PM CST
* problem: loj-10002
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
int L,W;
struct node {
    double s,t;
    int A,R;
    node(){};
    node(int a,int r){
        A=a,R=r;
        double w = sqrt(r*r-(W/2.0)*(W/2.0));
        s = a-w;
        t = a+w;
    }
    bool operator<(const node &b){
        if( s == b.s) return t < b.t;
        return s < b.s;
    }
};
vector<node>   v;
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d%d%d",&n,&L,&W);
    v.clear();
    int i,p,r;
    For(i,1,n){
        scanf("%d%d",&p,&r);
        if( r <= W/2) continue;
        v.push_back(node(p,r));
    }
    sort(v.begin(),v.end());
    int cnt = 0;
    double pre = 0;
    double _max= -1;
    node tmp;
    for (const auto& e : v) {
        if( e.s <= pre){
            if( _max < e.t){
                _max = e.t;
                tmp = e;
            }
        }
        else{
            //printf("%lf %lf %d %d\n",tmp.s,tmp.t,tmp.A,tmp.R);
            pre = _max;
            _max = e.t;
            cnt++;
            if( pre >= L){
                printf("%d\n",cnt);
                return;
            }
        }
    }
    if(_max < L)
        printf("-1\n");
    else
        printf("%d\n",cnt+1);
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int t;
    scanf("%d",&t);
    while(t--){
        init();
    }
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
