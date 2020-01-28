#include <bits/stdc++.h>
using namespace std;

vector<int>  t,a;
int n;
const int maxn = 1e3+5;
int f[maxn][maxn];

void init(){
    scanf("%d",&n);
    int i;
    int T;
    for(i=1;i<=n;i++){
        scanf("%d",&T);
        t.push_back(T);
    }
    for(i=1;i<=n;i++){
        scanf("%d",&T);
        a.push_back(T);
    }
}
int main(){
    init();
    int i,j;

    for(i=n;i>=1;i--){
        for(j=100;j>=1;j--){
            f[i][j]
        }
    }
    return 0;
}
