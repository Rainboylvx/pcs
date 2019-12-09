/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019骞?05鏈?11鏃?鏄熸湡鍏?20:52:25 CST
* problem:  luogu-_1067
*----------------*/
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int n;

int a[200];


bool flag_all_0 = true;
int main(){
    scanf("%d",&n);
    int i;
    for (i=1;i<=n+1;i++){
        scanf("%d",&a[i]);
        if( a[i] !=0)
            flag_all_0 = false;
    }

    if( flag_all_0 ){
        printf("0");
        return 0;
    }

    for (i=1;i<=n;i++){
        if( a[i] ==0)
            continue;

        if( a[i]< 0)
            printf("-");
        if(a[i]>0 && i!=1)
            printf("+");
        if( abs(a[i])!=1 ){
            printf("%d",abs(a[i]));
        }

        if( n-i+1 ==1)
            printf("x");
        else
            printf("x^%d",n-i+1);
        // 1 -n
        // 2 n-1
        //
    }

    if(a[n+1] != 0){

        if( a[n+1]< 0)
            printf("-");
        if(a[n+1]>0)
            printf("+");
        printf("%d",abs(a[n+1]));
    }
    return 0;
}