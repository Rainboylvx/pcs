#include <cstdio>
#include <algorithm>
using namespace std;

struct node {
    int b,e,t;
};
int n ,h;
node a[5005];
int shu[30005];
bool cmp(node a,node b){
    if( a.e == b.e )
        return a.b < b.b;
    return a.e < b.e;
}

int get_sum(int i,int j){
    int ret=0;
    while(i <=j ){
        if( shu[i]==1) ret++;
        i++;
    }
    return ret;
}

int main(){
    scanf("%d",&n);
    scanf("%d",&h);
    int i;
    for(i=1;i<=h;++i){
        scanf("%d%d%d",&a[i].b,&a[i].e,&a[i].t);
    }
    sort(a+1,a+1+h,cmp);
    int cnt =0;
    
    for( i =1;i<=h;i++){
        int t2 = get_sum(a[i].b, a[i].e);
        int t = a[i].t -t2 ;
        if( t <= 0) continue;
        int j;
        for( j = a[i].e ;j >= a[i].b ;j--){
            if(shu[j] == 0)
                shu[j]=1, t--,cnt++;
            if( t == 0) break;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
