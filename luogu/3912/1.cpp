#include <cstdio>
int n;
const int maxn = 1e8+5;
int notp[maxn];

/* 欧拉筛 */
void getPrime(){
    int i,j;
    for(i=2;i<=n;++i){
        //没有被筛掉,是素数
        if( !notp[i]) notp[ ++notp[0]] = i;
        for(j=1;j<=notp[0] && notp[j] *i <=n;++j){
            notp[i* notp[j]] = 1;
            if( i % notp[j] == 0) break;
        }
    }
}
int main(){
    scanf("%d",&n);
    getPrime();
    printf("%d\n",notp[0]);
    return 0;
}

