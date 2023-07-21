/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 02日 星期日 17:19:07 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

//====== 全局变量 =======
int n,m,root;
int c,l;
//====== 全局变量 =======

#define  FOR(i,n) for(int i=1;i<=n;i++)

struct node {
    int l,r;
    bool operator<(const node &b ) {
        if( l == b.l) 
            return r > b.r;
        return l > b.l;
    }
};
node a[maxn]; // cow
node cover[maxn];



//====== 函数与类 =======
//====== 函数与类 =======


//数据读取 
inline void init() {
    std::cin >> c >> m;
    for(int i=1;i<=c;++i){
        std::cin >> a[i].l >> a[i].r;
    }
    for(int i=1;i<=m;++i){
        std::cin >> cover[i].l >> cover[i].r;
    }
}

bool is_in_range(int a,int l,int r) {
    return a>=l && a <=r;
}

int main(){
    init();
    std::sort(a+1,a+1+c);
    int ans = 0;
    FOR(i,c){
        int idx = 0;
        FOR(j,m) {
            int l  = a[i].l;
            int r  = a[i].r;
            int spf = cover[j].l;
            int cnt = cover[j].r;
            if( !is_in_range(spf,l,r) || cnt == 0) continue;
            if( idx == 0 || spf > cover[idx].l)
                idx = j;
        }
        if( idx )
        {
            cover[idx].r--;
            ans++;
        }
    }
    std::cout << ans << "\n";
    return 0;
}
