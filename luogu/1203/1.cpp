/*-----------------
* author: Rainboy 🤠 /📬 : rainboylvx@qq.com ⌚: 2023-07-17 11:29:16
*----------------*/
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

char a[maxn]; //常用的一个数组 

void init()
{
    /* cin >> n >> m; */
    scanf("%d",&n);
    scanf("%s",a+1);
}

//i的下一个下标
int idx_next(int i) {
    ++i;
    if( i > n) i=1;
    return i;
}

int idx_pre(int i) {
    --i;
    if( i <=0) i = n;
    return i;
}

//从i开始的顺时针 收集的数目
int collect_clockwise(int i,int & endpos) {
    char color = a[i]; // 在第i个位置的颜色
    int cnt = 1;
    for(int s = idx_next(i); s != i ; s = idx_next(s)) {
        if( color == 'w' && a[s] != 'w') //如果你是从白色点开始
            color = a[s];               // 那么第一个你遇到的非白色点就是第一个白色点应该的颜色
        if( a[s] == color || a[s] == 'w'){
            ++cnt;
            endpos = s;
        }
        else break;
    }
    return cnt;
}

//从i开始的逆时针 收集的数目,但不能达到enpos 这个位置
int collect_anti_clockwise(int i,int endpos) {
    if( i == endpos)
        return 0;
    char color = a[i]; // 在第i个位置的颜色
    int cnt = 1;
    for(int s = idx_pre(i) ; s != i && s != endpos ; s= idx_pre(s))
    {
        if( color == 'w' && a[s] != 'w')
            color = a[s];
        if( a[s] == color || a[s] == 'w'){
            ++cnt;
        }
        else break;
    }
    return cnt;
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    int ans = 0;
    F(n) {
        int endpos;
        int t = collect_clockwise(i,endpos);
        t += collect_anti_clockwise(idx_pre(i),endpos);
        if( ans < t)
            ans=t;
    }
    printf("%d\n",ans);
    
    return 0;
}
