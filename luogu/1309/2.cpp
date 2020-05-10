/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 23日 星期一 08:00:53 CST
* problem: luogu-1309
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 2e5+5;
int n,q,r;
struct  _p  { int soc,w,id; //分数,实例,编号
    bool operator<(const _p &b){
        if( soc != b.soc )  return soc > b.soc;
        return id < b.id;
    }
} p[maxn];

_p win[maxn],lose[maxn];

bool cmp(const _p &a ,const _p &b){
    if( a.soc != b.soc )  return a.soc > b.soc;
    return a.id < b.id;
}

void init(){
    scanf("%d%d%d",&n,&r,&q);
    int i,end = n<<1;
    For(i,1,end){
        scanf("%d",&p[i].soc);
        p[i].id = i;
    }
    For(i,1,end){
        scanf("%d",&p[i].w);
    }
    sort(p+1,p+end+1,cmp);
}
/* ======= 全局变量 END =======*/

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    int w,l;
    For(i,1,r){
        w = l =0;
        For(j,1,n){
            int s=(((j-1)<<1)|1);
            int t = s+1;
            if( p[s].w > p[t].w){
                p[s].soc++;
                win[++w] = p[s];
                lose[++l] = p[t];
            }
            else {
                p[t].soc++;
                win[++w] = p[t];
                lose[++l] = p[s];
            }

        }
        j = 0;
        w = l = 1;
        while(w <= n && l <= n){
            if( cmp( win[w],lose[l])){
                p[++j] = win[w++];
            }
            else
                p[++j] = lose[l++];
        }
        while( w <=n ) p[++j] = win[w++];
        while( l <=n ) p[++j] = lose[l++];
        //printf("===================\n");
    }
    printf("%d\n",p[q].id);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
