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

#define mm 10010

int a[mm];
int b[mm] = {0};
int n;
int cnt = 0;

int main(){
    scanf("%d",&n);
    int i,j,k,l;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n ==1 ){
        if( a[1] <=1) printf("1");
        else printf("0");
        return 0;

    }

    if(n ==2){
        for(i=0;i<2;i++){
            b[1] = i;
            for(j=0;j<2;j++){
                b[2] =j;
                if( b[1]+b[2] == a[1] && b[1]+b[2] == a[2])
                    cnt++;
            }
        }
        printf("%d",cnt);
        return 0;
    }

    if( n== 3){
    for(i=0;i<2;i++){
        b[1] = i;
        for(j=0;j<2;j++){
            b[2] = j;
            for(k=0;k<2;k++){
                b[3]= k;
                if(b[1]+b[2] == a[1] && b[1]+b[2]+b[3] == a[2] && b[2]+b[3] == a[3])
                    cnt++;
            }
        }
    }
    printf("%d",cnt);
    return 0;

    }

    for(i=0;i<2;i++){
        b[1] = i;
        for(j=0;j<2;j++){
            b[2] = j;
            for(k=0;k<2;k++){
                b[3]= k;
                b[n+1] = 0;
                if(b[1]+b[2] == a[1] && b[1]+b[2]+b[3] == a[2]){   //有可能
                    for(l=3;l<=n;l++){
                        int t = b[l-1]+b[l];
                        if( t == a[l])   
                            b[l+1] = 0;
                        else if( t+1 == a[l] ) 
                            b[l+1] = 1;
                        else break;  //不可能
                    }
                    if(b[n+1] == 0 && l == n+1)
                        cnt++;
                }
            }
        }
    }

    printf("%d",cnt);

    return 0;
}
