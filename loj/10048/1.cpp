/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: 2019年 12月 17日 星期二 08:56:48 CST
* problem:  loj-10048
*----------------*/
#include <bits/stdc++.h> 
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
int la,lb;
char a[maxn],b[maxn];
int nxt[maxn];
int mem[maxn];
int pre[maxn]; //一个伪的链表
bool del_flag[maxn];

/* ======= 全局变量 END =======*/



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    int i,j,k;
    scanf("%s",a+1);
    scanf("%s",b+1);
    la = strlen(a+1);
    lb = strlen(b+1);

    // get nxt
    j=0,nxt[1] = 0;
    For(i,2,lb){
        while(j && b[j+1] != b[i]) j = nxt[j];
        if( b[j+1] == b[i]) j++;
        nxt[i] = j;
    }

    // kmp 匹配
    j=0;
    int pre_i = 0;
    For(i,1,la){
        pre[i] = pre_i;
        while(j && b[j+1] != a[i]) j =nxt[j];
        if(b[j+1] == a[i]) j++;
        mem[i] = j; // a[i] 和b里的那个元素匹配
        if( j == lb){
            //删除
            int k,t = i;
            for(k=1;k<=lb;k++){
                del_flag[t] = 1;
                t = pre[t];
                j = mem[t];
            }
            pre_i = t;
        }
        else
            pre_i = i;
    }

    For(i,1,la){
        if( !del_flag[i]) 
            printf("%c",a[i]);
    }
    printf("\n");


    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
} 
