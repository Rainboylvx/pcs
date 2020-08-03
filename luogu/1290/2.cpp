// 搜索
//
#include <cstdio>
#include <algorithm>

using namespace std;

bool dfs(int a,int b){
    if( a % b == 0){ return 1; }
    int i;
    int S = a / b;
    for(i=1;i<=S;++i){
        int mi = min(b, a-i*b);
        int ma = max(b, a-i*b );
        if( dfs(ma,mi) == 0){ //如果有一个输了,那自己就胜利了
            return 1;
        }
    }
    return 0;
}

int main(){
    int a, b;
    scanf("%d%d",&a,&b);
    if( a < b) swap(a,b);
    if( dfs(a,b))
        printf("Stan wins\n");
    else
        printf("Ollie wins\n");
    return 0;
}

