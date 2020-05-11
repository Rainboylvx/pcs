#include <cstdio>
#include <cstring>

char s[300]; //数字
int k;//要删除几位

int main(){
    scanf("%s",s);

    scanf("%d",&k);

    int cnt;
    int i,j;
    for(cnt  =1;cnt <=k;cnt++){
        int len = strlen(s);
        for(i=0;i<len;i++){
            if(s[i] > s[i+1]){
                for(j=i;j<len;j++) //往前移
                    s[j] =s[j+1];
                break;
            }
        }
    }

    int len = strlen(s);
    int first_not_zero;
    for(i=0;i<len;i++){
        if( s[i] !='0'){
            first_not_zero = i;
            break;
        }
    }
    if( i == len) 
        printf("0");
    else 
        printf("%s",&s[first_not_zero]);
    return 0;
}

