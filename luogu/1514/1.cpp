#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 505;

struct node {
    int l,r; //这个点能达到的区间
    int h; //高度

    void update(const node & o) {
        l = min(l,o.l);
        r = max(r,o.r);
    }
    bool operator<=(const node & o) {
        return h <= o.h;
    }
};

node _map[maxn][maxn];
bool vis[maxn][maxn];

int n,m;
bool in_map(int x,int y) {
    return x>=1 && x <= n && y >=1 &&  y <=m;
}

void init() {
    std::cin >> n >> m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin >> _map[i][j].h;
            _map[i][j].l = 1000;
            _map[i][j].r = 1;
        }
    }
}

int fx4[][2] = {1,0,0,1,-1,0,0,-1}; 

void dfs(int x,int y) {
    vis[x][y] = 1;
    if( x == n ) { //最后一行
        _map[x][y].l =y;
        _map[x][y].r =y;
    }
    for(int i=0;i<=3;++i){
        int nx = x + fx4[i][0];
        int ny = y + fx4[i][1];
        if(!in_map(nx, ny)) continue;
        if( _map[x][y] <= _map[nx][ny]) continue;
        if( vis[nx][ny] == 1) {
            _map[x][y].update( _map[nx][ny] );
        }
        else  {
            dfs(nx,ny);
            _map[x][y].update( _map[nx][ny] );
        }
    }
}

//检查 最小的数量
int check() {
    // for(int i = 1;i <= m ;i ++) {
    //     std::cout << _map[1][i].l <<  " ";
    //     std::cout << _map[1][i].r << std::endl;
    // }
    // std::cout << "---" << "\n";
    //排序
    sort(&_map[1][1],&_map[1][1]+m, [](node &a,node& b){ 
            if( a.l == b.l)
                return a.r < b.r;
            return a.l < b.l;
        });

    // for(int i = 1;i <= m ;i ++) {
    //     std::cout << _map[1][i].l <<  " ";
    //     std::cout << _map[1][i].r << std::endl;
    // }

    int l = 1, r = m;
    int cnt = 0;
    int choose = 1;
    int start = 1;
    while ( l <= m) {
        for(int i = start;i <= m ;i ++) {
            int ml =_map[1][i].l;
            int mr =_map[1][i].r;
            if( l>=ml && l <=mr) { //在范围内
                int cl = _map[1][choose].l;
                int cr = _map[1][choose].r;
                if( cr < mr) {
                    choose = i;
                    // start = i;
                }
            }
        }
        l = _map[1][choose].r+1;
        cnt++;
    }
    return cnt;
}

int main(){
    init();
    for(int i=1;i<=m;++i){
        if(!vis[1][i]) {
            dfs(1,i);
        }
    }
    int cnt = 0 ; //不可以建立的数量
    for(int i=1;i<=m;++i){
        if( !vis[n][i]) {
            cnt++;
        }
    }
    
    if( cnt != 0 ) {
        std::cout << 0 << std::endl;
        std::cout << cnt << std::endl;
        return 0;
    }
    else {
        std::cout << 1 << std::endl;
        std::cout << check() << std::endl;
    }
    return 0;
}
