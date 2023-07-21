#include "base.hpp"
#include "utils/log.hpp"
#include "graph/linkList.hpp"
#include "data.hpp"
#include "chips/range.hpp"

int n,root;
dirgraph_nw gh;
int a[maxn]; //每个节点的权值

bool enable[maxn]; //这个点是否可选

dynamic_array choose; //选的点
void init() {
    in(n,root);
    in >> YankArray(n) >> a;
    in >> YankArray(n-1) >> gh;
}

int main(){
    init();
    a >> YankArray(n) >> out;
    for(int i=0;i<gh.get_edge_cnt();++i){
        out << gh[i];
    }
    // log(gh.get_edge_cnt());

    enable[root] = 1;
    int cnt =0;
    while(cnt != n) {
        //找到所有中最大的那个
        int m =-1;
        int idx;
        FOR(i,R>n) {
            if( enable[i] && a[i] > m) {
                m = a[i];
                idx = i;
            }
        }

        enable[idx] = 0;
        cnt++;
        choose.push(idx);
        
        //更新周围的点
        FOR(v,gh.edges_start_for(idx)) {
            out.println(int(v));
            enable[v] = 1;
        }
    }
    out << choose;

    int ans=0;
    int idx=1;
    FOR(i,choose) {
        ans += idx*a[i];
        idx++;
    }
    out<< ans;
    return 0;
}
