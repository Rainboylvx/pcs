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

int a[2505][2505]; //常用的一个数组 
int f[2505][2505]; // dp

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


int check(int x,int y) {
    int len = f[x-1][y-1];
    int m1=0,m2=0;
    //行
    for(int i=y-1;i>=y-len;i--)
        if( a[x][i] ==0)
            m1++;
        else
            break;

    //列
    for(int i=x-1;i >= x-len;i--)
        if( a[i][y] == 0)
            m2++;
        else
            break;
    return std::min(m1,m2);
}

void calc() {
    F(n){ FF( j , m ){
            if( a[i][j] == 1) {
                f[i][j] = 1;

                int len = check(i,j);
                if( len == f[i-1][j-1]) {
                    f[i][j] = len+1;
                }
                else
                    f[i][j] = std::max(f[i][j],len+1);

                if(ans < f[i][j])
                    ans = f[i][j];
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
    memset(f,0,sizeof(f));
    calc();
    cout << ans << "\n";
    return 0;
}
