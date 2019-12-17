#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;


int n;
const int maxn = 1e5+5;
int a[maxn] = {0,1};
bool iddfs(int dep,int maxd){
    if( dep > maxd){
        if( a[dep-1] == n) return 1;
        return 0;
    }

    int i,j;
    for(i=dep-1;i>=1;i--)
        for(j=i;j>=1;j--){
            int b = a[j]+a[i];
            if( b <= n && b > a[dep-1]){
                a[dep] = b;
                if( iddfs(dep+1, maxd))
                    return 1;
            }
        }
    return 0;
}
void work(){
    if( n == 1){ printf("%d\n",1); return ; }
    int i,j;
    for( i =2; ;i++){
        if( iddfs(2, i)) {
            for(j=1;j<i;j++){
                printf("%d ",a[j]);
            }
            printf("%d",a[j]);
            printf("\n");
            break;
        }
    }
}
int main(){
    while (scanf("%d",&n) != EOF  && n !=0) {
        work();
    }
    return 0;
}

