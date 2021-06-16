#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n;
char _long[1000000];
char str[21][1000];
char _begin[10];
int vis[25] = {0};

/* 核心函数:
 *   - a 的尾巴和 b的开头是不是可以拼接,
 *   len 相同的长度
 *
 * */
bool is_ok(char a[],char b[],int &len){
    int la = strlen(a);
    int lb = strlen(b);
    int l = min(la,lb);
    int i;
    len = 0;
    for( i = 1;i<l;i++){
        if( strncmp(&a[la-i],b,i) == 0){
            len = i;
            break;
        }
    }
    if( len == 0)
        return false;
    return true;
}


// a末尾与b开头的len个字符相同,拼接在在一起
void pinjien(char a[],char b[],int len){
    int la = strlen(a);
    int lb = strlen(b);
    int i;
    for(i=len;i<lb;i++)
        a[la++] = b[i];
    a[la] = '\0';
}

/* dfs搜索 */
int ans;
void dfs(){
    int len = strlen(_long);
    if( ans < len){
        ans = len;
    }
    
    int i;
    int l;
    for(i=1;i<=n;i++){
        if(vis[i]>0 && is_ok(_long,str[i],l)){
            pinjien(_long,str[i],l);
            vis[i]--;
            dfs();
            _long[len] = '\0';
            vis[i]++;
        }
    }
}

int main(){
    scanf("%d",&n);
    int i,j;
    for (i=1;i<=n;i++){
        scanf("%s",str[i]);
        vis[i] = 2;
    }
    scanf("%s",_begin);
    int _ans = 0;

    for(i=1;i<=n;i++){
        if( _begin[0] == str[i][0]){
            ans = 0;
            strcpy(_long,str[i]);
            for(j=1;j<=n;j++)
                vis[j] = 2;
            vis[i] = 1;
            dfs();
            _ans = max(ans,_ans);
        }
    }
    printf("%d\n",_ans);
    return 0;
}
