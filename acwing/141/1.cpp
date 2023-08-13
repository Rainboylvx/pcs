/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-21 19:01:20
*----------------*/
#define maxn 1000005
#define maxe 2000005
#include <bits/stdc++.h>
#include "algo/kmp.hpp"
using namespace std;
typedef long long ll;

//////// 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)

#ifdef DEBUG
#include "utils/clock.hpp"
#include "utils/log.hpp"
#else
#define log(...)
#endif


int n,m;
/* 定义全局变量 */
char a[maxn]; //常用的一个数组

int init()
{
    scanf("%d",&n);
    if( n > 0) scanf("%s",a+1);
    return n;
}
KMP mykmp;

int main(){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
#ifdef DEBUG
    Clock t("main time");
#endif
    
    int idx = 0;
    while( init()) {
        mykmp.set_a(a);
        mykmp.len_a = strlen(a+1);
        mykmp.calc_a_next();
        printf("Test case #%d\n",++idx);
        F3( i , 2 , n){
            if( mykmp.next[i] != 0 && i % ( i - mykmp.next[i]) == 0)
            {
                printf("%d %d\n",i,i / (i-mykmp.next[i]));
            }
        }
        printf("\n");
    }
    
    return 0;
}
