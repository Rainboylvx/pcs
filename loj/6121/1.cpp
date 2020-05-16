/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 15日 星期五 10:35:43 CST
* problem: loj-6121
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e5+5;
const int maxe = 1e6+5;
int n,m,p,k,key_cnt;

struct node { //图上点点
    int dir[4]; //4个方向是墙，还是其他，-1表示畅通
    int key[11]; //钥匙
};

node _map[20][20];
/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
bool in_map(int x,int y){
    return x >=1 && x <=n && y >=1 && y <=m;
}

int getFx(int x1,int y1,int x2,int y2){
    int i;
    For(i,0,3){
        if( x1 + fx[i][0] == x2 && y1 + fx[i][1] == y2)
            return i;
    }
    return 0;
}

/* ======= 全局变量 END =======*/
void init(){
    int i,j;
    scanf("%d%d%d",&n,&m,&p);
    memset(_map,-1,sizeof(_map));
    For(i,1,n){
        For(j,1,m){
            _map[i][j].key[0] = 0;
        }
    }
    scanf("%d",&k);
    For(i,1,k){
        int x1,y1,x2,y2,g;
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&g);
        int dir = getFx(x1, y1, x2, y2);
        _map[x1][y1].dir[dir] = g;
        dir = getFx(x2, y2, x1, y1);
        _map[x2][y2].dir[dir] = g;
    }
    scanf("%d",&key_cnt);
    For(i,1,key_cnt){
        int x,y,key;
        scanf("%d%d%d",&x,&y,&key);
        int &cnt = _map[x][y].key[0];
        _map[x][y].key[++cnt] = key;
    }
}

struct state {
    int step;
    int x,y;
    int s;
};
bool vis[11][11][2<<10];

//是否有对应的钥匙
bool has_key(int state,int key){
    return state & (1<<(key-1));
}

int bfs(){
    queue<state> q;
    q.push({0,1,1,0});
    vis[1][1][0] = 1;
    while( !q.empty()){
        state h  = q.front(); q.pop();
        if( h.x == n && h.y == m) return h.step;

        int i;
        For(i,0,3){
            int nx = h.x + fx[i][0];
            int ny = h.y + fx[i][1];
            if( !in_map(nx, ny)) continue; //不在地图内
            if( _map[h.x][h.y].dir[i] == 0) continue; // 墙
            if(vis[nx][ny][h.s]) continue; //到达过
            if(_map[h.x][h.y].dir[i] !=-1 &&
                    !has_key(h.s, _map[h.x][h.y].dir[i])
                    ) continue; //没有对应的钥匙
            int new_state = h.s;
            vis[nx][ny][new_state] = 1;
            int i;
            if( _map[nx][ny].key[0] !=0) 
                For(i,1,_map[nx][ny].key[0]){
                    new_state |= (1<<(_map[nx][ny].key[i]-1));
                }
            vis[nx][ny][new_state] = 1;
            q.push({h.step+1,nx,ny,new_state});
        }
    }
    return -1;
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int ans = bfs();
    printf("%d\n",ans);
    

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
