/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 11月 27日 星期三 16:49:52 CST
* problem: hdu-1541
*----------------*/
#include <bits/stdc++.h>
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 15000+5;
int n,m;
int cnt[maxn];

struct Node {
    int a,b;
    bool operator < (Node &t){
        if( a != t.a) return a < t.a;
        return b < t.b;
    }
};

Node node[maxn];
int c[32005];

void init(){
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++){
        scanf("%d%d",&node[i].a,&node[i].b);
    }
}


/* ======= 全局变量 END =======*/

inline int lowbit(int x){
    return x&(-x);
}

void update(int pos,int num){
    while(pos<=32005){
        c[pos] += num;
        pos +=lowbit(pos);
    }
}

//sum(1,pos)
int query(int pos){
    int sum = 0;
    while(pos >0){
        sum+=c[pos];
        pos -= lowbit(pos);
    }
    return sum;
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    sort(node+1,node+1+n);
    int i;
    for(i=1;i<=n;i++){
        int now = query(node[i].b+1);
        cnt[now]++;
        update(node[i].b+1,1);
    }
    for(i=0;i<n;i++){
        printf("%d\n",cnt[i]);
    }


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
