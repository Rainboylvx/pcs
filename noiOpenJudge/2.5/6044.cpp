/* 
 * 思路:应该和第三次写的一样,细节的问题,导致超时,要优化
 *
 * 对一个点:[x,y,T], 坐标,和T值
 * 如果队列头的点可以访问的4个点是'#',那T要-1,
 *
 *
 *
 * 最关键的问题是:
 *  1.有的时候一个点已经VIS过了,但是还可以再次被访问
 *      同样的步数但是T更大也就是这个点可以被再次入队
 *  !!!BFS每一次入队的点一定都是第N次能被访问到的点
 * */

/* 
 *
 *  +---+    +---+
 *  | A |--->| B |
 *  +---+    +---+
 *
 * 如果B被VIS过,
 *
 * T =3 时候
 * ###@*
 * ####*
 * +###*
 * */

#include <cstdio>
#include <cstring>


int m,n,T;

char map[400][400];//地图数据

bool vis[400][400];
int ST[400][400];//点剩余的T


/* 队列 */
struct _node {
    int x,y;
    int step;
    int T;
    int pre;
};

_node queue[40000];
int head,tail;


_node s,t;//起点,终点

int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};


int ttt=0;

struct _node2{
    int x,y;
    int pre;
};



bool isRight(int x,int y){
    if( x>0 && x<=m && y>0 && y <=n)
        return true;
    return false;
}


void print(int head){
    int i=head;
    for(;queue[i].pre!=0;i=queue[i].pre)
        printf("{%d,%d}<-",queue[i].x,queue[i].y);
}

void bfs(){
    /* 初始化一些数据 */
    head=tail=0;
    tail++;
    queue[tail]=s;
    queue[tail].step=0;
    queue[tail].T=T;
    queue[tail].pre=0;
    ST[s.x][s.y]=T;

    memset(vis,0,sizeof(vis));
    vis[s.x][s.y] =1;//起点vis过

    while(head != tail){
        /* 取出头部 */
        
        head++;
        int x = queue[head].x;
        int y = queue[head].y;
        int nt = queue[head].T;
        int ns = queue[head].step;

        int i;
        for (i=0;i<=3;i++){
            int nx = x+fx[i][0];
            int ny = y+fx[i][1];

            if(nx == t.x && ny ==t.y){ //终点
                //print(head);
                printf("%d",ns+1);
                return ;
            }


            if(isRight(nx,ny)){ //这个点在map内
                if(vis[nx][ny] == 0){ //这个点没有被vis过
                    if(map[nx][ny] == '#' && nt >0){ //手下,能走
                        //入队
                        tail++;
                        queue[tail].x =nx;
                        queue[tail].y =ny;
                        queue[tail].T =nt-1;
                        queue[tail].step =ns+1;
                        queue[tail].pre =head;

                        //标记
                        ST[nx][ny] = nt-1;
                        vis[nx][ny]=1;
                    }
                    else if(map[nx][ny] == '*'){ // 不是手下
                        //入队
                        tail++;
                        queue[tail].x =nx;
                        queue[tail].y =ny;
                        queue[tail].T =nt;
                        queue[tail].step =ns+1;
                        queue[tail].pre =head;

                        //标记
                        ST[nx][ny] = nt;
                        vis[nx][ny]=1;
                    }

                }
                else  //vis过
                    if(map[nx][ny]=='#' && ST[nx][ny] < nt-1){//但剩T更少
                        //入队
                        tail++;
                        queue[tail].x =nx;
                        queue[tail].y =ny;
                        queue[tail].T =nt-1;
                        queue[tail].step =ns+1;
                        queue[tail].pre =head;

                        //标记
                        ST[nx][ny] = nt-1;
                    }
                    else if(map[nx][ny]=='*' && ST[nx][ny] < nt){//但剩T更少
                        //入队
                        tail++;
                        queue[tail].x =nx;
                        queue[tail].y =ny;
                        queue[tail].T =nt;
                        queue[tail].step =ns+1;
                        queue[tail].pre =head;

                        //标记
                        ST[nx][ny] = nt;
                    }
            }
        }
    }
    printf("-1");
    return ;
}

int main(){
    scanf("%d%d%d",&m,&n,&T);
    int i,j;
    for (i=1;i<=m;i++){
            scanf("%s",&map[i][1]);
            for (j=1;j<=n;j++){
                if(map[i][j] == '+')
                    t.x=i,t.y=j;
                else if(map[i][j] == '@')
                    s.x=i,s.y=j;
            }
    }
    bfs();
    return 0;
}
