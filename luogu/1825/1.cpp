/* author: Rainboy email: rainboylvx@qq.com  time: 2022年 02月 13日 星期日 19:37:03 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e3+5,maxe = 1e3+5; //点与边的数量

/* 顺时针-4个方向 */
int fx[][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int n,m;
/* 定义全局变量 */

bool in_mg(int x,int y){
    return x >= 1 && x <=n && y >=0  && y<m;
}

struct node {
    int x,y,s;
};
bool vis[maxn][maxn];

string mg[maxn];
int sx,sy,tx,ty;

vector<node> v[30]; //存这样的一对装置


void init(){
    std::cin >> n >> m;
    for(int i=1;i<=n;++i){
        std::cin >> mg[i]; //读取了一行字符串
        for(int j=0;j<=m-1;++j){
            if( mg[i][j] == '='){
                tx = i;
                ty = j;
            }
            else if(mg[i][j] == '@'){
                sx = i;
                sy = j;
            }
            //else if(mg[i][j] >= 'A' || mg[i][j] <= 'Z'){
            else if(std::isupper(mg[i][j])){
                v[mg[i][j] - 'A'].push_back({i,j,0}); // 装存置
            }
        }
    }
}

int bfs(){
    queue<node> q;
    q.push({sx,sy,0});
    vis[sx][sy] = 1;

    while ( !q.empty() ) {
        node h = q.front();
        //std::cout << h.x <<" "<< h.y <<" "<< h.s << std::endl;
        q.pop();
        if( h.x == tx && h.y == ty ) return h.s;

        for(int i=0;i<=3;++i){
            int nx = h.x + fx[i][0];
            int ny = h.y + fx[i][1];
            if( in_mg(nx, ny) && mg[nx][ny] != '#' && vis[nx][ny] == 0){

                if( isupper(mg[nx][ny])){ //是传送门
                    int t = mg[nx][ny] - 'A';
                    vis[nx][ny] = 1;
                    for(int k = 0 ;k < v[t].size() ; ++k){
                        if( v[t][k].x != nx ||  v[t][k].y != ny  ){
                            nx = v[t][k].x;
                            ny = v[t][k].y;
                            break;
                        }
                    }
                    //if( vis[nx][ny] == 0){
                    q.push({nx,ny,h.s+1});
                        //vis[nx][ny] = 1;
                    //}
                }
                else { //no portable 
                    q.push({nx,ny,h.s+1});
                    vis[nx][ny] = 1;
                }
            }
        }
    }
    return -1;
}

int main(int argc,char * argv[]){
    init();
    int ans = bfs();
    std::cout << ans << std::endl;
    return 0;
}
