/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
*----------------*/

#include "base.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp"
// #include "graph/linkList.hpp"
#include "chips/range.hpp"

#ifdef DEBUG
#include "utils.hpp"
#endif

//====== 全局变量 =======
int n,m,root;
//====== 全局变量 =======

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

void operator>>(fast_in & in,node & a) {
    in.read(a.l,a.r);
}

//数据读取 
inline void init() {
    in(n,m);
    in >> YankArray(n) >> a;
    in >> YankArray(m) >> cover;
}

int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();
    std::sort(a+1,a+1+n);
    int ans = 0;
    FOR(i,R>n){
        int idx = 0;
        FOR(j,R>m) {
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
    out << ans;
    out.ln();
    return 0;
}
