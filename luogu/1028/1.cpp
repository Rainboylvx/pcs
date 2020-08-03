#include <cstdio>

int n;
int jishu[10000];
int chai(int x){
    if( x == 1) 
        return 1;
    if( jishu[x] !=0 ) return jishu[x];
    int mid = x /2; // middle
    int i,sum=0;
    for(i=1;i<=mid;i++){
        sum += chai(i);
    }
    jishu[x] = sum+1;
    return sum+1;
}
int main(){
    scanf("%d",&n);
    int ans = chai(n);
    printf("%d\n",ans);
    return 0;
}
