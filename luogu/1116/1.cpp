#include <cstdio>
#include <algorithm>
using namespace std;


const int maxn = 1e5+5;
int n;
int a[maxn];

int main(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;++i){
        scanf("%d",&a[i]);
    }
    int cnt=0;
    for(i=1;i<=n;++i){
        for(j=1;j<=n-i;++j){
            if(a[j] > a[j+1]){
                cnt++;
                swap(a[j],a[j+1]);
            }
        }
    }
    printf("%d\n",cnt);
    return 0;
}

