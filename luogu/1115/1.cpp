#include <cstdio>
#include <algorithm>
using namespace std;


#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)

const int maxn = 5e5+5;
#define inf3f 0x3f3f3f3f
int n,m;

int a[maxn];

int max_range(int l,int r){
    if( l > r) swap(l, r);
    int ans = a[l];
    int i,j,m = a[l];
    For(i,l+1,r){
        if( m < 0){
            m = a[i];
        }
        else {
            m += a[i];
        }
        ans = ans > m ? ans : m;
    }
    return ans;
}

int main(){
    scanf("%d",&n);
    int i,j;
    For(i,1,n){
        scanf("%d",&a[i]);
    }
    printf("%d\n",max_range(1,n));
    return 0;
}

