/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 18:27:53 CST
* problem: uva-1584
*----------------*/
#include <bits/stdc++.h>
using namespace std;
int T;
int n;
char str[105];

/* i开头的字串是不是比j开头的小 */
bool _less(int i,int j){
    int a;
    for(a=0;a<n;a++){
        int ii = (i+a) % n;
        int jj = (j+a) % n;
        if( str[ii] < str[jj])
            return true;
        else if( str[ii] > str[jj])
            return false;
    }
    return false;
}

int main(){
    scanf("%d",&T);
    int i,j;
    for (i=1;i<=T;i++){
        scanf("%s",str);
        n = strlen(str);
        int ans = 0;
        for (j=1;j<n;j++){
            if( _less(j,ans))
                ans = j;
        }
        for(j = 0;j<n;j++){
            int k = (j+ans) % n;
            printf("%c",str[k]);
        }
        printf("\n");
    }
    return 0;
}
