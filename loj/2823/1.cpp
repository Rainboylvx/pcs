/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 09 Apr 2020 10:40:38 PM CST
* problem: loj-2823
*----------------*/
#include <cstdio>
#include <string>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 2e6+5;
int n,m;

char str[maxn];
/* ======= 全局变量 END =======*/
namespace hashmap {
    typedef unsigned long long ull;
    const ull seed = 2333;
    ull p[maxn];
    inline void hashmap_init(int len = maxn){ 
        for( int i = 1;i<=len;i++) p[i] = p[i-1]*seed;
    }
}
using namespace hashmap;
ull sum[maxn];

ull get_range(int x,int y){
    if( x > y ) return 0;
    return sum[y] - sum[x-1]*p[y-x+1];
}
ull get_left(int pos){
    int mid = n>>1;
    if( pos >=mid+1) return sum[mid];
    return get_range(1, pos-1)*p[mid-pos+1] + get_range(pos+1, mid+1);
}

ull get_right(int pos){
    int mid = n >>1;
    if( pos <=mid+1) return get_range(mid+2, n);
    return get_range(mid+1, pos-1)*p[2*mid-pos+1] + get_range(pos+1, n);
}


int main(){
    p[0] = 1;
    scanf("%d",&n);
    if( n % 2 == 0){
        printf("NOT POSSIBLE");
        return 0;
    }
    scanf("%s",str+1);
    hashmap_init(n);
    int i,j;
    sum[0] = 0;
    For(i,1,n){
        sum[i] = sum[i-1]*seed + (ull)(str[i]-'A'+1);
    }
    int ans=0,ans_p;
    int mid = n>>1;
    ull ans_num;
    for(int i=1;i<=n;i++){ //枚举是哪个位置是新插入的字符
        ull left = get_left(i);
        ull right= get_right(i);
        if(left == right){
            ans_p = i;
            if( ++ans > 1){
                if( left != ans_num) {
                    printf("NOT UNIQUE");
                    return 0;
                }
            }
            else if( ans == 1 ) ans_num = left;
        }
    }
    if( ans == 0){
        printf("NOT POSSIBLE");
    }
    else {
        for(i =1;i<=(n>>1);i++){
            if( i != ans_p)
                printf("%c",str[i]);
        }
        if( ans_p <= (n>>1))
            printf("%c",str[(n>>1)+1]);
    }
    printf("\n");
    return 0;
}
