/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 05月 22日 星期三 21:58:09 CST
* problem: uva-11584
*----------------*/
#include <bits/stdc++.h>
using namespace std;

int n;
char str[1005];
bool s[1005][1005];
int f[1005];
int len;

/* [x,y] 是否是回文 */
bool is_huiwen(int x,int y){
    if( x == y) return 1;
    int mid = (x+y) >> 1;
    int len = y-x+1;
    int i,j=mid+1;
    if( len & 1)
        i = mid-1;
    else 
        i = mid;

    while(i >= x){
        if(str[i] != str[j])
            return 0;
        i--,j++;
    }

    return 1;
}
void init(){
    scanf("%s",str+1);
    memset(f,0x3f,sizeof(f));
    memset(s,0,sizeof(s));
    len = strlen(str+1);
    int i,j;
    for (i=1;i<=len;i++){
        for (j=i;j<=len;j++){
            s[i][j] = is_huiwen(i,j);
        }
    }
}
void dp(){
    int i,j;
    f[0]  = 0;
    for (i=1;i<=len;i++){
        for(j=0;j<i;j++){
            if(s[j+1][i])
                f[i] = min(f[i],f[j]+1);
        }
    }
    printf("%d\n",f[len]);
}
int main(){
    scanf("%d",&n);
    int i;
    for (i=1;i<=n;i++){
        init();
        dp();
    }
    return 0;
}
