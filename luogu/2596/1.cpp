/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 11月 06日 星期五 16:27:50 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

int n,m;
struct linkList {
    typedef struct {int u,v,w,next;} edge;
    edge e[maxe];
    int h[maxn],edge_cnt=0;
    linkList(){
        edge_cnt=0;
        memset(h,-1,sizeof(h));
    }
    void add(int u,int v,int w=0){
        e[edge_cnt] = {u,v,w,h[u]};
        h[u] = edge_cnt++;
    }
    void add2(int u,int v,int w=0){
        add(u,v,w);
        add(v,u,w);
    }
    edge& operator[](int i){
        return e[i];
    }
} e;

void init(){
    
}

struct Random {
    random_device rd;
    mt19937 rnd{rd()};
    uniform_int_distribution<> dis;
    Random(){}
    Random(int l,int r){ dis = uniform_int_distribution<> (l,r); }
    int operator()(){ return dis(rnd); }
};

struct Fhq {
    struct {int va,fx,fa,sz,c[2];} tr[maxn];
    Random rnd;
    int root,x,y,z,idx=0;
    int id[maxn]; // 每个点对应的编号
    inline int &va(int p){return tr[p].va;}
    inline int &fx(int p){return tr[p].fx;}
    inline int &sz(int p){return tr[p].sz;}
    inline int &fa(int p){return tr[p].fa;}
    inline int &lc(int p){return tr[p].c[0];}
    inline int &rc(int p){return tr[p].c[1];}
    inline int &c(int p,bool aim){return tr[p].c[aim];}
    
    inline int New(int v){
        tr[++idx] = {v,rnd(),0,1,0,0};
        id[v] = idx;
        return idx;
    }
    inline void pushup(int p){ sz(p) = sz(lc(p)) + sz(rc(p)) + 1;}

    void split(int p,int k,int &x,int &y,int faa=0,int fab=0){
        if(!p) { x = y = 0 ; return;}
        // 在左子树内，p和rc(p)都是> k的
        if( sz(lc(p)) + 1 <= k){ //去
            x = p;
            fa(p) = faa;
            split(rc(p),k-sz(lc(p))-1,rc(p),y,p,fab);
        }
        else { // > k 一定在左子树上
            y = p;
            fa(p) = fab;
            split(lc(p), k, x, lc(p),faa,p);
        }
        pushup(p);
    }

    //合并两个树
    int merge(int x,int y){
        if( !x || !y) return x+y;
        int u;
        if( fx(x) > fx(y) ) u = x, rc(x) = merge(rc(x),y),fa(rc(x)) = x;
        else                u = y, lc(y) = merge(x,lc(y)),fa(lc(y)) = y;
        pushup(u);
        return u;
    }
    void push(int v){
        if( !root ){
            root = New(v);
            return;
        }
        root = merge(root, New(v));
    }

    // 编号x点的排名
    int rank(int x){
        int k = sz(lc(x)) + 1 , p = x;
        while( p != root && p ){
            // 当p是右孩子的时候
            if( p == rc(fa(p))) k += sz(lc(fa(p)))+1;
            p =fa(p);
        }
        return k;
    }

    void dfs(int p ){
        if( !p ) return;
        dfs(lc(p));
        printf("%d ",va(p));
        dfs(rc(p));
    }
} fhq;

#ifdef DEBUG
    vector<int> a;
#endif

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i){
        int t;
        scanf("%d",&t);
        fhq.push(t);
#ifdef DEBUG
        a.push_back(t);
#endif

    }
    #ifdef DEBUG
        fhq.dfs(fhq.root);
        printf("\n");
        for(int i=0;i<n;++i){
            printf("%d ",fhq.rank(fhq.id[a[i]]));
        }
    #endif

    char opt[100];
    int t;
    for(int i=1;i<=m;++i){
        scanf("%s",opt);
        scanf("%d",&t);
        if(opt[0] == 'T'){ // top
            int k = fhq.rank(fhq.id[t]); //找到t的排名
            int x,y,z;
            fhq.split(fhq.root, k,x,y);
            fhq.split(x,k-1,x,z);
            fhq.root = fhq.merge(z, fhq.merge(x, y));
        }
        else if (opt[0] == 'B') // Bottom
        {
            int k = fhq.rank(fhq.id[t]);
            int x,y,z;
            fhq.split(fhq.root,k,x,y);
            fhq.split(x,k-1,x,z);
            fhq.root = fhq.merge(fhq.merge(x,y),z);
        }
        else if( opt[0] == 'I'){ //insert
            int k  = fhq.rank(fhq.id[t]);
            if( !t ) continue;
             if( t > 0) {
            }
        }
    }

    return 0;
}
