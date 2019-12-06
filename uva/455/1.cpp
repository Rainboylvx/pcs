/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 04日 星期二 00:48:02 CST
* problem: uva-455
*----------------*/
#include <bits/stdc++.h>
using namespace std;
int n;

char str[105];

bool isequ(int l,int strl){
    int i;
    for(i=l+1;i<=strl;i+=l){
        if(strncmp(str+1,str+i,l) !=0)
            return 0;
    }
    return 1;
}

int _do(){
    scanf("%s",str+1);
    int len = strlen(str+1);
    int i,j;
    for (i=1;i<=len>>1;i++){
        if(len % i !=0)
            continue;
        if(isequ(i,len)){
            return i;
        }
    }
    return len;
}

int main(){
    scanf("%d",&n);
    int i;
    for (i=1;i<n;i++){
        int ans = _do();
        printf("%d\n\n",ans);
    }
    int ans = _do();
    printf("%d\n",ans);
    return 0;
}
