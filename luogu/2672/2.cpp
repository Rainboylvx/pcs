/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 29日 星期六 08:35:24 CST */
#include <bits/stdc++.h>
#include "data_structure/binary_index_tree.hpp"
using namespace std;
typedef long long ll;
// const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
/* 定义全局变量 */

ll s[maxn];
ll a[maxn];

bit_range_max bit1,bit2;

void init()
{
    cin >> n;
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> s[i];
    }

    for(int i = 1;i <= n ;++i ) // i: 1->n
    {
        cin >> a[i];
        bit1.push_back(a[i]);
    }
    for(int i = 1;i <= n ;++i ) // i: 1->n
    {

        bit2.push_back( 2*s[i] + a[i]);
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    int last;
    ll ans = 0;

    //第一次先找一个大的 bit2

    int pos = bit2.max_pos(1,n);
    last = pos;
    ans += bit2.a[pos];
    bit1.update(pos,0);

    cout << ans << "\n";

    for(int i = 2;i <= n ;++i ) // i: 2->n
    {
        ll pre = 0; //从前面找的最大值
        ll suf = 0; //从后面找的最大值
        int pre_pos = -1;
        int suff_pos = -1;
        if( last > 1) { //有前面的位置
            pre_pos = bit1.max_pos(1,last-1);
            pre = bit1.a[pre_pos]; //前面的最大值
        }
        if( last < n) { //有后面的位置
            suff_pos = bit2.max_pos(last+1,n);
            suf = bit2.a[suff_pos];
        }

        if( ans + pre > ans - 2*s[last] + suf) { //选前面的值
            ans += pre;
            bit1.update(pre_pos,0); //这个位置改成0
        }
        else { //选后面的值
            ans -= 2*s[last];
            ans += suf;
            last = suff_pos;
            bit2.update(suff_pos,0); //把这个位置改成0
            bit1.update(suff_pos,0); //这个位置改成0
        }
        cout << ans << "\n";
    }

    return 0;
}
