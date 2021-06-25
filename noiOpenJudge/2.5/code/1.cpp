/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 24日 星期四 20:24:57 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int key_count; //钥匙的数量
struct state { //状态
    int x,y,snake,key,step; // 位置，蛇的状态，时间
};

char mg[200][200];
int sx,sy,tx,ty; //起点 终点

bool vis[15][100][200][200]; 
int snake_cnt = 10; //蛇的数量
// vis[snake][x][y] 位于x，y，
// 蛇的状态为snake 时的最小步数
//
/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
bool in_mg(int x,int y){
    return x>=1 && x<=n && y>=1 && y<=n;
}

bool is_snake(int x,int y){ return mg[x][y] > 10 && mg[x][y] <=15; }

//这个位置的蛇是否已经打死
bool is_beated_snake(int x,int y,int snake_state){
    return (1<<(mg[x][y]-10-1)) & snake_state;
}
int kill_snake(int x,int y,int snake_state){
    return (1<<(mg[x][y]-10-1)) | snake_state;
}


void init(){
    snake_cnt = 10;
    for(int i=1;i<=n;++i){
        scanf("%s",mg[i]+1);
        for(int j=1;j<=n;++j){
            if( mg[i][j] == 'K')
                sx = i,sy = j;
            else if ( mg[i][j] == 'T'){
                tx = i ,ty = j;
            }
            else if ( mg[i][j] == 'S') {
                snake_cnt++;
                mg[i][j] = snake_cnt; // 改成这个值
            }
        }
    }
}

int bfs(state S){ //

    queue<state> q;
    q.push(S);
    vis[S.key][S.snake][S.x][S.y] = 1;

    while ( !q.empty() ) {
        state h = q.front(); q.pop();
        if( h.key == key_count && mg[h.x][h.y] == 'T')
            return h.step; //已经救了唐僧

        //这个位置是蛇,且没有被杀死,那必须杀它
        if( is_snake(h.x, h.y) && !is_beated_snake(h.x, h.y, h.snake)){
            int after  = kill_snake(h.x, h.y, h.snake);
            if( vis[h.key][after][h.x][h.y] == 0){
                
                q.push({h.x,h.y,after,h.key,h.step+1 });
                vis[h.key][after][h.x][h.y] = 1;

            }
        }
        else 

            for(int i=0;i<=3;++i){
                int nx = h.x + fx[i][0];
                int ny = h.y + fx[i][1];
                if( in_mg(nx, ny)  && mg[nx][ny] != '#'){
                    char &t = mg[nx][ny];
                    int key = h.key;
                    //是钥匙且可拿
                    if(t >='1' && t <= '9' && t == key+1+'0') key++;
                    if( vis[key][h.snake][nx][ny] == 0){
                        q.push({nx,ny,h.snake,key,h.step+1});
                        vis[key][h.snake][nx][ny] =1 ;
                    }
                }
            }
    }

    return -1;
}

int do_job(){
    state S = {sx,sy,0,0,0};
    memset(vis,0,sizeof(vis));

    return bfs(S);
}


int main(){
    while ( 1 ) {
        scanf("%d%d",&n,&key_count);
        if( n ==  0 && key_count == 0) break;
        init(); //读取数据
        int ans = do_job(); //开始工作，计算答案
        if( ans != -1)
            printf("%d\n",ans);
        else
            printf("impossible\n");

    }
    return 0;
}
