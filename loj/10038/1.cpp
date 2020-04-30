/*-----------------
* author: Rainboy
* email: rainboylvx@qq.com
* time: Thu 16 Apr 2020 02:45:59 PM CST
* problem: loj-10038
*----------------*/
#include <bits/stdc++.h>
#define For(i,start,end) for(i = start ;i <= end; ++i)
#define Rof(i,start,end) for(i = start ;i >= end; --i)
typedef long long ll;
using namespace std;

/* ======= 全局变量 =======*/
const int maxn = 1e6+5;
const int maxe = 1e6+5;
int n,m;
char s[maxn];

/* ======= 全局变量 END =======*/

namespace hashmap {
    typedef unsigned long long ull;
    const ull seed = 2333;
    ull p[maxn],sum[maxn];
    inline void hashmap_init(int len = maxn){ 
        p[0] = 1;
        for( int i = 1;i<=len;i++) p[i] = p[i-1]*seed;
    }

    //得到前缀的hash
    void get_hash(char s[],int len){
        sum[0] = 0;
        for(int i=1;i<=n;i++) sum[i] = sum[i-1] *seed +(ull)(s[i]-'a'+1);
    }

    //得到区间的hash
    ull get_range(int l,int r){
        return sum[r] -sum[l-1]*p[r-l+1];
    }
}
using namespace hashmap;


int tot=0;
int prime[maxn];
int _min_prime[maxn]; // 每个数的最小质因数
void euler_prime(int len){ //线性欧拉筛
    int i,j;
    for(i=2;i<=len;++i){
        //没有被筛掉,是素数
        if( prime[i] == 0) prime[++tot] = _min_prime[i] = i;
        for(j=1;j<=tot && prime[j] *i <=len;++j){
            prime[i*prime[j]] =1;
            _min_prime[i*prime[j]] = prime[j];
            if( i % prime[j] == 0) break;
        }
    }
}

void init(){
    scanf("%d",&n);
    scanf("%s",s+1);
    scanf("%d",&m);
}



int main(){
    clock_t program_start_clock = clock(); //开始记时
    //===================
    init();
    hashmap_init(n);
    get_hash(s, n);
    euler_prime(n);
    int x,y;
    int i;
    For(i,1,m){
        scanf("%d%d",&x,&y);
        if( x == y) {
            printf("%d\n",1);
            continue;
        }
        int len = y-x+1;
        vector<int> v; //存质因子
        while( len >1){
            v.push_back(_min_prime[len]);
            len /= _min_prime[len];
        }

        len = y-x+1;
        for (const auto& e : v) {
            int t = len / e;
            if( get_range( x, y-t) == get_range(x+t, y)) 
                //可以去除
                len = t;
        }
        printf("%d\n",len);

    }

    //=================== 
    fprintf(stderr,"\n Total Time: %lf ms",double(clock()-program_start_clock)/(CLOCKS_PER_SEC / 1000));
    return 0;
}
