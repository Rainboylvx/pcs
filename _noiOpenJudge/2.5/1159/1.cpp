#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct pos{
    int x,y;
};

queue<pos> q;


int n,m;
char maze[400][400];
int sx,sy;
bool vis[400][400];
int fx[4][2] = {0,1,1,0,-1,0,0,-1};

int key[5] = {0};
int key_num[5] = {0};
bool IS_GET_KEY; //在这次探险中是不是得到新的钥匙

void save_key(char a){
    if(a >='a' && a <='e')
        key[a-'a']++;
}
bool is_key(char c){
    return (c >='a' &&c <='e');
}
bool is_gate(char c){
    return (c>='A' &&c <='E');
}

bool is_key_enough(char a){
    return ( key[a-'A'] != 0 && (key[a-'A'] == key_num[a-'A']));
}


void read_maze(){
	memset(key,0,sizeof(key));
	memset(key_num,0,sizeof(key_num));
	memset(vis,0,sizeof(vis));
	int i,j;
	for(i=1;i<=n;i++){
		scanf("%s",maze[i]+1);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			if( maze[i][j] == 'S'){
				sx = i, sy = j;
			}
			else if( is_key(maze[i][j])){
			    char c = maze[i][j];
			    key_num[c-'a']++;
			}
		}
}
bool in_map(int x,int y){
	if( x >=1 && x <=n && y >=1 && y <=m)
		return 1;
	return 0;
}
void debug_maze(){
    int i,j;
    for (i=1;i<=n;i++){
        printf("%s\n",maze[i]+1);
    }
    printf("============================\n");
}
bool dfs(int x,int y){
    char &at = maze[x][y];
    vis[x][y] = 1;
    if( at == 'G') {
        vis[x][y] = 0;
        return 1;
    }
    if( is_key(at)) {
        IS_GET_KEY = true;
        save_key(at);
        at = '.';
    }

    int i;
    for(i=0;i<4;i++){
        int nx = x + fx[i][0];
        int ny = y + fx[i][1];
        if( in_map(nx,ny) && !vis[nx][ny]  && at!='X'){
            if( !is_gate(at)){
                if( dfs(nx,ny))
                    return 1;
            }
            else if( is_key_enough(at) ){
                at = '.';
                if( dfs(nx,ny))
                    return 1;
            }
        }
    }
    vis[x][y] = 0;
	return 0;
}

bool bfs(){
    memset(vis,0,sizeof(vis));
    vis[sx][sy] = 1;
    q.push({sx,sy});

    while( !q.empty()){
        pos h  = q.front();
        q.pop();
        int i;
        for(i=0;i<4;i++){
            int nx = h.x + fx[i][0];
            int ny = h.y + fx[i][1];
            if( in_map(nx, ny) && !vis[nx][ny] && maze[nx][ny] !='X'){
                char &at = maze[nx][ny];
                if( is_key(at)){
                    save_key(at);
                    IS_GET_KEY = 1;
                    at = '.';
                }
                else if( is_gate(at)){
                    if( !is_key_enough(at))
                        continue;
                    else
                        at = '.';
                }
                else if( at == 'G')
                    return 1;
                vis[nx][ny] = 1;
                q.push({nx,ny});
            }
        }
    }
    return 0;
}

bool Explor(){
    while(1){
        IS_GET_KEY = false;
        bool ret = bfs();
        if( ret) return 1;
        if( !IS_GET_KEY )
            return 0;
    }
    return 0;
}
int main(){
	
	while(1){
		int ret = scanf("%d%d",&n,&m);
		if( n== 0 || m == 0 )
			return 0;
		if( ret == EOF)
		    return 0;
		read_maze();
		if( Explor())
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
