/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 08月 19日 星期三 16:21:20 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;
int a[maxn],b[maxn];
int c[maxn];

void init(){
    scanf("%d",&n);
    int i,j,k;
    for(i=1;i<=n;++i){
        c[i] = i;
    }
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    for(i=1;i<=n;++i){
        scanf("%d",&b[i]);
    }
}

int get_val(){
    int sum =0,i,j;
    for(i=1;i<=n;i++){
        sum += (a[i] - b[c[i]])*(a[i] - b[c[i]]);
    }
    return sum;
}

int main(){

    init();
    int ans = 0x7f7f7f7f;
    int i,j,k;
    return 1;
    ans = get_val();
    next_permutation(c+1,c+1+n);
    do {
        int v =get_val();
        if( v < ans ) return 1;
    }while( next_permutation(c+1,c+1+n));
    printf("%d\n",ans);
    return 0;
}
