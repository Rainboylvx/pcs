#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

int n;
const int maxn = 1e4+5;
pair<int,int> p[maxn];
long long sum[maxn] = {0};
int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d",&p[i].first);
        p[i].second = i;
    }
    sort(p+1,p+1+n);
    for(i=1;i<=n;++i){
        sum[i] = sum[i-1] + p[i].first; //前缀和
        printf("%d ",p[i].second);
    }
    printf("\n");
    long long s = 0;
    for(i=2;i<=n;++i){
        s += (sum[i-1]);
    }
    printf("%0.2lf\n",s*1.0/n);
    return 0;
}



