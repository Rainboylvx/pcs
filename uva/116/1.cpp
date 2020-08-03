/*-----------------
 * author: Rainboy
 * email: rainboylvx@qq.com
 * create_time: 2019年 05月 20日 星期一 16:51:07 CST
 * end_time: 2019-05-21 10:16
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

void tran(int x,int &nx){
    if( x == 0)
        nx  = m;
    else if( x == m+1)
        nx = 1;
    else 
        nx = x;
}

/* 得到序列 */
string get_seq(int x,int y){
    string s;
    while(1){
        char t =  x+'0';
        s.push_back(t);

        if( pre[x][y] == -1)
            break;
        x  = pre[x][y];
        y--;
    }
    reverse(s.begin(),s.end());
    return s;
}
void _dp(){
    int i,j,k;
    for (j=1;j<=m;j++) //边界
        f[j][1] = a[j][1];

    for (i=1;i<n;i++){ //每一列
        for (j=1;j<=m;j++){
            int nx,ny;
            tran(j-1,ny);
            if( f[ny][i+1] > f[j][i] + a[ny][i+1]){
                f[ny][i+1] = f[j][i] + a[ny][i+1];
                pre[ny][i+1] = j;
            } 
            else if ( f[ny][i+1] == f[j][i] + a[ny][i+1] && pre[ny][i+1] != -1){
                string s1 = get_seq(j,i);
                string s2 = get_seq(pre[ny][i+1],i);
                if( s1 < s2)
                    pre[ny][i+1] = j;
            }

            ny= j;
            if( f[ny][i+1] > f[j][i] + a[ny][i+1]){
                f[ny][i+1] = f[j][i] + a[ny][i+1];
                pre[ny][i+1] = j;
            }
            else if ( f[ny][i+1] == f[j][i] + a[ny][i+1] && pre[ny][i+1] != -1){
                string s1 = get_seq(j,i);
                string s2 = get_seq(pre[ny][i+1],i);
                if( s1 < s2)
                    pre[ny][i+1] = j;
            }

            tran(j+1,ny);
            if( f[ny][i+1] > f[j][i] + a[ny][i+1]){
                f[ny][i+1] = f[j][i] + a[ny][i+1];
                pre[ny][i+1] = j;
            }
            else if ( f[ny][i+1] == f[j][i] + a[ny][i+1] && pre[ny][i+1] != -1){
                string s1 = get_seq(j,i);
                string s2 = get_seq(pre[ny][i+1],i);
                if( s1 < s2)
                    pre[ny][i+1] = j;
            }
        }
    }

    int _min = 0x7f7f7f7f,idx;
    head = 0;
    for(i=1;i<=m;i++){
        if( _min > f[i][n]){
            _min = f[i][n];
            idx = i;
        }
        else if( _min == f[i][n]){
            string s1 = get_seq(idx,n);
            string s2 = get_seq(i,n);
            if( s1 > s2)
                idx = i;
        }
    }
    
    string seq = get_seq(idx,n);
    int len = seq.length();
    for(i=0;i<len-1;i++){
        printf("%d ",seq[i]-'0');
    }
    printf("%d\n",seq.back()-'0');
    printf("%d\n",_min);
}

int main(){
    while ( scanf("%d%d",&m,&n) != EOF) {
        init();
        _dp();
    }
    return 0;
}


