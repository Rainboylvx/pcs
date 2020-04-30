/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Mon 06 Apr 2020 12:01:28 AM CST
* problem:  loj-10008
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;

int a[maxn];

struct node {
    int day,fen;
    bool operator<(const node &b){
        if(fen == b.fen) return day > b.day;
        return fen > b.fen;
    }
};
node b[maxn];
/* ======= 全局变量 END =======*/
void init(){
    scanf("%d",&n);
    int i;
    For(i,1,n){
        scanf("%d%d",&b[i].day,&b[i].fen);
    }
    sort(b+1,b+1+n);
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



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    bcj_init(n);
    int i,j;
    int sum = 0;
    For(i,1,n){
        int day = b[i].day;
        int fen = b[i].fen;
        int root = find(day);
        if( root == 0 ) continue;
        sum +=fen;
        fa[root] = root-1;

        //for( j = b[i].day;j >=0;j--){
            //if( a[j] == 0){
                //a[j] = fen;
                //sum +=fen;
                //break;
            //}
        //}
    }
    printf("%d\n",sum);

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
