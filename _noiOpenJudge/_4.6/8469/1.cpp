#include <bits/stdc++.h>
using namespace std;

char s1[100];
char s2[100];
char aim[100];
int len;

void init(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    len = strlen(s1+1);
}

void opt(int i){
    aim[i] = aim[i] == '0' ? '1': '0';
    aim[i-1] = aim[i-1] == '0' ? '1': '0';
    aim[i+1] = aim[i+1] == '0' ? '1': '0';
}

int main(){
    init();
    int i,j,k;

    int cnt = 0;
    memcpy(aim,s1,sizeof(aim));

    /* 不按 */
    for(i=2;i<=len;i++){
        if( aim[i-1] != s2[i-1]){
            cnt++;
            opt(i);
        }
    }
    if( aim[len] == s2[len])
    return 0;
}
