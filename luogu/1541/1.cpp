#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

#define N 41

int max(int a,int b){
    if( a> b)
        return a;
    return b;
}

int f[N][N][N][N] = {0};
int a[400];
int pai[5] = {0};
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int i,j,k,l;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    for (i=1;i<=m;i++){
        int t;
        scanf("%d",&t);
        pai[t]++;
    }

    f[0][0][0][0] = a[1]; //边界

    for (i=0;i<=pai[1];i++){
        for (j=0;j<=pai[2];j++){
            for (k=0;k<=pai[3];k++){
                for (l=0;l<=pai[4];l++){

                    int &t = f[i][j][k][l];
                    int bijia =a[i+j*2+k*3+l*4+1];
                    if( l > 0)
                        t = max( t,f[i][j][k][l-1]+bijia);

                    if( i > 0)
                        t = max( t,f[i-1][j][k][l]+bijia);
                    if( j > 0)
                        t = max( t,f[i][j-1][k][l]+bijia);
                    if( k > 0)
                        t = max( t,f[i][j][k-1][l]+bijia);

                }
            }
        }
    }

    printf("%d", f[ pai[1] ][ pai[2] ][ pai[3] ][ pai[4] ]);
    return 0;
}
