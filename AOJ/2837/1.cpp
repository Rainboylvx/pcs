/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 20日 星期三 19:06:54 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int x,y;


double len(int x,int y){
    int X = 100-x;
    int Y = 10-y;
    return sqrt(X*X+Y*Y);
}
int main(){

    scanf("%d%d",&x,&y);
    double l = len(x,y);
    if( l <= 10.0)
        printf("0.000");
    else
        printf("%.3lf",l-10.0);

    return 0;
}
