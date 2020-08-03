/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 22:18:57 CST
* problem: uva-1225
*----------------*/
#include <bits/stdc++.h>
using namespace std;

int n;
int count[10];
int pre[10005][10];

void init(){
    int i,t;
    for (i=1;i<=10000;i++){
        t =i;
        memcpy(pre[i],pre[i-1],sizeof(pre[0]));
        while(t){
            int g = t % 10;
            t /=10;
            pre[i][g]++;
        }
    }
}

int main(){
    scanf("%d",&n);
    init();
    int i;
    int t;
    while(n--){
        scanf("%d",&t);
        for (i=0;i<9;i++){
            printf("%d ",pre[t][i]);
        }
        printf("%d\n",pre[t][9]);
    }
    return 0;
}
