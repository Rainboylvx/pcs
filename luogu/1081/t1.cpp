/* author: Rainboy email: rainboylvx@qq.com
 *
 * time: 2023年 06月 13日 星期二 22:06:22 CST */
/**
 * 
 * 20% 把
 */
#include <bits/stdc++.h>
// #include "utils/debug.hpp"
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量
                                     //


const int INF = 0x7f7f7f7f;
int n,m;
/* 定义全局变量 */
int a[maxn];
int next_1[maxn]; // next_1[i] i后 第一小的
int next_2[maxn]; // next_2[i] i后 第二小的

int _abs_sub(int a,int b)
{
    int t= a - b;
    if( t < 0 ) return -t;
    return t;
}


// 得到第一小,第二小
void get_next_() {
    for(int i=1;i<=n;++i){
        int t1;// = next_1[i];
        int t2;// = next_2[i];
        t1 =t2 = INF;
        for(int j=i+1;j<=n;++j){
            int dis = _abs_sub(a[i], a[j]);
            if( t1 > dis  //当前更小
                || (t1 == dis && a[j] < a[next_1[i]]) // 或者相等,但当前海拔低
                    ) {
                // 是否把当前的第一 下放给第二
                if( t2 > t1) {
                    t2 = t1;
                    next_2[i] = next_1[i];
                }
                else if( t2 == t1 && a[next_1[i]] > a[next_2[i]] ) {
                    next_2[i] = next_1[i];
                }

                t1 = dis;
                next_1[i] = j;

            }
            else if ( 
                    t2 > dis 
                    || t2 == dis && a[next_2[i]] > a[j] 
                    )
            {
                next_2[i] = j;
                t2 = dis;
            }
        }
        // dbg(i,next_1[i],next_2[i]);
        // tdbg(i,next_1[i],next_2[i]);
    }
}

void init()
{
    cin >> n;
    for(int i=1;i<=n;++i) cin >>a[i];
    get_next_();
}

int len_a,len_b;

//从i出发,a走的距离,b走的距离
//总距离不超过 len
void dfs(int i,bool afirst,int len) {
    int next = 0;
    if( afirst )
        next = next_2[i];
    else
        next = next_1[i];
    if( next == 0) return;

    int dis = _abs_sub(a[i],a[next]);
    len -= dis;
    if( len < 0 ) return;

    if( afirst)
        len_a += _abs_sub(a[i] , a[next]);
    else
        len_b += _abs_sub(a[i] , a[next]);
    dfs(next,!afirst,len);
}

// 分数类
//得到两个数乘后的正负 -1 表示负 1 表示正
//原理是异或
int sgn(int a,int b) {
    return (a^b) < 0 ? -1 : 1;
}

struct Fraction {
    ll a,b; // 分子分母

    //得到a,b的乘/除 后的公共符号
    //-1 表示负, 1 表示正
    static
    constexpr
    ll sgn(ll a,ll b) {
        return (a^b) < 0  ? -1 : 1;
    }

    static
        constexpr
        ll _abs(ll a) { return a < 0 ? -a : a;}

    //构造函数
    constexpr
    Fraction(ll a,ll b)
        : a(sgn(a,b)*_abs(a)), //a来存公共符号
        b(_abs(b))
    {}


    bool operator==(const Fraction & oth)
    {
        return a == oth.a && b == oth.b;
    }

    bool operator<(const Fraction & oth)
    {
        return a * oth.b < oth.a * b;
    }

    //TODO
    Fraction operator*(const Fraction oth) const;
    Fraction operator-(const Fraction oth) const;
    Fraction operator+(const Fraction oth) const;
};

//无穷大的分数
const auto Fraction_inf = Fraction(1,0);
//无穷小的分数
const auto Fraction_neg_inf = Fraction(-1,0);



int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();

    // std::cout << "----------" << "\n";
    int x0;
    std::cin >> x0;
    Fraction ans_1 = Fraction_inf;
    int ans_start_x0 = -1;
    for(int i=1;i<=n;++i){
        len_a = len_b = 0 ;
        dfs(i,true,x0);
        // tdbg(i,len_a,len_b,len_b == 0 ? -1 : len_a *1.0/ len_b);
        Fraction t(len_a,len_b);
        if(   t < ans_1) {
            ans_start_x0= i;
            ans_1 = t;
        }
    }
    cout << ans_start_x0 << "\n";

    cin >> m;
    for(int i=1;i<=m;++i){
        int s,x;
        std::cin >> s >> x;
        len_a= len_b = 0;
        dfs(s,true,x);
        cout << len_a <<" " << len_b << "\n";
    }
    
    return 0;
}
