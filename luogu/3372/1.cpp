/* author: Rainboy email: rainboylvx@qq.com  time: 2020年 12月 22日 星期二 09:25:18 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
//===================== 线段树 BEG
template<typename T=int,int N=maxn>
struct sgt_range {
    T tr[N*4+5];
    T flag[N*4+5]; //flag 里的内容与题目有关，灵活设定
    inline int lp(int p){return p<<1;}
    inline int rp(int p){return (p<<1)|1;}
    inline int mid(int l,int r){return (l+r)>>1;}

    inline void pushup(int p){  //向上合并
        tr[p] = tr[lp(p)] + tr[rp(p)];
    }
    inline void pushdown(int p,int m){ //向下压标记
        if( flag[p] ){ //当前点有flag
            flag[lp(p)] += flag[p];
            flag[rp(p)] += flag[p];
            tr[lp(p)] += flag[p]*(m-(m>>1)); //成段替换需要这样写
            tr[rp(p)] += flag[p]*(m>>1);
            flag[p] = 0;
        }
    }

    void build(int l,int r,int p){ //建立
        if( l == r ) {
            scanf("%lld",&tr[p]);
            return;
        }
        int m = mid(l,r);
        build(l,m,lp(p));
        build(m+1,r,rp(p));
        pushup(p);
    }

    // 区间更新
    void update(int L,int R,T v,int l,int r,int p){ 
        if(L <= l && r <= R) {
            flag[p] += v; 
            tr[p] += (r-l+1)*v;
            return;
        }
        pushdown(p,r-l+1); //路过
        int m = mid(l,r);
        if( L<=m) 
            update(L,R,v,l,m,lp(p));
        if( R>=m+1)
            update(L,R,v,m+1,r,rp(p));
        pushup(p);
    }

    //区间查询
    T query(int L,int R,int l,int r,int p){
        if( L <=l && r<=R ) {
            return tr[p];
        }
        pushdown(p, r-l+1);
        int m = mid(l,r);
        T ret = 0;
        if( L <= m ) ret+=query(L,R,l,m,lp(p));
        if( R >=m+1) ret+=query(L,R,m+1,r,rp(p));
        //pushup(p);
        return ret;
    }
};
sgt_range<ll> sgt;
//===================== 线段树 END

#ifdef DEBUG
template<typename T=int>
struct sgt_debug {
        vector<string> v;
        char fmt[1000];
        int to_dot_cnt = 0;
        sgt_range<T> &Sgt;
        sgt_debug():Sgt(sgt){}
        sgt_debug(sgt_range<T> &sgt):Sgt(sgt){}
        inline int mid(int l,int r){return (l+r)>>1;}

        void to_dot () {
            v.clear();
            ofstream dot;
            sprintf(fmt,"%04d.dot",++to_dot_cnt);
            dot.open(fmt);
            dot << "graph g{\n node[shape=record];\n";
            _to_dot(1,n,1);
            for (auto& e : v) {
                dot<< e;
            }
            dot<< "}" <<endl;
            dot.close();
        }
        void _to_dot(int l,int r,int p) {
            sprintf(fmt,"%d[label=\"%d|flag=%d|%d|%d\"];\n",p,Sgt.tr[p],Sgt.flag[p],l,r);
            v.push_back(string(fmt));
            if( l == r){
                return ;
            }
            int m = mid(l,r);

            sprintf(fmt,"%d--%d;\n",p,Sgt.lp(p));
            v.push_back(string(fmt));
            _to_dot(l,m,Sgt.lp(p));
            sprintf(fmt,"%d--%d;\n",p,Sgt.rp(p));
            v.push_back(string(fmt));
            _to_dot(m+1,r,Sgt.rp(p));
        }
};
sgt_debug<ll> sgt_d;
#endif

int main(){
    scanf("%d%d",&n,&m);
    sgt.build(1, n, 1);
    for(int i=1;i<=m;++i){
        int o,x,y,z;
        scanf("%d",&o);
        if( o == 1) {
            scanf("%d%d%d",&x,&y,&z);
            sgt.update(x,y,z,1,n,1);
        }
        else {
            scanf("%d%d",&x,&y);
            ll ans = sgt.query(x, y, 1, n, 1);
            printf("%lld\n",ans);
        }
#ifdef DEBUG
        sgt_d.to_dot();
#endif
    }
    return 0;
}
