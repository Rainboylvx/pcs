/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 01:41:42 CST
* problem: uva-340
*----------------*/
#include <bits/stdc++.h>
using namespace std;


int n;
int a[1005];
int b[1005];
int show[10]; //is 出现过
int isright[10];


void init(){
    int i,j,sum;
    int ans = 0;
    int ans2;
    for (i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }

    while(1){
        memset(show,0,sizeof(show));
        memset(isright,0,sizeof(isright));
        sum =0;
        ans = 0;
        ans2 = 0;
        for (i=1;i<=n;i++){
            scanf("%d",&b[i]);
            sum += b[i];
            if(b[i] == a[i]){
                ans++;
            }
            else {
                show[a[i]]++;
            }

        }
        if(sum == 0)
            return ;

        for (i=1;i<=n;i++){
            if(a[i] != b[i] && show[b[i]]){
                ans2++;
                show[b[i]]--;
            }
        }
        printf("    (%d,%d)\n",ans,ans2);
    }
}
int main(){
    int cnt=0;
    while (1) {
        scanf("%d",&n);
        if (n==0) { return 0; }
        cnt++;
        printf("Game %d:\n",cnt);
        init();

    }
    return 0;
}
