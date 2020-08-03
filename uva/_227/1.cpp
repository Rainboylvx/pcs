/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 06月 04日 星期二 12:56:18 CST
* problem: uva-227
*----------------*/
#include <bits/stdc++.h>
using namespace std;

char all_char[1000000];
char cmd_line[1000000];
int len,idx = 0;
char _m[10][100];

char get_c(){ return all_char[idx++]; }
bool notempty() { return idx < len;};

void init(){
    char c,i=0;
    while( scanf("%c",&c) !=EOF){
        if( c != '\n')
            all_char[i++] = c;
    }
    len = i;
}

bool in_map(int x,int y){
    if(x >=1 && x<=5 && y>=1 && y <=5)
        return 1;
    return 0;
}

bool _swap(char opt,int &x,int &y){
    int nx=x,ny=y;
    if( opt == 'A'){
        nx--;
        if( !in_map(nx,ny)) return 0;
    }
    else if( opt == 'B'){
        nx++;
        if( !in_map(nx,ny)) return 0;
    }
    else if( opt == 'L'){
        ny--;
        if( !in_map(nx,ny)) return 0;
    }
    else if( opt == 'R'){
        ny++;
        if( !in_map(nx,ny)) return 0;
    }
    swap(_m[x][y],_m[nx][ny]);
    x = nx;
    y = ny;
    return true;
}
void pr_m(){
    int i;
    for (i=1;i<=5;i++){
        printf("%s\n",_m[i]+1);
    }
    printf("\n");
}

void _do(){
    int x,y;
    int i,j;
    for (i=1;i<=5;i++){
        for (j=1;j<=5;j++){
            if( _m[i][j] == ' '){
                x = i;
                y =j;
                break;
            }
        }
    }
    j = 0;
    //printf("%s\n",cmd_line);
    //pr_m();

    while(1){
        char c =  cmd_line[j++];
        if( c== '\0') break;
        if( !_swap(c,x,y)){
            printf("This puzzle has no final configuration.\n");
            return;
        }
    }
    for (i=1;i<=5;i++){
        for (j=1;j<=5;j++){
            printf("%c ",_m[i][j]);
        }
        printf("\n");
    }
}


int main(){
    init();
    int i,j;
    int cnt = 1;
    while( notempty()){

        if( all_char[idx] == 'Z')
            return 0;
        printf("Puzzle #%d:\n",cnt++);
        for(i=1;i<=5;i++)
            for (j=1;j<=5;j++){
                _m[i][j] = get_c();
            }
        j = 0;
        while(1){
            cmd_line[j++] = get_c();
            if( cmd_line[j-1] == '0'){
                cmd_line[j-1] = '\0';
                break;
            }
        }
        _do();
        printf("\n");
    }
    return 0;
}
