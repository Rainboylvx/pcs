/* author: Rainboy email: rainboylvx@qq.com  time: 2021年 03月 01日 星期一 22:18:19 CST */
// f[i][x][y] = max{ f[i-1][x][y], f[i-1][x-wi1][y-wi2] + 1}
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int X,Y; // 球，体力
int n,m;

int f[1005][1005]; // [球][体力]

int main(){
    scanf("%d%d%d",&X,&Y,&n);
    for(int i=1;i<=n;++i){
        int c,r;
        scanf("%d%d",&c,&r);
        for(int x=X;x>=c;--x){ //球从大到小
            for(int y=Y;y>=r;--y){ // 体力从大到小
                f[x][y] = max(f[x][y],f[x-c][y-r]+1);
            }
        }
    }
    int Min; //最小消耗的体力
    for(int i=Y;i>=0;--i){
        if( f[X][i] == f[X][Y])
            Min = i;
        else break;
    }
    
    printf("%d %d",f[X][Y],Y-Min);
    return 0;
}
