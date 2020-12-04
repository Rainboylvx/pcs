/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 11月 04日 星期三 09:27:32 CST */
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

bool isLink = true;
bool is_ai_1  = true;

void init(){
    scanf("%d%d",&n,&m);
    int i,u,v,w;
    for(i=1;i<=n-1;++i){
        scanf("%d%d%d",&u,&v,&w);
        e.add2(u,v,w);
        if( v != u+1) isLink = 0;
        if( u != 1) is_ai_1 = 0;
    }
}

int link_edge[maxe];

/* 使用: 首先定义EF::check函数 
 * EF::work(int l,int r)            二分
 * EF::work(double l,double r)      二分-double
 *
 * EF::work 区间[l,r) 内第一个不满足check()的位置
 *  if check(mid) => mid < key 则找到第一个 >=key 的位置 
 *  if check(mid) => mid <=key 则找到第一个 >key  的位置 
 *  核心思想:[l,r)是满足check的区间,不停缩小[l,r)
 * */
namespace EF {
    bool check(int mid);    //函数声明
    int work(int l,int r){
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
}
bool EF::check(int mid){
    int cnt = 0,tot = 0;
    for(int i=1;i<n;i++){
        tot += link_edge[i];
        if( tot >= mid) {
            cnt++;
            if( cnt >= m) break;
            tot = 0;
        }
    }
    return cnt <= n-1;
}

namespace EF2 {
    bool check(int mid);    //函数声明
    int work(int l,int r){
        while( l != r){
            int mid = (l+r)>>1;
            if( check(mid) ) l = mid+1;
            else r = mid;
        }
        return l;
    }
}
int ef2head = 1;
bool EF2::check(int mid){
    
}
vector<int> ef2a;

int main(){
    init();
    if( m == 1){
        int ans = -1;
        //树上最长链
        return 0;
    }

    if( isLink ){
        int ans = 0;
        for(int i=1;i<n;i++){
            link_edge[i] = e[e.h[i]].w;
            ans += link_edge[i];
        }
        int a = EF::work(0,ans);
        printf("%d\n",a-1);
        return 0;
    }

    if( is_ai_1 ){ //菊花树 二分
        for(int i=e.h[1];~i;i=e[i].next){
            ef2a.push_back(e[i].w);
        }
        sort(ef2a.begin(),ef2a.end());
        return 0;
    }

    return 0;
}
