/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 24日 星期六 16:24:17 CST */
#include <bits/stdc++.h>

#ifdef DEBUG
#include "utils/debug.hpp"
#endif

using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m,k;

/* 定义全局变量 */

int f[10005][1005]; //f[x][y] 到达x,y的最小点击次数
                    //

struct node { //每一列的水管
    int l,h;
};

node pipes[10005];//水管
struct node2 {
    int x,y;
};

node2 touch[10005]; // 每一行 上升,下降

void init()
{
    cin >> n >> m >> k;
    for(int i=0;i<n;++i){
        cin >> touch[i].x >> touch[i].y;
    }
    memset(pipes,-1,sizeof(pipes));
    for(int i=0;i<k;++i){
        int p,l,h;
        std::cin >> p >> l >> h;
        pipes[p].l = l;
        pipes[p].h = h;
    }
}

void dp() {

}

bool in_pipe(int col,int y)
{
    int l = pipes[col].l;
    int h = pipes[col].h;
    if( l == -1 && h == -1)
        return 0;
    if( h == -1)
        h = n+1;
    
    // else if( l == -1) {
    //     return y > -1 && y < h;
    // }
    // else if ( h == -1) {
    //     return y > l && y < n;
    // }
    //
    // return y > -1 && y < h;
    return !(y > l && y < h);
}

void upd_min(int & a,int b) {
    if( a > b)
        a = b;
}


//第x行,第y列,对应的是f数组的哪个元素
int & _map(int x,int y) {
    return f[x][y];
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();
    memset(f,0x3f,sizeof(f));

    //小鸟是否可以从0,0出发
    for(int i =0 ;i<= m;i++)  // 第0列,边界
        f[0][i] = 0;

    int max_col = 0;
    for(int i =1 ;i<= n;i++) { // 每一列
#ifdef DEBUG
        Tools::Table t;  //创建一个table
#endif
        for(int j = 1;j <= m;j++) { // 这一列的每一个点
            int pre_x = i-1; //前一列
            if( in_pipe(i, j) ) continue;
            
            // opts 1, 下降得来的
            int pre_y = j + touch[pre_x].y;
            int  &now = f[i][j];
            
            //计算上升
            for(int k = 1; ; k++) { //点击k次
                int pre_y = j - touch[pre_x].x*k;
                if( pre_y <= 0)
                    break;
                if(  in_pipe(pre_x, pre_y))
                    continue;
                // upd_min(now, f[pre_x][pre_y]+1);
                if( now > f[pre_x][pre_y]+k)
                {
                    now = f[pre_x][pre_y]+k;
                    max_col = i;
                }
            }
            if( !in_pipe(pre_x,pre_y)) { //前趋不是pipe里
                // upd_min(now,f[pre_x][pre_y]);
                if( now > f[pre_x][pre_y])
                {
                    now = f[pre_x][pre_y];
                    max_col = i;
                }
            }
        }
        //最高点很特殊
        //如果最高点可以被转移,那么尝试前面的[]可能性
        if( !in_pipe(i, m) ) {
            int x = touch[i-1].x;
            for( int j = 1; j<=m ;j++ )
            {
                if( in_pipe(i-1,j)) continue;

                int k = (m-j) / touch[i-1].x;
                if( (m-j) % touch[i-1].x)
                    k++;
                if( m-j == 0)
                    k++;

                if( f[i][m] > f[i-1][j]+k)
                {
                    f[i][m] = f[i-1][j]+k;
                    max_col = i;
                }
            }
        }
#ifdef DEBUG
        std::cout << i << ":\n";
        //输出第i列的所有的点的值
        for(int j=0;j<=m;++j){
            t.push(j);
        }
        t.add_row();
        for(int j=0;j<=m;++j){
            t.push(f[i][j]);
        }
        cout << t << '\n';
#endif
    }
#ifdef DEBUG
    dbg_one(max_col);
#endif
    if( max_col != n) {
        std::cout << "0\n";
        int sum=0;
        for(int i=1;i<=max_col;++i){
            if( pipes[i].l != -1 || pipes[i].h != -1)
                sum++;
        }
        std::cout << sum << "\n";
    }
    else {
        int _min = 0x3f3f3f3f;
        for(int i=1;i<=m;++i){
            upd_min(_min,f[n][i]);
        }
        std::cout << "1\n"<< _min ;
    }

    return 0;
}
