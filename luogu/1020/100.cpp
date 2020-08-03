/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 07月 25日 星期六 08:47:53 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int a[maxn];
int f1[maxn],f2[maxn];


int main(){
    int t;
    while( scanf("%d",&t) != EOF){
        a[++n] = t;
        f1[n] = f2[n] = 1;
    }
    int i,j;
    int m1 =0,m2 = 0;
    for(i=2;i<=n;i++){
        for(j=1;j<i;j++){
            if( a[j] >= a[i]){
                f1[i] = max(f1[i],f1[j]+1);
            }
            if( a[j] < a[i]){
                f2[i] = max(f2[i],f2[j]+1);
            }
        }
        //printf("%d %d\n",f1[i],f2[i]);
        m1 = max(m1,f1[i]);
        m2 = max(m2,f2[i]);
    }
    printf("%d\n%d",m1,m2);


    return 0;
}
