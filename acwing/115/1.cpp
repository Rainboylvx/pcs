/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
*----------------*/
#ifndef DEBUG
#include <bits/stdc++.h>
#endif

#include "base.hpp"
#include "math/fraction.hpp"
// #include "graph/linkList.hpp"
#include "chips/range.hpp"

#ifdef DEBUG
// #include "utils/log.hpp"
// #include "utils/clock.hpp"
#endif


int n,root;
int fa[maxn];
int next[maxn];
bool del[maxn]; //delete falg of tree node, when merge to father



struct node {
    int first,last; //当前这个点的集合的起点,重点
    int fa; //父亲结点
    fraction w; //权值
};

int a[maxn];
node nodes[maxn];

// a -> b
void merge(node &a,node & b) {
    b.w.d() += a.w.d(); // sum of denominators
    b.w.n() += a.w.n(); // sum of numberator
    next[b.last] = a.first;
    b.last = a.last;
    del[a.first] = 1;
    //遍历所有的点
    //没有被删除的,且父亲是a.first 修改为b.first
    FOR(i,R>(n)) {
        if( del[i]) continue;
        if( nodes[i].fa == a.first)
            nodes[i].fa = b.first;
    }
}

void init() {
    in(n,root);
    // in >> (YankAdaptor( [&n](auto & lc,auto &rc){ } ) )  >>nodes;
    FOR(i,R>n) {
        in(a[i]);
        nodes[i].w.n() = a[i];
        nodes[i].w.d() = 1;
        nodes[i].last  = i;
        nodes[i].first = i;
    }
    FOR(i,R>(n-1)) {
        int u,v;
        in(u,v);
        nodes[v].fa = u;
    }
}

int main(){
    // Clock t("main time");
    init();
    FOR(i,R>(n-1)) {

        //找最大的值的那个点
        fraction _max = Fraction_neg_inf;
        int idx;
        FOR(j,R>n) {
            if(j == root ||  del[j]) continue;
            if( nodes[j].w > _max) {
                _max = nodes[j].w;
                idx = j;
            }
        }
        merge(nodes[idx], nodes[nodes[idx].fa]);
        // log(idx);
    }
    long long sum = 0;
    int idx = 1;
    while ( root != 0  ) {
        // log(root);
        sum += idx * a[root];
        // out << root;
        idx++;
        root = next[root];
    }
    // out.ln();
    out.println(sum);
    return 0;
}
