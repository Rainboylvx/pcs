/*-----------------
 * author: Rainboy
 * email: rainboylvx@qq.com
 * create_time: 2019年 05月 20日 星期一 16:51:07 CST
 * end_time: 2019-05-21 14:59
 * problem: uva-116
 *----------------*/
#include <bits/stdc++.h>
using namespace std;

int m,n;
int a[11][101];
int f[11][101];
int pre[11][101];

int head;
int b[20];
void push(int x){
    b[head++] = x;
}

void init(){
    int i,j;
    for (i=1;i<=m;i++){
        for (j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    memset(f,0x3f,sizeof(f));
    memset(pre,-1,sizeof(pre));
}

void _dp(){
    int i,j,k;
    /* 边界 */
    for(i=1;i<=m;i++)
        f[i][n] = a[i][n];
    for(j=n-1;j>=1;j--){ //列
        for(i=1;i<=m;i++){ // 行
            int rows[3] ={i-1,i+1,i};
            if( i == 1) rows[0] = m;
            if( i == m) rows[1] = 1;
            sort(rows,rows+3);
            for(k=0;k<3;k++){
                int hang = rows[k];
                if( f[i][j] > f[hang][j+1]+a[i][j]){
                    f[i][j] = f[hang][j+1]+a[i][j];
                    pre[i][j] = hang;
                }
            }
        }
    }

    int _min = 0x7f7f7f7f;
    int idx;
    for(i=1;i<=m;i++){
        if( _min > f[i][1]){
            _min = f[i][1];
            idx = i;
        }
    }
    for (i=idx,j=1;j <n;i = pre[i][j],j++){
        printf("%d ",i);
    }
    printf("%d\n",pre[i][n-1]);
    printf("%d\n",_min);
}

int main(){
    while ( scanf("%d%d",&m,&n) != EOF) {
        init();
        if( n == 1){
            int i,k;
            int _min = 0x7f7f7f7f;
            for(i=1;i<=m;i++){
                if(_min > a[i][1]){
                    _min = a[i][1];
                    k = i;
                }
            }
            printf("%d\n%d\n",k,_min);
        }
        else
            _dp();
    }
    return 0;
}


