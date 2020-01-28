#include <cstdio>
#include <list>
using namespace std;

#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)


const int maxn = 1e5+5;
struct node {
    int l,r;
};

node p[maxn];
bool del[maxn];

void insert_left(int i,int j){
    p[i].l = p[j].l;
    p[ p[j].l ].r = i;
    p[j].l = i;
    p[i].r = j;
}

void insert_right(int i,int j){
    p[i].r = p[j].r;
    p[ p[j].r].l = i;
    p[j].r = i;
    p[i].l = j;
}

void _del(int i){
    if( del[i]) return;
    del[i] = 1;
    int left = p[i].l;
    int right = p[i].r;
    p[left].r = right;
    p[right].l = left;
}

int n,m;

void debug(){
    int i;
    For(i,1,n){
        printf("%d: %d %d\n",i,p[i].l,p[i].r);
    }
    printf("++++++++++++++++++++++++\n");
}
int main(){
    scanf("%d",&n);
    int i,t1,t2;

    For(i,2,n){
        scanf("%d%d",&t1,&t2);
        if( t2 == 0){
            insert_left(i, t1);
        }
        else
            insert_right(i, t1);
        //debug();
    }
    scanf("%d",&m);
    For(i,1,m){
        scanf("%d",&t1);
        _del(t1);
    }
    int first;
    For(i,1,n){
        if( del[i]) continue;
        if( p[i].l == 0){
            first = i;
            break;
        }
    }
    while( p[first].r !=0 ){
        printf("%d ",first);
        first = p[first].r;
    }
    printf("%d\n",first);
    return 0;
}
