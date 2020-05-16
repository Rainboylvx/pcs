/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 22:01:42 CST
* problem:  uva-11270
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 11;
const int maxe = 1e6+5;
int n,m,cur;

typedef long long ll;
ll d[2][(1<<maxn)+5];

inline void update(int a,int b){
    if( b & (1<<m))
        d[cur][b^(1<<m)] += d[1-cur][a];
}

/* ======= 全局变量 END =======*/


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    while (scanf("%d%d",&n,&m) ==2) {
        if( n < m ) swap(n,m);
        memset(d,0,sizeof(d));
        cur = 0;
        d[0][(1<<m)-1] = 1;
        for( int i =0;i<n;i++)
            for(int j =0 ;j<m;j++){
                cur ^= 1;
                memset(d[cur],0,sizeof(d[cur]));
                for(int k =0;k< (1<<m) ;k++){ //枚举上状态
                    update(k,k<<1);
                    if(i && !(k & (1<<(m-1)))) update(k, (k<<1)  ^ (1<<m)^1);
                    if( j && !(k&1)) update(k, (k<<1)^3);

                }
            }
        printf("%lld\n",d[cur][(1<<m)-1]);
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
