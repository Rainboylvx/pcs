#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n,m,k,r;
struct node {
    int w,v;
};
vector<node> p{1000}; //老师的题目

int f[200]; //各个时间下的刷题目的个数
int f2[200]; //每个时间下的最大分数,只做老师的题目
int main(){
    scanf("%d%d%d%d",&n,&m,&k,&r);
    for(int i=1;i<=n;++i){
        int t;
        scanf("%d",&t);
        for(int j = r ;j >= t;j--){
            if( f[j] <  f[j-t] +1){
                f[j] =  f[j-t] +1;
            }
        }
    }
    //printf("%d",f[r]);
    //
    for(int i=1;i<=m;++i){
        scanf("%d",&p[i].w);
    }
    for(int i=1;i<=m;++i){
        scanf("%d",&p[i].v);
    }

    for(int i =1;i<=m;i++){
        for(int j=r;j>=p[i].w;--j){
            if(f2[j] < f2[j-p[i].w] + p[i].v)
                f2[j] = f2[j-p[i].w] + p[i].v;
        }
    }
    
    int ans = -1;
    for(int i = 0;i<=r;i++){
        if( f2[i] >=k ){
            ans = max(ans,f[r-i]);
        }
    }
    printf("%d",ans);


    return 0;
}
