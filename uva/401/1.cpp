/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 02日 星期日 11:01:35 CST
* problem: uva-401
*----------------*/
#include <bits/stdc++.h>
using namespace std;

char rev[] = "A   3  HIL JM O   2TUVWXY5";
char rev_num[] = "O1SE Z  8 ";

char message[][100] = {
 "-- is not a palindrome.",
 "-- is a mirrored string.",
 "-- is a regular palindrome.",
 "-- is a mirrored palindrome."
};

char str[1000];

int ishuiwen(char str[]){
    bool flag1 = 1;
    bool flag2 = 1;
    int len = strlen(str);
    char tmp[100]= {0};
    int i,j;
    for (i=0;i<len;i++){
        if( str[i] >='0'  && str[i] <='9')
            tmp[len-i-1] = rev_num[str[i]-'0'];
        else
            tmp[len-i-1] = rev[str[i]-'A'];
    }
    if( strcmp(str, tmp)!=0)
        flag1 = 0;
    int mid = (len-1) >>1;
    int r = mid+1;
    int l = mid;
    if( ((len-1)&1) == 0)
        l--;
    while(l>=0){
        if( str[l] != str[r]){
            flag2 = 0;
            break;
        }
        l--;
        r++;
    }
    return (flag2 <<1) | flag1;
}

int main(){
    while (scanf("%s",str) != EOF) {
        int ans = ishuiwen(str);
        printf("%s %s\n\n",str,message[ans]);
    }
    return 0;
}
