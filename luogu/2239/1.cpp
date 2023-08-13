/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 27日 星期四 18:30:34 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,x,y;
/* 定义全局变量 */

ll val; //目标圈子的左上角的值
ll circle_num; // 目标是第几个圈

// n 第几个圈,__val ,这时左上角的值
void dfs(int circle,ll __val) {
    if( n-circle*2 <= 0 ) {
        return;
    }
    int top_line = 1+circle; //上部是那一行
    int bottom_line = n - circle; // 下部是哪一行
    int left_line = top_line;
    int right_line = bottom_line;
    bool cond_1 = ( (x == top_line || x == bottom_line) && ( y >= left_line && y <= right_line));
    bool cond_2 = ( ( y == left_line || y == right_line) && ( x>=top_line && x <= bottom_line));
    if( cond_1 || cond_2)
    {
        circle_num = circle;
        val = __val;
        return;
    }

    int cnt = n- circle*2; //这一圈,最上面一行的数量
    int len = cnt == 1 ? 1 : 4*(cnt-1); // 这一圈的数量

    dfs(circle+1,__val+len);

}
void init()
{
    std::cin >> n >> x >> y;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    dfs(0,1);
    // std::cout << circle_num << "\n";
    // std::cout << val << "\n";
    int cnt = n-circle_num*2; // 子矩阵的边的数量
    int pos = 0;
    int s = 1+circle_num;
    int t = 1+circle_num;
    int top_line = 1+circle_num; //上部是那一行
    int bottom_line = n - circle_num; // 下部是哪一行
    int left_line = top_line;
    int right_line = bottom_line;
    while( s != x || t != y) {
        t++;
        pos++;
        if( t >= right_line) {
            break;
        }
    }

    while( s != x || t != y) {
        s++;
        pos++;
        if( s >= bottom_line) {
            break;
        }
    }

    while( s != x || t != y) {
        t--;
        pos++;
        if( t <= left_line) {
            break;
        }
    }

    while( s != x || t != y) {
        s--;
        pos++;
        if( s <= top_line) {
            break;
        }
    }
    cout << val+pos;
    return 0;
}
