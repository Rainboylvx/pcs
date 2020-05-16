/*============================================================================
* Title : 865. 魔板 康托展开
* Author: Rainboy
* Time  : 2016-06-10 10:30
* update: 2016-06-10 10:30
* ? Copyright 2016 Rainboy. All Rights Reserved.
*=============================================================================*/
 
/* 
 *  使用 康托展开
 * */
#include <cstdio>
#include <cstring>
#include <queue>
 
using namespace std;
 
queue<int> q;
 
bool vis[45000] ={0};
struct _fa {
    int pre;
    char preOPT;
}fa[45000]= {0};
 
 
 
char str[100] = {'3','1','2','4','5','6','7','8'};
char dst[100];
char tmp[100];
int dstnum;
char lx[100] = {'1','2','3','4','5','6','7','8'};
 
bool isExit[10];
int fac[10] = {1,1,2,6,24,120,720,5040,40320}; //n! 阶乘
 
/*str 字符串,strlen 总长度*/
int encoding(char str[],int len){
    int num =0,i,j;
    for(i=0;i<len;i++){
        int tmp = 0;
        for(j=i+1;j<len;j++)
            /* 有几个数比它小 */
            if(str[j] < str[i]) tmp++; 
        num += tmp*fac[len-i-1];
    }
    return num;
}
 
void decoding(int num,int len,char str[]){
    memset(isExit,0,sizeof(isExit));
    int i,j,cnt;
    for(i=0;i<len;i++){
        cnt = 0;
        int y = num / fac[len-i-1];
        num = num % fac[len-i-1];
        /* y+1 第y+1次数到它,y=0,第一次数到的数就是 */
        for(j=0;j<len;j++){
            if(!isExit[j]) {
                cnt++;
                if(cnt == y+1)
                    break;
            }
        }
        isExit[j] = 1;
        str[i] = lx[j];
    }
}
 
void optA(char sa[],char sb[]){
    /*  倒序 */
    int i;
    for(i=0;i<8;i++){
        sb[7-i] = sa[i];
    }
}
 
 
void optB(char sa[],char sb[]){
    memcpy(sb+1,sa,3);
    memcpy(sb+4,sa+5,3);
    sb[0] = sa[3];
    sb[7] = sa[4];
}
 
void optC(char sa[],char sb[]){
    memcpy(sb,sa,8);
    sb[2] = sa[1];
    sb[1] = sa[6];
    sb[5] = sa[2];
    sb[6] = sa[5];
}
 
char stack[1000];
void final(int father,char opt){
    int cnt =0;
	int count = 0;
    stack[cnt++] = opt;
	count++;
    while( fa[father].pre != 0){
		count++;
          stack[cnt++] = fa[father].preOPT;
          father = fa[father].pre;
    }
    int i;
	if(fa[father].preOPT != 0){
		count++;
		printf("%d\n",count);
		printf("%c",fa[father].preOPT);
	} else 
		printf("%d\n",count);
	
	
    for(i=cnt-1;i>=0;i--)
        printf("%c",stack[i]);
}
 
void bfs(){
    
    while(!q.empty()){
        int front = q.front();q.pop();
        decoding(front,8,tmp);
        int ans;
        optA(tmp,dst);
        ans = encoding(dst,8);
        if( !vis[ans] ){
            if( ans == dstnum){
                final(front,'A');
                return;
            }
            fa[ans].pre = front;
            fa[ans].preOPT = 'A';
            q.push(ans);
            vis[ans] = 1;
        }
 
        optB(tmp,dst);
        ans = encoding(dst,8);
        if( !vis[ans] ){
            if( ans == dstnum){
                final(front,'B');
                return;
            }
            fa[ans].pre = front;
            fa[ans].preOPT = 'B';
            q.push(ans);
            vis[ans] = 1;
        }
    
        optC(tmp,dst);
        ans = encoding(dst,8);
        if( !vis[ans] ){
            if( ans == dstnum){
                final(front,'C');
                return;
            }
            fa[ans].pre = front;
            fa[ans].preOPT = 'C';
            q.push(ans);
            vis[ans] = 1;
        }
    }
 
}
 
int main(){

	int i;
	for(i=0;i<8;i++){
		scanf("%d",&str[i]);
		str[i]+='0';
	}
    dstnum = encoding(str,8);
	if( dstnum == 0){
		printf("0");
		return 0;
	}
    q.push(0);
    bfs();
    return 0;
}
