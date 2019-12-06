/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 17:18:38 CST
* problem: uva-1583
*----------------*/
#include <bits/stdc++.h>
using namespace std;
#define maxn 200005
int n;
int a[maxn] = {0};


void init(){
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=100000;i++){
        int sum = i;
        int t = i;
        while( t){
            sum += t % 10;
             t /= 10;
        }

        if( !a[sum])
            a[sum] = i;
    }
    for (i=1;i<=n;i++){
        scanf("%d",&j);
        printf("%d\n",a[j]);
    }
}

int main(){
    init();
    return 0;
}
