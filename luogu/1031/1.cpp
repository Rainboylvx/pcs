#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000];

int main(){
    scanf("%d",&n);
    int i;
    int t = 0;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
        t += a[i];
    }
    int ans = 0;
    t =  t / n;
    for (i=1;i<=n-1;i++){
        if( a[i] != t){
            ans++;
            int x = (a[i]-t);
            a[i+1] += x;
        }
    }
    printf("%d\n",ans);
    return 0;
}
