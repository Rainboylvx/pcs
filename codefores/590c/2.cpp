#include<bits/stdc++.h>
using namespace std;
#define Fopen freopen("_in.txt","r",stdin); freopen("_out.txt","w",stdout);
#define LL long long
#define ULL unsigned LL
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define lch(x) tr[x].son[0]
#define rch(x) tr[x].son[1]
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef pair<int,int> pll;
const int inf = 0x3f3f3f3f;
const int _inf = 0xc0c0c0c0;
const LL INF = 0x3f3f3f3f3f3f3f3f;
const LL _INF = 0xc0c0c0c0c0c0c0c0;
const LL mod =  (int)1e9+7;
const int N = 1e3 + 100;
int n, m;
LL dis[N][N][3];
char s[N][N];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
deque<pll> q;
void bfs(int k){
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            dis[i][j][k] = inf;
    char kk = k + '0' + 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(s[i][j] == kk){
                dis[i][j][k] = 0;
                q.push_back(pll(i,j));
            }
        }
    }
    while(!q.empty()){
        pll t = q.front();
        q.pop_front();
        for(int _ = 0; _ < 4; ++_){
            int nx = t.fi + dx[_];
            int ny = t.se + dy[_];
            if(nx < 1 || nx > n || ny < 1 || ny > m || s[nx][ny] == '#') continue;
            int dd = dis[t.fi][t.se][k] + (s[nx][ny] == '.');
            if(dd < dis[nx][ny][k]){
                dis[nx][ny][k] = dd;
                if(s[nx][ny] == '.') q.push_back(pll(nx,ny));
                else q.push_front(pll(nx, ny));
            }
        }
    }
}
int main(){

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%s", s[i]+1);
    for(int i = 0; i < 3; ++i) bfs(i);
    LL ans = inf;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            int f = 0;
            if(s[i][j] == '.') f = 2;
            ans = min(ans, dis[i][j][0] + dis[i][j][1] + dis[i][j][2] - f);        }
    }
    if(ans == inf) ans = -1;
    cout << ans << endl;
    return 0;
}
