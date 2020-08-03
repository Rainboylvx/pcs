#include <bits/stdc++.h>
using namespace std;

char s1[500],s2[500];
char out[1000];

int l1,l2;
int cnt = 0;
bool vis[500];
int get_val(){
    int i,j;
    int ans = 0;
    for(i=1;i<=l1+l2;i++){
        char c = out[i];
        if( !vis[c]){
            vis[c] = 1;
            for(j=l1+l2;j>=1;j--){
                if( out[j] == out[i]){
                    ans += j-i;
                    break;
                }
            }
        }
    }
    return ans;
}

int _min = 0x7f7f7f7f;
int flag = 0;

void dfs(int dep,int x,int y){
    if( dep == l1+l2+1){
        /* 输出 */
        out[l1+l2+1] = '\0';
        memset(vis,0,sizeof(vis));
        int ans = get_val();
        if( _min > ans)
            _min = ans;
        if( !flag){
            printf("%d : %s ",++cnt,out+1);
            printf("%d\n",ans);
        }
        else if( ans == _min)
            printf("%s\n",out+1);
        return ;
    }

    if( x <= l1){
        out[dep] = s1[x];
        dfs(dep+1,x+1,y);
    }

    if( y <= l2){
        out[dep] = s2[y];
        dfs(dep+1,x,y+1);
    }
}

void init(){
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    l1 = strlen(s1+1);
    l2 = strlen(s2+1);
}
int main(){
    char s[] = "YRRGGBBYB";
    int l = strlen(s);
    l1=l;
    memcpy(out+1,s,sizeof(s));
    printf("%d\n",get_val());
    return 0;
}
