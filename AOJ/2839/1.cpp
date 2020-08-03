/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 20日 星期三 19:31:46 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;

int a[maxn],b[maxn];
bool isb[maxn];



int main(){
    scanf("%d",&n);
    int i,j,k,t;
    for(i=1;i<=n;++i){
        scanf("%d",&t);
        isb[t] = 1;
        b[i] =t;
    }
    int nn = n*2;
    for(i=1;i<=nn;++i){
        if( isb[i]) 
            //b[++b[0]] = i;
            ;
        else a[++a[0]] = i;
    }
    //sort(a+1,a+n+1);
    sort(b+1,b+n/2+1);
    sort(b+n/2+1,b+n+1); //后半 从小到大
    int ans =0;

    int *c = a+n/2+1;
    //int ans=0;
    //先比较前N/2
    j = n/2;
    for(i=n/2;i>=1;i--){
        while( c[i] < b[j] && j>=1) j--;
        if( j >=1) ans++;
    }
    c = a+1;
    j = n/2+1;
    for(i=1;i<=n/2;i++){
        while(c[i] > a[j] && j <= n) j++;
        if( j <=n) ans++;
    }
    printf("%d\n",ans);


    return 0;
}
