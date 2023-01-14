/* 作者：[这里写你的名字] ; 邮箱：[这里写你的邮箱] ; 时间:$TODAY */
#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
#define mm memset
#define EPS 1e-8
#define inf 0x7f7f7f7f
#define ninf -inf
typedef long long ll;

//#define dbg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__<<" "; ((cerr<<exchange(c,',')<<" "<<x),...); cerr<<endl; }(__VA_ARGS__);
//兼容问题，没有使用c++17的 fold expression,使用了c++11递归 variadic template
template<char Delimiter = ' ',typename Args>
void print(std::ostream &os, Args&& args){ os << args << std::endl; }

template<char Delimiter = ' ',typename T,typename... Args>
void print(std::ostream &os,T t,Args&&... args){
    os << t << Delimiter;
    print<Delimiter>(os,args...);
}
#define  dbg(...) std::cerr << "Line: " << __LINE__ << ": " #__VA_ARGS__ " = "; print<','>(std::cerr,__VA_ARGS__)

/* 快读: 可以用于 int,long long , __int128 */
template<class T>
void read(T &a){
    a = 0;T flag = 1; char ch = getchar();
    while( ch <  '0' || ch >  '9'){ if( ch == '-') flag = -1; ch = getchar(); }
    while( ch >= '0' && ch <= '9'){ a = a*10 + ch-'0'; ch = getchar(); }
    a*=flag;
}
// ---------------------- 代码开始 ----------------------

const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量
/* 定义全局变量 */
int n,m; 


int main(){
    ios::sync_with_stdio(false); cin.tie(0); // cin 加速


    return 0;
}
