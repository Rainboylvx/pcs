/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-18 11:14:31
*----------------*/
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

//////// 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif


int n,m;
/* 定义全局变量 */

int a[200][200]; //常用的一个数组 

void init()
{
    cin >> n >> m;
    F(n){
        FF(j,m){
            cin >> a[i][j];
        }
    }
}

int ans = 0;


bool check(int x,int y,int len) {
    if( a[x+len-1][y+len-1] !=1 )
        return 0;
    for(int i=y;i<y+len-1;i++)
        if( a[x+len-1][i] ==1)
            return 0;
    for(int i=x;i<x+len-1;i++)
        if( a[i][y+len-1] == 1) 
            return 0 ;
    return 1;
}

void calc() {
    F(n){
        FF( j , m ){
            F3(len,1,n) {
                //超过了矩阵的范围
                if( i + len-1 > n || j+ len-1 >m)
                    break;
                if(check(i,j,len) )
                    ans = std::max(ans,len); //更新ans
                else
                    break;
            }
        }
    }
}

//左右翻转
void flip() {
    F(n){ //行
        std::reverse(a[i]+1,a[i]+1+m);
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    calc();
    flip();
    calc();
    cout << ans << "\n";
    return 0;
}
