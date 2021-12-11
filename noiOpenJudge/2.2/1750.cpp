#include <cstdio>
#include <cstring>

char str[10];
int len;

bool visited[300] = {0};

char keng[10];

void qpl(int pos){
    if(pos == len +1){
        // 输出
        printf("%s\n",&keng[1]);
        return ;
    }

    int i;
    for(i=1;i<=len;i++){
        if( visited[ str[i] ] == 0){
            keng[pos] = str[i];
            visited[ str[i] ] = 1;
            qpl(pos+1);
            visited[ str[i] ] = 0;
        }
    }
    
}

int main(){
    scanf("%s",&str[1]);
    len = strlen(&str[1]);
    qpl(1);

    return 0;
}
