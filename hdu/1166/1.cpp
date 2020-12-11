/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 11日 星期五 23:11:28 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
template<typename T,int N = maxn>
struct sgt_point {
    T tr[N*4+5];
    inline int lp(int p){ return p << 1;}
    inline int rp(int p){ return (p << 1) | 1;}
    inline int mid(int l,int r){return (l+r)>>1;}
    
    void pushup(int p){ tr[p] = tr[lp(p)] + tr[rp(p)]; }

    void build(int l,int r,int p){
        if( l == r ) {
            scanf("%lld",&tr[p]);
            return;
        }
        int m = mid(l,r);
        build(l,m,lp(p));
        build(m+1,r,rp(p));
        pushup(p);
    }

    void update(int pos,int add,int l,int r,int p){
        if( l==r) {
            tr[p] +=add;
            return;
        }
        int m = mid(l,r);
        if( pos <=m )
            update(pos,add,l,m,lp(p));
        else 
            update(pos,add,m+1,r,rp(p));
        pushup(p);
    }

    T query(int L,int R,int l,int r,int p){
        if( L <= l && r <= R ) {
            return tr[p];
        }
        int m = mid(l,r);
        T ret=0;
        if( L <= m )
            ret += query(L, R, l, m, lp(p));
        if( R >=m+1)
            ret += query(L, R, m+1, r, rp(p));
        return ret;
    }

};

sgt_point<ll> sgt;

char s[100];
int main(){
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;++i)
    {
        printf("Case %d:\n",i);
        scanf("%d",&n);
        sgt.build(1, n, 1);
        while ( 1 ) {
            scanf("%s",s);
            if(s[0] == 'E') break;
            int x,y;

            if(s[0] == 'A'){
                scanf("%d%d",&x,&y);
                sgt.update(x, y, 1, n, 1);
            }

            if(s[0] == 'S'){
                scanf("%d%d",&x,&y);
                sgt.update(x, -y, 1, n, 1);
            }
            if(s[0] == 'Q'){
                scanf("%d%d",&x,&y);
                ll ans = sgt.query(x,y,1,n,1);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}
