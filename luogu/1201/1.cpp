#include <cstdio>
#include <cstring>


char name[20][100]; //存人的名字
int y[20] = {0};
int song[20] = {0}; //送出的钱
int shou[20] = {0}; //收到的钱
int n; //多少人

/* 返回输入的名字是第几个人 */
int seach_people(char *name1){
    int i;
    for(i=1;i<=n;i++)
        if(strcmp(name1,&name[i][0]) == 0){
            return i;
        }
    return -1;
}


int main(){
    int i;
    scanf("%d",&n);

    for(i=1;i<=n;i++) //读取人的名字
        scanf("%s",&name[i][0]);

    int qian,ren;
    char tmp_name[100];

    int j;

    for(j=1;j<=n;j++){
        scanf("%s",tmp_name); //读入 发钱的人
        int idx = seach_people(tmp_name);

        scanf("%d%d",&qian,&ren);

        if( ren == 0) continue; // 避免出错

        y[idx] = qian;
        song[idx] = qian/ren *ren; // 送出的钱

        for(i=1;i<=ren;i++){
            scanf("%s",tmp_name);
            idx = seach_people(tmp_name);
            shou[idx] += qian/ren;
        }
    }

    for(i=1;i<=n;i++){
        printf("%s %d\n",&name[i][0],shou[i] - song[i]);
    }
    return 0;
}


