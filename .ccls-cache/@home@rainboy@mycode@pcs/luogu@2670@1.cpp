/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 02日 星期日 12:43:10 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
string s[105];

int fx[8][2] = { 0,1, 1,0, 0,-1, -1,0, 1,-1, -1,1, 1,1, -1,-1 };
// 0 1 //fx[0][0] fx[0][1]
// 1 0 //fx[1][0] fx[1][1]
// 0 -1

bool in_map(int x,int y){
    return x >=0 && x < n && y >=0 && y <m;
}

int main(){
    cin >> n >> m;
    int i,j,k;
    for( i =0;i<n;i++){
        cin >> s[i];
    }

    for( i =0;i<n;i++){
        for(j=0;j<m;j++){
            int cnt = 0;
            if( s[i][j] == '*')
                cout << "*";
            else{
                for( k=0;k<8;k++){
                    int nx = i + fx[k][0];
                    int ny = j + fx[k][1];
                    if( in_map(nx,ny) && s[nx][ny] == '*')
                        cnt++;
                }
                cout << cnt;
            }
        }
        cout << endl;
    }
    return 0;
}
