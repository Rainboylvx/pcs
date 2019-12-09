#include <bits/stdc++.h>
using namespace std;
 
int want_val;
int base;
struct _node {
    int val,cnt;
};
vector<_node> node;
 
void print_val(int t){
    for(auto x:node){
        cout << base+x.val << " " << (x.val+t) * x.cnt << endl;
    }
}
 
int main(){
    int  val,cnt;
    scanf("%d",&want_val);
    scanf("%d%d",&base,&cnt);
    node.push_back({0,cnt});
    int _max = -1;
    int _max_cnt;
    while(1){
        scanf("%d%d",&val,&cnt);
        if( val == -1 && cnt == -1){ break; }
        _node _last = node.back();
        if( val > _last.val+base+1){
            int i,j;
            int split =(cnt-_last.cnt) /(val-base-_last.val);

            int t = _last.cnt;
            for(i=_last.val+1+base;i<=val;i++){
                t += split;
                node.push_back({i-base,t });
            }
        }
        else {
            node.push_back({val-base,cnt });
        }
    }
    _node _last = node.back();
    int i,sub;
    _max_cnt = _last.cnt;
    _max = _last.val+base;
    scanf("%d",&sub);
    for(i=_max+1;1;++i){
        _max_cnt -= sub;
        if( _max_cnt <= 0) break;
        node.push_back({i-base,_max_cnt});
    }
 
    int want = want_val - base;
    int want_earn;
    int j,k,t;
    for(j=0;j<=10000;j++){
        for(k=-1;k<=1;k+=2){
            t = j *k;
            int max_earn = -1;
            for(auto i:node){
                int earn  = i.cnt*(i.val+t);
                max_earn = max(max_earn,earn);
                if( i.val == want){
                    want_earn = earn;
                }
            }
            if(want_earn == max_earn){
                cout << t << endl;;
                //print_val(t);
                return 0;
            }
        }
    }
    cout << "NO SOLUTION";
    return 0;
}
