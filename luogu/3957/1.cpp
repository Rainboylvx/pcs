/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 30日 星期日 11:54:27 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

ll n,d,k;
ll x[maxn]; //距离
ll s[maxn]; //分数
/* 定义全局变量 */
ll f[maxn];
bool vis[maxn]; // vis[i] 表示第i个点是事能到达

void init()
{
    std::cin >> n >> d >> k;

    for(ll i=1;i<=n;++i){
        std::cin >> x[i] >> s[i];
    }
}


// 单调队列的实现
//这个可以认为是一个模板,可以保存下来
struct mono_queue{
    ll a[maxn]; //存值
    ll head,tail;
    ll limit_start; // 队列中所有< limit_start 的都需要删除

    //这些都和队列一样
    void clear() { head = tail = limit_start = 0 ; }
    void push(ll v) { a[tail++] =v ;}
    void pop_front() { head++;}
    void pop_back() { tail--;}
    bool empty() { return head >= tail;}
    ll & front() { return a[head];}
    ll & back() { return a[tail-1];}


    // APi 1:  删除开头
    void del_front() 
    {
        while( !empty() && x[front()] < limit_start)
            pop_front();
    }

    // api2 数列中所有不优于p位置的都删除,然后加入p
    void push_new(ll p) {
        //TODO:
        while(!empty() && f[back()] <= f[p])
            pop_back();
        push(p);
    }
};
mono_queue q;

// 查检使用g金币的情况下,能否超过k
bool check(ll g) {
    ll max_jump = d+g; //最大跳跃距离
    ll min_jump = max(d-g,1ll); //最小跳跃距离
    memset(f,0,sizeof(f)); //清空f
    memset(vis,0,sizeof(vis));
    q.clear();
    f[0] = 0; //边界
    vis[0] = 1; //0号点到达过
    if( f[0] >= k) return true;
    for(ll i=1;i<=n;++i){
        // 求出
        ll last_pos = x[i] - min_jump; // 最后一个能跳到i的距离
        ll p = std::upper_bound(x+1, x+1+n, last_pos) - x; //找到第一个大于last_pos的位置
        p--; //前一个位置 就是最后一个 <= last_pos的位置
        ll last = p;
        while( p != 0 && x[p] >= x[i] - max_jump && x[p] <= x[i]-min_jump ) {
            if( q.empty() == false && q.back() >= p) break;
            p--;
        }
        for( ;p <= last;p++) {
            if( x[p] >= x[i] - max_jump && x[p] <= x[i]-min_jump )
                if(vis[p])
                    q.push_new(p);
        }
        q.limit_start = x[i] - max_jump;
        q.del_front(); //删除不要的点
        // 取单调队列中的点
        if( q.empty() == false) { //非空
            // if( )
            f[i] = f[q.front()] + s[i];
            vis[i] = 1;
        }
        if( f[i] >= k) 
            return true;

    }

    return false;
}


ll bs(ll l,ll r) {
    while (l < r) {
        ll mid = (l+r) >> 1;
        if( check(mid) )
            r = mid;
        else
            l = mid+1;
    }
    return l;
}


int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();

    // int i = 972;
    // cout << std::boolalpha<< check(i); return 0;
    // for(int i=972;i>=870;--i){
    //     cout << std::boolalpha<< i << " "<< check(i) << endl; 
    //     cout << "tail " << q.tail << "\n";
    // }
    //     return 0;
    // for(int i=1000;i>=467;--i){
    //     cout << std::boolalpha<< i << " "<< check(i) << endl; 
    //     // return 0;
    // }
    ll ans = bs(0,x[n]+1);
    if( ans == x[n]+1)
        cout << -1;
    else
        cout << ans;
    return 0;
}
