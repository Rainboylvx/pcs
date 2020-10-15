/* author: Rainboy  email: rainboylvx@qq.com  time: 2019年 10月 15日 星期四 20:05:32 CST */
#include <bits/stdc++.h>
using namespace std;

#ifndef DEBUG
#define debug(...)
#endif

const int maxn = 1e5+5;
int n,m;
char word[20],s[1000005];

void _tolower(char s[]){
    int len = strlen(s);
    int i;
    for(i=0;i<len;++i){
        if( s[i] >='A' && s[i] <='Z'){
            s[i] = s[i] - 'A'+'a';
        }
    }
}

int len_s;
char s2[1000000];
int s2_idx,head = 0;
int _next(){
    s2_idx = 0;
    int p = head;
    while(p <= len_s-1 && (s[p] == '\n' || s[p] == ' ') ) p++;
    if( p >= len_s-1) return -1;
    int i;
    for(i = p ; 1 ; i++){
        if( s[i] == '\n' || s[i] == ' ') break;
        s2[s2_idx++] = s[i];
        if( i == len_s -1) break;
    }
    head = i;
    s2[s2_idx] = '\0';
    return p;
}

int main(){
    fgets(word,20,stdin);
    _tolower(word);
    int cnt = 0,pos=-1;
    fgets(s,1000005,stdin);
    word[strlen(word)-1] = '\0';
    len_s = strlen(s);
    _tolower(s);
    while(1){
        int p = _next();
        if( p == -1) break;
        if( strcmp(s2,word) == 0 ){
            cnt++;
            if( pos == -1) pos = p;
        }
    }
    if( cnt == 0)
        printf("%d\n",-1);
    else
        printf("%d %d\n",cnt,pos);

    return 0;
}
