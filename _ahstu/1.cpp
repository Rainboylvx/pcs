/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 17日 星期五 16:29:59 CST
* problem: aoj-_id 
*----------------*/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int a[100005];
int pre[100005];

int chai(int n){
    int cnt=0;
    while(n){
        int t = n % 10;
        n = n /10;
        if( t == 7)
            cnt++;
    }
    return cnt;
}

int can(int n){
    if( n % 7)
        return 0;
    return can(n / 7)+1;
}

int main(){
    int i;
    a[7] = 2;
    pre[7] =2;
    for(i=8;i<=100000;i++){
        pre[i] = pre[i-1] + chai(i) +can(i);
        //if( i>=47 && i <=50){
            //printf("%d ",chai(i) +can(i));
        //}
    }
        //printf("\n");

    int T;
    scanf("%d",&T);
    int t1,t2;
    while(T--){
        scanf("%d%d",&t1,&t2);
        printf("%d\n",pre[t2]-pre[t1-1]);
    }
    return 0;
}
