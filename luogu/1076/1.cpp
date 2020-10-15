/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 03日 星期一 22:51:22 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
const int mod = 20123;
int n,m;
int start;
int sum;

struct ROOM {
    bool up;
    int x;
};
ROOM r[10005][105];
int UP[10005][105];

int find(int start,int cen){
    int x = r[cen][start].x;
    int i = start;
    while(1){
        if(r[cen][i].up == 1) break;
        i++;
        if( i == m) i=0;
    }
    int j;
    for(j=1;j<=UP[cen][0];j++)
        if( UP[cen][j] == i) break;
    int ret = (j+x-1) % UP[cen][0];
    if( ret == 0) ret = UP[cen][0];
    return UP[cen][ret];
}

void init(){
    cin >>n >> m;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=0;j<m;j++){
            cin >> r[i][j].up >> r[i][j].x;
            if( r[i][j].up == 1){
                UP[i][ ++UP[i][0] ] = j;
            }
        }
    }
    cin >> start;
}

int main(){
    init();
    int i,j;
    for( i =1;i<=n;i++){
        sum += r[i][start].x;
        sum %= mod;
        start = find(start,i);
    }
    cout << sum;


    return 0;
}
