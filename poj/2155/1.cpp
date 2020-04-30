/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 02 Apr 2020 04:07:29 PM CST
* problem: poj-2155
*----------------*/
#include <cstdio>
#include <cstring>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e3+5;
const int maxe = 1e6+5;
int n,m;
int c[maxn][maxn];
/* ======= 全局变量 END =======*/

// == 二维树状数组
inline int lowbit(int x){return x &-x;}
void update(int x,int y,int val){
    int i,j;
    for(i=x;i<=n;i+=lowbit(i)){
        for( j = y;j<=n;j+=lowbit(j)){
            c[i][j] += val;
        }
    }
}

int query(int x,int y){
    int s = 0;
    int i,j;
    for( i = x ;i>0;i-=lowbit(i) )
        for(j= y ;j >0;j-=lowbit(j))
            s += c[i][j];
    return s;
}

// == 二维树状数组 END

void init(){
    memset(c,0,sizeof(c));
    scanf("%d%d",&n,&m);
    char str[10];
    char &s = str[0];
    int i;
    int x,y,xx,yy;
    For(i,1,m){
        scanf("%s",str);
        if( s == 'C'){
            scanf("%d%d%d%d",&x,&y,&xx,&yy);
            update(x, y, 1);
            update(xx+1, y, 1);
            update(x, yy+1, 1);
            update(xx+1, yy+1, 1);
        }
        else{
            scanf("%d%d",&x,&y);
            int ret = query(x, y);
            printf("%d\n",ret%2);
        }

    }
}


int main(){
    //===================
    int t;
    scanf("%d",&t);
    while (t--) {
        init();
        printf("\n");
    }
    

    //=================== 
    return 0;
}
