#include <cstdio>
#include <cmath>

int x,y,m,n,l;

int exgcd(int a,int b,int &x,int &y){//ax+by=gcd(a,b)
    if(b==0){x=1,y=0;return a;}
    int gcd=exgcd(b,a%b,x,y);
    int tx=x;
    x=y;
    y=tx-(a/b)*y;
    return gcd;
}

int main(){
    scanf("%d%d%d%d%d",&x,&y,&m,&n,&l);
    int a = m-n;
    int b = l;
    int d = y-x;
    int ax,ay;
    int c =exgcd(a,b,ax,ay);
    //printf("%d\n",c);
    //printf("ax=  %d\n",ax);
    if( d % c  != 0){
        printf("Impossible");
        return 0;
    }


    int mm = abs(b /c);
    long long ans = (((long long)ax*d/c % mm) +mm) %mm;
    printf("%lld\n",ans);


    return 0;
}

