/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2020年 05月 26日 星期二 17:16:34 CST
* problem: loj-10150
*----------------*/
#include <bits/stdc++.h>
using namespace std;

char str[1000];
int f[105][105];
int main(){
    scanf("%s",str+1);
    int len = strlen(str+1);
    int i,j,k;
    int L; //长度
    for(i=1;i<=len;++i) {
        f[i][i] = 1;
        for(j=i+1;j<=len;j++)
            f[i][j] = 0x3f3f3f3f;
    }
    for(L=2;L<=len;++L){
        for(i=1;i+L-1<=len;++i){ //枚举起点
            for(k=i;k+1<=i+L-1;k++){
                j = i+L-1;
                f[i][j] = min(
                            f[i][j],
                            f[i][k]+f[k+1][j]
                        );
                if( (str[i] == '(' && str[j] ==')') ||  (str[i] == '[' && str[j] ==']') ){
                    f[i][j] = min(f[i][j],f[i+1][j-1]);
                }
            }
        }
    }
    printf("%d\n",f[1][len]);

    return 0;
}
