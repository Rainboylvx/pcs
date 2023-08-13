/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-27 15:44:07
*----------------*/
#define __maxn__ 1e6
#define __maxe__ 2e7
#include "base.hpp"
#include "chips/piece.hpp"
#include "math/fraction.hpp" // 分数类
#include "data_structure/dynamic_array.hpp"
// #include "graph/linkList.hpp"
// #include "chips/range.hpp"

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp" 
#else
#define log(...)
#endif


//==== 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,t) for(int i=s;i<=t;++i)

//====== 全局变量 =======

int n,m,root;
// int a[maxn];


dynamic_array<int> a;
dynamic_array<int> b;
int in_dgree[maxn];
int d[maxn];

int gh[1005][1005];

//====== 全局变量 =======



//====== 函数与类 =======


//====== 函数与类 =======


//数据读取 
inline void init() {
    in(n,m);
    F(m){
        int t;
        in.read(t);
        a.clear();
        FF( j , t ){
            in >> a;
        }
        b.clear();
        F3(j,2,a.size()) {
            int start = a[j-1];
            int end = a[j];
            for(int k = start+1;k < end; k++) {
                b.push(k);
            }
        }
        FF( j , a.size() ){
            FF( k , b.size() ){
                if( gh[b[k]][a[j]] == 0 )
                {
                    gh[b[k]][a[j]] = 1; //表明 b[k] 到 a[j] 有连线
                    // gh.add(b[k],a[j]);
                    in_dgree[a[j]]++;
                }
            }
        }
    }
}


int main(){
#ifdef DEBUG
    Clock t("main time");
#endif
    init();

    a.clear();
    F(n){
        if(in_dgree[i] == 0)
        {
            d[i] = 1;
            a.push(i); //加入第一层入度为0的点
        }
    }
    int cnt = n;
    int ans = 0;
    while( n ) {
        int u = a.top();
        // log(u,d[u]);
        ans = std::max(ans,d[u]);
        a.pop_back();
        n--;
        for(int v = 1 ; v<=cnt; v++)
        {
            if( gh[u][v] == 0) continue;
            if(d[v] <= d[u])
                d[v] = d[u]+1;
            // log(u,v,d[v]);
            in_dgree[v]--;
            if( in_dgree[v] == 0) {
                a.push(v);
            }
        }
    }
    // out.println(d+1,d+1+cnt);
    out << ans;

    return 0;
}
