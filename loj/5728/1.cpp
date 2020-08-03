#include <cstdio>
int n;
int a[1005],b[1005],c[1005],d[1005];

int _abc(int x,int y){
    int a = x-y;
    if( a < 0) a= -a;
    return a;
}

int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d%d%d",&a[i],&b[i],&c[i]);
        d[i] = a[i] + b[i] + c[i];
    }
    int ans=0;
    for(i=1;i<=n;++i){
        for(j=i+1;j<=n;++j){
            if(
                _abc(a[i],a[j]) <=5 &&
                _abc(b[i],b[j]) <=5 &&
                _abc(c[i],c[j]) <=5 &&
                _abc(d[i],d[j]) <=10
            )
                ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}

