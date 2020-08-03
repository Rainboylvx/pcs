/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 26日 星期二 22:46:48 CST
* problem: loj-10151
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;
template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch < '0' || ch > '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}

/* ======= 全局变量 =======*/
const int maxn = 400;
const int maxe = 1e6+5;
int n,m;
int a[maxn];
int f[maxn][maxn];
int p[maxn][maxn];
struct node { int l,r; };

/* ======= 全局变量 END =======*/
void dfs(int i,int j){
    if( p[i][j] == 0) return;
    printf("%d ",p[i][j]);
    dfs(i,p[i][j]);
    dfs(p[i][j]+1,j);
}
void init(){
    scanf("%d",&n);
    int i,t;
    For(i,1,n){
        read(a[i]);
    }
    int j,k,L;
    For(L,2,n){
        for(i=1;i+L-1<=n;++i){
            j = i+L-1;
            for(k=i;k<j;k++){
                if(f[i][j] <  f[i][k]+f[k+1][j]+(a[i]+a[j])*a[k] ){
                    f[i][j] =  f[i][k]+f[k+1][j]+(a[i]+a[j])*a[k] ;
                    p[i][j] = k;
                }
            }
        }
    }
    printf("%d\n",f[1][n]);
    queue<node> q;
	q.push({ 1, n });
	while (!q.empty()) {
		int l = q.front().l, r = q.front().r;
		q.pop();
		if (l == r) continue;
		printf("%d ",p[l][r]);
		q.push({ l, p[l][r] });
		q.push({ p[l][r] + 1, r });
	}
	printf("\n");
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
