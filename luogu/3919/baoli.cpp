#include <bits/stdc++.h>
using namespace std;

int n,m;
typedef vector<int> vInt;

vector<vInt> V;

int vi,opt,pos,val;

void init(){
    scanf("%d%d",&n,&m);
    vInt v;
    int i,t;
    for(i=1;i<=n;i++){
        scanf("%d",&t);
        v.push_back(t);
    }
    V.push_back(v);
}
int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    int i,j;
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&vi,&opt,&pos);
        if( opt == 1)
            scanf("%d",&val);

        /* 复制 */
        vInt v(V[vi].begin(),V[vi].end());
        if(opt == 2){
            printf("%d\n",v[pos-1]);
        }
        else{
            v[pos-1] = val;
        }
        V.push_back(v);
    }

    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}

