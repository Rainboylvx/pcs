/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 03日 星期一 19:35:24 CST
* problem: uva-1586
*----------------*/
#include <bits/stdc++.h>
using namespace std;
char str[100];
int n;
double g[500];

/* ========== 快读 ========== */
void in(int &a,int i){
    a = 0;
    char ch = str[++i];
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = str[++i]; }
}
/* ========== 快读 END ========== */

void _do(){
    scanf("%s",str+1);
    int i,k;
    int len = strlen(str+1);
    double total = 0;
    for (i=1;i<=len;i++){
        if(str[i] >='A' &&str[i] <='Z'){
            k = i;
            int num;
            in(num,k);
            if(!num) num =1;
            total += num*g[str[i]];
        }
    }

    printf("%0.3lf\n",total);
}

int main(){
    g['C'] = 12.01;
    g['H'] = 1.008;
    g['O'] = 16.00;
    g['N'] = 14.01;
    scanf("%d",&n);
    while(n--){
        _do();
    }
    return 0;
}
