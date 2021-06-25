/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 06月 24日 星期四 20:24:57 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
int key_count; //钥匙的数量
struct state { //状态
    int x,y,snake,step; // 位置，蛇的状态，时间
};

char mg[200][200];
int sx,sy,tx,ty; //起点 终点

int vis[100][200][200]; 
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

vector<state> key_state[11]; //存得到每个钥匙时候的状态
void bfs(state S,int aim_key){ // aim_key 目标钥匙
    memset(vis,0x7f,sizeof(vis));
    queue<state> q; //定义一个队列
    q.push(S);
    vis[S.snake][S.x][S.y] = S.step;

    while ( !q.empty() ) {
        state h = q.front(); q.pop();

        //这个位置是蛇且这个没有被杀死,那必须杀死蛇
        if( is_snake(h.x, h.y) && !is_beated_snake(h.x, h.y, h.snake)){
            int after_state = kill_snake(h.x, h.y, h.snake);
            if( h.step+1 < vis[after_state][h.x][h.y] ) { //更好
                q.push({h.x,h.y,after_state,h.step+1});
                vis[after_state][h.x][h.y]  = h.step+1 ;
            }
        }
        else
            for(int i=0;i<=3;++i){
                int nx =h.x +fx[i][0];
                int ny =h.y +fx[i][1];
                if( in_mg(nx, ny) && mg[nx][ny] != '#' ){
                    // 不用判断nx，ny是否是蛇
                    // 1 如果是没有杀死，那要先进去
                    // 2 如果是但已经杀死 相当于一个普通的点
                    // 3 普通的点 直接进
                    if( vis[h.snake][nx][ny] > h.step+1 ){
                        q.push({nx,ny,h.snake,h.step+1});
                        vis[h.snake][nx][ny] = h.step+1;
                    }
                }
            }
    }
    // TODO 应该把 T 改成 all_key+1->char

    // 遍历所有的点
    //printf("aim_key = %d \n",aim_key);
    char aim = aim_key +'0';
    if( aim_key == key_count + 1) aim = 'T'; //这个时候是找 唐僧了
    for(int k=0;k< (1<<(snake_cnt-10));++k){ //蛇的状态
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if( mg[i][j] == aim){
                    //printf("%c\n",mg[i][j]);
                    if(vis[k][i][j] == 0x7f7f7f7f) continue;
                    //printf("vis[%d][%d][%d] = %d\n",k,i,j,vis[k][i][j]);
                    key_state[aim_key].push_back({i,j,k,vis[k][i][j]});
                }
            }
        }
    }
    //printf("\n");
    //printf("\n");
    //printf("\n");
}

int do_job(){
    for(int i=0;i<=9;++i) key_state[i].clear(); //清空
    memset(vis,0x7f,sizeof(vis)); // 把所有的点
    vis[0][sx][sy] = 0;
    
    key_state[0].push_back({sx,sy,0,0}); //起点
    for(int i=1;i<=key_count+1;++i){ // 得到每个钥匙
        for(int j=0;j<key_state[i-1].size();++j){ //遍历每一种状态
            bfs(key_state[i-1][j],i); //传递参数计算
        }
    }

    int ans = 0x7f7f7f7f;
    int size = key_state[key_count+1].size()-1;
    for(int i=0;i<= size ;++i){
        if(ans > key_state[key_count+1][i].step)
            ans = key_state[key_count+1][i].step;
    }
    return ans;
}

int main(){
    while ( 1 ) {
        scanf("%d%d",&n,&key_count);
        if( n ==  0 && key_count == 0) break;
        init(); //读取数据
        int ans = do_job(); //开始工作，计算答案
        if( ans != 0x7f7f7f7f )
            printf("%d\n",ans);
        else
            printf("impossible\n");

    }
    return 0;
}
