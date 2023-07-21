/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 20日 星期二 19:48:46 CST */
#include <bits/stdc++.h>
//#include "utils/log.hpp"
using namespace std;
typedef long long ll;
const int maxn = 4000,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */


//带有-inf的数
template<typename T>
struct number {
    int flag{-1}; //-1 -inf 0 normal ,1 inf
    T v;
    number(): flag(-1) {}

    number & operator = (const number & oth) {
        if( &oth == this) return *this;
        flag = oth.flag;
        v = oth.v;
        return *this;
    }

    number & operator = (const T & oth) {
        flag = 0;
        v = oth;
        return *this;
    }

    bool operator < (const number & oth) {
        if( flag != oth.flag )
            return flag < oth.flag;
        return v < oth.v;
    }

    number operator+(const number & oth) {
        number n;
        if( flag == 0 && oth.flag == 0) {
            n.flag = 0;
            n.v = v + oth.v;
        }
        else n.flag = flag;
        return n;
    }

    number operator+(const T & oth) {
        number n;
        if( flag == 0) {
            n.flag = 0;
            n.v = v + oth;
        }
        else n.flag = flag;
        return n;
    }

    friend std::ostream & operator << (std::ostream& o,const number & oth) {
        if( oth.flag == -1)
            o << "-INF";
        else if ( oth.flag == 1)
            o << "INF";
        else
            o << oth.v;
        return o;
    }
};

number<long long> f[2][maxn][2];
ll a[maxn];

void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        std::cin >> a[i];
    }
}

template<typename T1>
void max_upd(T1 & a,const T1 & b) {
    if( a < b)
        a = b;
}

template<typename T1,typename... T>
void max_upd(T1 & a,const T1 & b ,const T&... o) {
    if( a < b)
        a = b;
    max_upd(a,o...);
}

number<ll> _max;
int idx = 0;
void dp() {
    idx = 0;

    //边界,选0个的情况
    // for(int i = 2;i <= n;i++)
    // max_upd( f[1][0][0] ,f[0][0][0]);
    f[1][0][0] = f[0][0][0];
    max_upd(_max,f[idx][1][1]);


    for(int i = 2;i <= n;i++){// 枚举 长度

        // cout << "i == " << i << endl;
        for(int j =1;j<=m;j++) {  //枚举 亮的数量 
            if( j > i) continue;
            // cout << "j == " << j << endl;

            f[idx^1][j][1].flag = -1;
            max_upd( f[idx^1][j][1],f[idx][j-1][1] + a[i] , f[idx][j-1][0]);
            // cout << "f[idx^1][j][1] " << f[idx^1][j][1]  << endl;
            // cout << i <<' ' << j << ' ' << 1 <<"--->" << f[idx^1][j][1] << '\n';

            max_upd(_max,f[idx^1][j][1]);
            
            f[idx^1][j][0].flag = -1;
            max_upd(f[idx^1][j][0],f[idx][j][1],f[idx][j][0]);
            max_upd(_max,f[idx^1][j][0]);
            // cout << "f[idx^1][j][0] " << f[idx^1][j][0]  << endl;
            // cout << i <<' ' << j << ' ' << 0 <<"--->" << f[idx^1][j][0] << '\n';
        }
        idx = idx^1;
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    init();

    // dp1 
    memset(f, -1, sizeof(f));
    f[0][1][1] = 0; //前1个物品,且这个物品不选
    f[0][0][0] = 0; //选中第一个 ,为0
    dp();
    number ans = _max;
    // std::cout << "--00-------------------\n" ;
    // return 0;
    memset(f, -1, sizeof(f));
    f[0][1][1] = a[1];
    // dp2 
    dp();
    max_upd(ans, f[idx][m][1]);
    // cout << f[idx][m][1] << endl;
    
    std::cout << ans << std::endl;
    return 0;
}

