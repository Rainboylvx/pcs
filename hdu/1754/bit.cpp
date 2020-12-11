/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 09日 星期三 19:25:36 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;

template<typename T,int N=maxn,typename comp=greater<T> >
struct Bit_max {
    T a[maxn],c[maxn]; // a是原数组
    comp com;
    inline int lowbit(T x) { return x & -x;      }
    inline int fa(int p)   { return p+lowbit(p); }
    inline int left(int p) { return p-lowbit(p); }
    inline T g(T a ,T b) { return com(a,b) ? a : b;}
    void update_by_child(int p,T v){ //alias push
        c[p] = a[p] = v;
        int lb = lowbit(p);
        for(int i=1;i < lb ;i <<= 1)
            c[p] = g(c[p],c[p-i]);
    }

    void update(int p,T v){
        update_by_child(p, v);
        T t = c[p];
        for( p = fa(p); p<=N ; p = fa(p)){
            if( g(t,c[p]) ) c[p] = t;
            else break;
        }
    }

    T query(int l,int r){ // 求区间最值
        T ret = a[l];
        for( ; l <=r; ){
            int next = left(r)+1;
            if( next >= l ) ret = g(ret,c[r]) , r = next-1;
            else            ret = g(ret,a[r]) , r--;
        }
        return ret;
    }
};
Bit_max<ll> bit;
int main(){
    while ( 1 ) {
        memset(bit.a,0,sizeof(bit.a));
        memset(bit.c,0,sizeof(bit.c));
        if( scanf("%d%d",&n,&m) == EOF) break;
        for(int i=1;i<=n;++i){
            int t;
            scanf("%d",&t);
            bit.update_by_child(i, t);
        }
        char s[10];
        for(int i=1;i<=m;++i){
            scanf("%s",s);
            int x,y;
            if( s[0] == 'Q' ) {
                scanf("%d%d",&x,&y);
                ll ans = bit.query(x,y);
                printf("%lld\n",ans);
            }
            else {
                scanf("%d%d",&x,&y);
                bit.update(x, y);
            }
        }
    }
    return 0;
}
