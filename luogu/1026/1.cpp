#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



int len;
char str[400];
int f[300][300] = {0}; // f[i][j] 表示[i,j]范围内的单词数量
int g[300][300] = {0};//g[i][k] 表示 前i个字符 分成k份的单词数量
char word[10][8];
int n;
int p,k;

void init(){
    int i,j;
    scanf("%d%d",&p,&k);

    char tmp[25];
    for (i=1;i<=p;i++){
        scanf("%s",tmp);
        int idx = (i-1)*20;
        //strcpy(&str[idx+1],tmp);
        int j = 0;
        for(int i = idx+1 ;i<=idx+20 ;i++ )
            str[i] = tmp[j++];
    }
    // len = strlen(str+1);
    len = p *20;
    scanf("%d",&n);
    for (i=1;i<=n;i++){
        scanf("%s",&word[i][1]);
        word[i][0] = strlen(&word[i][1]);
    }
}
/* 比较是否一样 */
bool cmp(char m[],char s[],int l){
    char tmp[205];
    strncpy(tmp,m,l);
    tmp[l] = '\0';
    if( strncmp(tmp,s+1,s[0]) == 0)
        return true;
    return false;
}

void dp_init(){
    int i,j,k,l;
    for(i=len;i>0;i--){ //选定一个结尾
        for(j=i;j>0;j--){ //从结尾i往前走
            for(k=1;k<=n;k++){ //枚举单词
                if( cmp(&str[j],word[k],i-j+1)){
                    f[j][i] = f[j+1][i] +1;
                    break;
                }
                else
                    f[j][i] = f[j+1][i];
            }
        }
    }
}

/* 
 * g[i][k] = max{f[j+1][i] + g[j][k-1]}
 * g[i][1] = f[1][i] 边界
 * */
void dp(){
    int i,j,kk;

    for(i=1;i<=len;i++)
        g[i][1] = f[1][i];
    for(kk=2;kk<=k;kk++){
        for(i=kk;i<=len;i++){ //枚举前i个字符
            for(j=kk-1;j<i;j++)
                g[i][kk] = max(g[i][kk], f[j+1][i] + g[j][kk-1]);
        }
    }

}

int main(){
    init();
    dp_init();
    dp();
    printf("%d\n",g[len][k]);
    return 0;
}

