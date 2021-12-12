#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;

const int maxn = 105;
const int maxe = 10005;
int n,m;
int indgree[maxn],outdgree[maxn];
int c[maxn],U[maxn];
int tSort[maxn],tc;
int out[maxn],outc;


struct {int u,v,w,next;} e1[maxn],e2[maxn];
int head1[maxn],head2[maxn];
int edge_cnt_1,edge_cnt_2;

void add1(int u,int v,int w){
    e1[++edge_cnt_1] = {u,v,w,head1[u]};
    head1[u] = edge_cnt_1;
}

void add2(int u,int v,int w){
    e2[++edge_cnt_2] = {u,v,w,head2[u]};
    head2[u] = edge_cnt_2;
}

void init(){
    memset(head1,-1,sizeof(head1));
    memset(head2,-1,sizeof(head2));
    scanf("%d%d",&n,&m);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d%d",&c[i],&U[i]);
    }
    for(i=1;i<=m;++i){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        indgree[v]++;
        outdgree[u]++;
        add1(u, v, w);
        add2(v,u,w);
    }
}

void kahn(){
    stack<int> sta;
    int i;
    for(i=1;i<=n;++i){
        if( indgree[i] == 0) sta.push(i);
    }

    while( !sta.empty()){
        int u = sta.top(); sta.pop();
        tSort[++tc] = u;
        for(i= head1[u];i !=-1 ;i = e1[i].next){
            int v= e1[i].v;
            indgree[v]--;
            if( indgree[v] == 0) sta.push(v);
        }
    }
}



int main(){
    init();
    kahn();
    int i,j;
    for(i=1;i<=n;i++){
        if( outdgree[i] == 0)  {

            out[++outc] = i;
            for(int i=1;i<=n;++i){
                //if( outdegree[i] == 0)
                //std::cout << "out " << i  << " " << outdgree[i] << '\n';
            }
        }
    }
    sort(out+1,out+outc+1); // ?

    for(i=1;i<=tc;++i){
        int u = tSort[i];
        for(j = head2[u];j !=-1; j = e2[j].next){
            int v= e2[j].v;
            if( c[v] <= 0) continue;
            c[u] += c[v]*e2[j].w;
        }
        c[u] -= U[u];
    }

    int cnt = 0;
    for(i=1;i<=outc;i++){
        if( c[out[i]] >0 ){
            cnt++;
            printf("%d %d\n",out[i],c[out[i]]);
        }
    }
    if( cnt == 0){
        printf("NULL");
    }
    return 0;
}


