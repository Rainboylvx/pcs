/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 18日 星期六 10:59:05 CST
* problem: aoj2018acm省赛-问题G
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define maxn 6*5000+5

long long n,h;
long long f[maxn];

long long max_v;
long long min_v;
void init(){
    memset(f,0,sizeof(f));
    scanf("%lld%lld",&n,&h);
    max_v = 6*n;
    min_v = 3*n;
}

void dp(){
    long long i,j,k;
    f[0] = 1;
    for(i=1;i<=n;i++){
        for(k=3;k<=6;k++)
            for(j=max_v;j>=k;j--){
                f[j] = f[j] + f[j-k];
            }
    }

    long long total = 0;
    long long ok = 0;
    for(i = min_v;i<=max_v;i++){
        total += f[i];
        if( i >= h)
            ok+= f[i];
    }
    printf("%lf\n",(ok*1.0)/total);
    
}

int main(){
    long long T;
    scanf("%lld",&T);
    while(T--){
        init();
        dp();
    }
    return 0;
}
