/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 16日 星期一 11:56:41 CST
* problem: loj-2591
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
#define Each_e(u)	for(i = head[u]; ~i ; i = e[i].next)
using namespace std;

/* ======= 全局变量 =======*/
int mp[10][10]; // 填字的棋盘
int t_cnt = 0; //需要填的格子的数量
int ans,b_ans;

bool row[10][10],col[10][10],gong[10][10];// 记录每行,列,宫,中相应数字是否用过

//分值
int fen[10][10] = { 0,0,0,0,0,0,0,0,0,0, 0,6,6,6,6,6,6,6,6,6, 0,6,7,7,7,7,7,7,7,6, 0,6,7,8,8,8,8,8,7,6, 0,6,7,8,9,9,9,8,7,6, 0,6,7,8,9,10,9,8,7,6, 0,6,7,8,9,9,9,8,7,6, 0,6,7,8,8,8,8,8,7,6, 0,6,7,7,7,7,7,7,7,6, 0,6,6,6,6,6,6,6,6,6};

/* 得到宫的编号 */
#define g_num(x,y) (3*((x-1)/3)+((y-1)/3)+1)

struct _node{ int x,y,val; 
    bool operator<(_node t){
        if(val != t.val)
            return val < t.val;
        if( x != t.x )
            return x < t.x;
        return y < t.y;
    }
} node[100];

inline int get_num_0(bool a[]){
    int i,s = 0;
    For(i,1,9){
        s += a[i];
    }
    return 9-s;
}

/* ======= 全局变量 END =======*/

int get_fen(){
    int i,j,s = 0;
    For(i,1,9){
        For(j,1,9){
            s+= fen[i][j] *mp[i][j];
        }
    }
    return s;
}
void init(){
    int i,j,t;
    For(i,1,9){
        For(j,1,9){
            scanf("%d",&t);
            if(!t) t_cnt++;
            mp[i][j] = t;
            int n=g_num(i,j);
            row[i][t] = col[j][t] = gong[n][t] = 1;
        }
    }
    /* 得到每个点的  */
    int a[10];
    For(i,1,9){
        For(j,1,9){
            int p  = (i-1)*9+j;
            if( mp[i][j]){
                node[p].val = 0x3f3f3f3f;
                continue;
            }
            node[p].x = i;
            node[p].y = j;
            int t1 = get_num_0(row[i]);
            int t2 = get_num_0(col[j]);
            int t3 = get_num_0(gong[g_num(i,j)]);
            node[p].val = min(t1,min(t2,t3));
        }
    }
    sort(node+1,node+81+1);
    //For(i,1,t_cnt){
        //printf("%d %d %d\n",node[i].x,node[i].y,node[i].val);
    //}
    b_ans = get_fen();
}

void p_mp(){
    int i,j;
    For(i,1,9){
        For(j,1,9){
            printf("%d ",mp[i][j]);
        }
        printf("\n");
    }
}

void dfs(int dep,int f){
    if( dep > t_cnt){
        ans = max(ans,f);
        //if( ans == 2876){
            //p_mp();
        //}
        //printf("\n");
        //printf("\n");
        return;
    }
    int i;
    int x = node[dep].x;
    int y = node[dep].y;
    For(i,1,9){
        if( row[x][i] || col[y][i] || gong[g_num(x, y)][i]) continue;
        //最优性剪枝
        if( f+i*fen[x][y] + 90*(t_cnt - dep) <= ans) return;
        row[x][i] = 1;
        col[y][i] = 1;
        gong[g_num(x, y)][i] = 1;
        mp[x][y] = i;
        dfs(dep+1,f + i*fen[x][y]);
        mp[x][y] = 0;
        row[x][i] = 0;
        col[y][i] = 0;
        gong[g_num(x, y)][i] = 0;
    }
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    dfs(1,b_ans);
    if(ans)
        printf("%d\n",ans);
    else
        printf("-1");

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
