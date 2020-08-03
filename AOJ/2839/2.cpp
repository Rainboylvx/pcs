/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 20日 星期三 19:31:46 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

int a[maxn],b[maxn];
bool isb[maxn];


int c[] = {0,1,2,3,4};
int main(){
    scanf("%d",&n);
    int i,j,k,t;
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        isb[t] = 1;
    }
    int nn = n*2;
    for(i=1;i<=nn;++i){
        if( isb[i]) b[++b[0]] = i;
        else a[++a[0]] = i;
    }
    int ans=0;
    do{

    }
    while( next_permutation(c+1, c+5) );

    printf("%d\n",ans);


    return 0;
}
