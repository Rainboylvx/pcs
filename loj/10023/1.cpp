#include <cstdio>
#include <ctime>
#include <algorithm>
using namespace std;


int n;
int p[105][105]; //板子
int max_col=0;

int up[105][105]; //每个board的直接上级

inline void up_push(int x,int y){
    up[x][ ++up[x][0] ] = y;
}

// [l1,r1] [l2,r2] 相交的元素的数量
inline int common_arear(int l1,int r1,int l2,int r2){
    return min(r2,r1) - max(l1,l2)+1;
}


struct _board {
    int x1,y1,x2,y2,c; //c颜色的编号
    int flag; //是否染色
};
_board board[105];

void init(){
    scanf("%d",&n);
    int i,j,x1,y1,x2,y2,c;
    for(i=1;i<=n;++i){
        scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
        board[i] = {x1, y1, x2, y2, c,0};
        max_col = max(max_col,c);
    }

    //遍历得到每个board 上面的board
    for(i=1;i<=n;++i){
        for(j=1;j<=n;++j){
            if( j == i) continue;
            if( board[i].x1 == board[j].x2 && common_arear( board[i].y1, board[i].y2, board[j].y1, board[j].y2) > 1)
                up_push(i, j);
        }
    }
}

bool all_have_col(){
    int i;
    for(i=1;i<=n;++i){
        if( !board[i].flag) 
            return 0;
    }
    return 1;
}

/* idx这个板子可以染颜色 x */
bool can_paint(int idx,int x ){
    if( board[idx].c != x) return 0;
    if( board[idx].flag ) return 0;
    int i;
    for(i=1;i<=up[idx][0];++i){
        int u = up[idx][i];
        if( board[u].flag == 0)
            return 0;
    }
    return 1;
}

int a[100];
int ans = 0x3f3f3f3f;
// cnt 第几次拿起刷子,col,那个颜色的刷子
bool dfs(int cnt,int col){
    /* 是不是所有的板子都染色了 */
    if( all_have_col() ) return 1;
    if( cnt >= ans ) return 0; //最优性剪枝
    

    /* 估价函数 */

    /* 尝试用当前的颜色染色 */
    int i,paint_flag = 0;
    for(i=1;i<=n;++i){
        if( can_paint(i,col)) {
            board[i].flag = 1;
            paint_flag = 1;
            if( all_have_col()) { ans = min(ans,cnt); board[i].flag = 0; return 1; }
            bool ret = dfs(cnt,col);

            if( !ret ) { // 下一层染色 失败了
                /* 尝试用其他的颜色染色 */
                int c;
                for(c=1;c<=max_col;++c){
                    if( c == col ) continue;
                    if( cnt+1 >= ans ) continue;
                    dfs(cnt+1,c);
                }
            }

            board[i].flag = 0;
        }
    }
    return paint_flag;

}

int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i;
    for(i=1;i<=max_col;++i){
        dfs(1,i);
    }
    printf("%d\n",ans);
    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
