/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 07月 20日 星期一 09:02:28 CST
* problem: luogu-6582
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef int INT;
//typedef long long int;
#define int long long

using namespace std;
template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch < '0' || ch > '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m,k;
const int mod = 998244353;

char s[1005][1005];
char cnt[1005][1005];
/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
/* ======= 全局变量 END =======*/
void init(){
    scanf("%lld%lld%lld",&n,&m,&k);
    int i,j;
    For(i,1,n){
        scanf("%s",&s[i][1]);
    }
}

bool in_map(int x,int y){ 
    return x >=1 && x <=n && y >=1 && y <=m;
}

int isO(int dir,int x,int y){
    int nx = x + fx[dir][0];
    int ny = y + fx[dir][1];
    if( !in_map(nx, ny)) return 0;
    return s[nx][ny] == 'O';
}

int check(int x,int y){
    int ret = 0;
    ret += isO(0,x,y);
    ret += isO(1,x,y);
    ret += isO(2,x,y);
    ret += isO(3,x,y);
    return ret;
}

vector<int> v;
bool vis[1005][1005];
int c = 0;
int cnt_num[5];
void dfs(int x,int y){
    c++;
    vis[x][y] = 1;
    int num = check(x,y);
    cnt_num[ num <3 ? num : 3 ]++;
    int i,j;
    For(i,0,3){
        int nx = x + fx[i][0];
        int ny = y + fx[i][1];
        if( in_map(nx, ny) && !vis[nx][ny] && s[nx][ny] == 'O')
            dfs(nx,ny);
    }
}
bool get_v(){
    int i,j;
    For(i,1,n){
        For(j,1,m){
            if( s[i][j] == 'O' && !vis[i][j]){
                c= 0;
                memset(cnt_num,0,sizeof(cnt_num));
                dfs(i,j);
                v.push_back(c);
                if( cnt_num[3] != 0 ) return 1;
                if( cnt_num[1] != 2 && c > 1) return 1;
                if( cnt_num[1] == 1 && c != 1) return 1;
            }
        }
    }
    return 0;
}

int quick_mi(int a,int x){
    int base = a % mod;
    int ret = 1;
    for( ; x ; x >>= 1){
        if( x & 1){
            ret *= (base %mod);
            ret %= mod;
        }
        base *= base;
        base %= mod;
    }
    return ret;
}

INT main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    if( get_v() ){
        printf("%d\n",0);
        return 0;
    }
    int ans = 1;
    auto compute = [](int a){
        return k*quick_mi(k-1, a-1) % mod;
    };
    for (const auto& e : v) {
        //printf("%lld ",e);
        ans *= compute(e);
        ans %= mod;
    }
    //printf("\n");
    printf("%lld\n",ans);
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
