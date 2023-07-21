/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 06月 22日 星期四 18:24:46 CST */
#include <bits/stdc++.h>
#include "math/bit.hpp"
#include "utils.hpp"
using namespace std;
typedef long long ll;

int n,m;
/* 定义全局变量 */



// x op a -> b .求x
// -1 不可能
// 0,1 必须这0或1
// 2 都可以
int anti_op(char op ,int a,int b) {
    if( op == 'O') //or
    {
        if( a == 1 && b ==1)
            return 2; //表示随意
        if( a == 1 && b == 0)
            return -1; //表示不可能
        if( a == 0 && b == 1)
            return 1; // x 必须是 1
        if( a == 0 && b == 0)
            return 0; // x 必须是 0
    }
    else if( op == 'A') // AND
    {
        if( a == 1 && b ==1)
            return 1;
        if( a == 1 && b == 0)
            return 0; //表示不可能
        if( a == 0 && b == 1)
            return -1;
        if( a == 0 && b == 0)
            return 2;
    }
    else if( op == 'X')
    {
        if( a == 1 && b ==1)
            return 0;
        if( a == 1 && b == 0)
            return 1;
        if( a == 0 && b == 1)
            return 1;
        if( a == 0 && b == 0)
            return 0;
    }
    return 0;
}

char tmp[10];
struct opt {
    char opt;
    int val;
};

int a[40];
opt opts[maxn];

void init()
{
    cin >> n >> m;
    for(int i=1;i<=n;++i){
        cin >> tmp >> opts[i].val;
        opts[i].opt = tmp[0];
        // std::cout << opts[i].opt << " " << opts[i].val << "\n";
    }
}

int check(int pre,int idx,int k) {
    int res = anti_op(opts[idx].opt,bit_at_pos(opts[idx].val, k) , pre);
    if( res == 2 || res == -1)
        return res;
    else if ( idx == 1) return res;
    else return check(res, idx-1, k);
}

int ans = 0;

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    init();
    for(int i = 0 ;i <31;i++) { //假定i位置 结果都为1
        a[i] = check(1, n, i);
        // cout << a[i] << ' ';
    }
    
    Bit t1;
    Bit ans;
    //从最高位开始填写
    for(int i = 30 ;i >= 0 ;i -- ) {
        if( a[i] == -1) { //这个位置一个是0
            t1.reset(i); //这个位置为0
        }
        else if ( a[i] == 2) // 这个位置是2,任意填
        {
            ans.set(i); //这个位置为1
        }
        else if ( a[i] == 0) {
            ans.set(i); //这个位置为1
        }
        else if ( a[i] == 1) {
            Bit tt = t1;
            tt.set(i);
            if( tt.to_number() <= m  ) {
                ans.set(i);
                t1.set(i);
            }

        }
    }
    std::cout << ans.to_number() << "\n";
    return 0;
}
