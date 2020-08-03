/*
*   (@)                 
*   |-|----------------------------------------------
*   | |
*   |-|  时间: 2019/3/27 下午5:24:10
*   | |  作者: rainboy
*   |-|  题目: 3526-[NOIP2003-提高] 加分二叉树
*   | |                 
*   |_|----------SLIME-ONLINE-JUDGE--------- ༼◉‿◉ ༽
*   (@)
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int a[40];

int f[40][40];
int root[40][40];

void init(){
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][i] = a[i]; //边界
        f[i][i-1] = 1; //边界2
        f[i+1][i] = 1;
    }
}

void dp(){
    int i,j,k;
    for(i=2;i<=n;i++){  //长度
        for(j=1;j<=n-i+1;j++){  //枚举起点

            /* 枚举根 */
            for(k=j;k<=i+j-1;k++){

                int fen = a[k] + f[j][k-1]*f[k+1][i+j-1];
                if( f[j][i+j-1] < fen){
                    f[j][i+j-1] = fen;
                    root[j][i+j-1] = k;
                }

            }
        }
    }
}

/* 前序输出 */
void dfs(int x,int y){
    if(x > y)
        return;
    if( x==y){
        printf("%d ",x);
        return;
    }
    printf("%d ",root[x][y]);

    dfs(x,root[x][y]-1);
    dfs(root[x][y]+1,y);

}
int main(){
    init();
    dp();
    printf("%d\n",f[1][n]);
    dfs(1,n);
    return 0;
}


