/* author: Rainboy  email: rainboylvx@qq.com  time: 2020年 05月 20日 星期三 19:14:47 CST */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+5;
int n,m;
int _left[5];

char s[9000];

char hua[] = "PKHT";
int dick[300];
char cnt[20][5];
int toInt(char a1,char a2){
    return (a1-'0')*10 + (a2-'0');
}


int main(){
    scanf("%s",s+1);
    int i,j;
    for(i=0;i<=3;++i){
        dick[hua[i]] = i+1;
    }
    int len =strlen(s+1);
    for( i =1;i<=len;i+=3){
        //printf("%c%c%c\n",s[i],s[i+1],s[i+2]);
        int h = dick[s[i]];
        int p = toInt(s[i+1], s[i+2]);
        if( cnt[p][h] == 1){
            printf("GRESKA\n");
            return 0;
        }
        else {
            cnt[p][h] = 1;
        }
    }
    _left[1] = _left[2] = _left[3] = _left[4] = 13;

    for(i=1;i<=4;++i){
        for(j=1;j<=13;j++){
            _left[i] -= cnt[j][i];
        }
    }
    printf("%d ",_left[1]);
    printf("%d ",_left[2]);
    printf("%d ",_left[3]);
    printf("%d",_left[4]);


    return 0;
}
