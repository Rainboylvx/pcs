/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 04日 星期二 15:03:39 CST
* problem: uva-1588
*----------------*/
#include <bits/stdc++.h>
using namespace std;

char s1[500];
char s2[500];

bool is_cop(char s1[],char s2[]){
    int l1 = strlen(s1);
    int l2 = strlen(s2);
    int _m = min(l1,l2);
    int i;
    for (i=0;i<_m;i++){
        if((s1[i]-'0')+(s2[i]-'0') >3)
            return 0;
    }
    return 1;
}

bool init(){
    if(scanf("%s",s1+1) == EOF)
        return 1;
    scanf("%s",s2+1);
    int l1 = strlen(s1+1);
    int l2 = strlen(s2+1);
    int _min = l1+l2;
    /* 左 */
    int i;
    for(i=l1;i>=1;i--){
        if( is_cop(s1+i,s2+1)){
            int ch = min(l1-i+1,l2);
            _min = min(_min,l1+l2-ch);
        }
    }
    
    for(i=1;i<=l2;i++){
        if( is_cop(s1+1,s2+i)){
            int ch = min(l1,l2-i+1);
            _min = min(_min,l1+l2-ch);
        }
    }
    printf("%d\n",_min);

    return 0;
}

int main(){
    while(1){
        if(init())
            break;
    }
    return 0;
}
