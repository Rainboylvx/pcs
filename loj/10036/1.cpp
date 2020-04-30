/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 09 Apr 2020 09:36:49 PM CST
* problem: loj-10036
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 4e5+5;
const int maxe = 1e6+5;
int n,m;

char str[maxn];
/* ======= 全局变量 END =======*/

namespace hashmap {
    typedef unsigned long long ull;
    const int hash_mod= 10007;
    const int size = 30005;
    const ull seed = 2333;
    int cnt,head[hash_mod],next[size];
    ull p[maxn] = {1};
    ull hashmap[size];
    inline void hashmap_init(int len = maxn){ 
        //cnt = 0; memset(head,-1,sizeof(head));
        p[0] = 1;
        for( int i = 1;i<=len;i++) 
            p[i] = p[i-1]*seed;
    }
    ull hash(char s[]){
        ull len = strlen(s),sum = 0; //得到长度
        for(ull i=0;i<len;i++) sum = sum*seed + (ull)(s[i]);
        return sum;
    }
    //插入
    int insert(ull val){
        int h = val % hash_mod;
        for( int i = head[h]; i!= -1 ;i = next[i]){
            if( val == hashmap[i]){ //已经存在
                return i;
            }
        }
        // 不存在
        hashmap[++cnt] = val;
        next[cnt] = head[h];
        head[h] = cnt;
        return cnt;
    }
    //查找
    int find(ull val){
        int h = val % hash_mod;
        for( int i = head[h]; i!= -1 ;i = next[i]){
            if( val == hashmap[i]){ //已经存在
                return i;
            }
        }
        // 不存在
        return 0;
    }
}
using namespace hashmap;

ull sum[maxn];
void init(){
    sum[0] = 0;
    int len = strlen(str+1);
    int i,j;
    For(i,1,len){
        sum[i] = sum[i-1]*seed + (ull)str[i];
    }

    int n = len;
    for( i =1;i<=n;i++){
        ull s1 = sum[i];
        ull s2 = sum[n] - sum[n-i]*p[i];
        if( s1 == s2){
            printf("%d ",i);
        }
    }
    printf("\n");
}


int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    hashmap_init(400001);
    while ( scanf("%s",str+1) != EOF) {
        init();
    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
