/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 22日 星期三 17:26:54 CST
* problem: uva-11400
*----------------*/
#include <bits/stdc++.h>
using namespace std;

int n;
int f[1005];
int s[1005];

struct _p {
    int v,k,c,l;

    bool operator<(const _p &a){
        return v < a.v;
    }

};
_p a[1005];

void init(){
    int i,j;
    for (i=1;i<=n;i++){
        scanf("%d%d%d%d",&a[i].v,&a[i].k,&a[i].c,&a[i].l);
    }
    sort(a+1,a+n+1);
    memset(f,0x7f,sizeof(f));
    memset(s,0,sizeof(s));
    f[0] =0;
    for (i=1;i<=n;i++){
        s[i] = s[i-1] + a[i].l;
    }
}

void dp(){
    int i,j;
    for (i=1;i<=n;i++){
        for(j=1;j<=i;j++){
            int sum = s[i]-s[j-1];
            f[i] = min(f[i],f[j-1] + sum*a[i].c+a[i].k);
        }
    }
    printf("%d\n",f[n]);
}
int main(){
    while(1){
        scanf("%d",&n);
        if( n == 0) return 0;
        init();
        dp();
    }
    return 0;
}
