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
long long f[2][maxn];

long long max_v;
long long min_v;
void init(){
    memset(f,0,sizeof(f));
    scanf("%lld%lld",&n,&h);
    max_v = 6*n;
    min_v = 3*n;
}

int sum[100] = {0};
void dp(){
    long long i,j,k;
    int cur = 0;
    f[0][1] = 1;
    f[0][2] = 1;
    f[0][3] = 1;
    f[0][4] = 1;

    for(i=2;i<=n;i++){ //每张牌
        cur = cur^1;
        memset(f[cur],0,sizeof(f[cur]));
        for(k=3;k<=6;k++){
            /* 位置 */
            int end = i*3+1;
            for (j=1;j<=end;j++){
                int num = i*3+j-1;
                int _num = num -k;
                int pre_p = _num+1-(i-1)*3;
                if( pre_p <=0 ) continue;
                f[cur][j] += f[cur^1][pre_p];
            }
        }
    }

    long long total = 0;
    long long ok = 0;
    int end = n*3+1;
    for(i=1;i<=end;i++){
        long long num = n*3+i-1;
        //printf("%lld %lld\n",num,f[cur][i]);
        printf("\t\t%lld ",f[cur][i]);
        total += f[cur][i];
        sum[i] = sum[i-1] + f[cur][i];
        if( num >= h)
            ok+= f[cur][i];
    }

    printf("\n");
    for (i=1;i<=end;i++){
        printf("\t\t%lf ",(sum[end]-sum[i-1])*1.0/sum[end]);
    }
    
    printf("\n");
    //printf("%lf\n",(ok*1.0)/total);
    
    
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
