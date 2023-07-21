//一个不使用本代码库的模板,ver 0.1, upd at 2023-07-09
/* author: Rainboy email: rainboylvx@qq.com  time: 2023年 07月 09日 星期日 21:51:45 CST */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e6+5,maxe = 1e6+5; //点与边的数量

#ifndef DEBUG
#define DEBUG
#endif

//////// 常用宏
#define F(n) for(int i=1;i<=n;++i)
#define FF(i,n) for(int i=1;i<=n;++i)
#define F3(i,s,n) for(int i=s;i<=n;++i)



/////////////// log,调试用
#define __LOG_INFO__   "[" << "Ln " << __LINE__  << "]: "

#ifdef DEBUG
#define log(...) std::cerr << __LOG_INFO__ ; __debug_with_arg_name(std::cerr,#__VA_ARGS__,__VA_ARGS__)
#else
#define log(...)
#endif

template<typename T1,typename... T2>
void __debug_with_arg_name(std::ostream & O , std::string_view args_str, T1&& arg1)
{

    O << args_str<< "=" << arg1 <<  '\n';
}

template<typename T1,typename... T2>
void __debug_with_arg_name(std::ostream & O , std::string_view args_str, T1&& arg1,T2&&... args) 
{
    auto p1 = args_str.find_first_of(",");
    O << args_str.substr(0,p1) << "=" << arg1  << ',';
    __debug_with_arg_name(O, args_str.substr(p1+1),std::forward<T2>(args)...);
}
///////////////////////

int n,m;
/* 定义全局变量 */

// int a[maxn]; //常用的一个数组 
//  A C G  T -
//A 5 -1 -2 -1 -3
//C -1 5 -3 -2 -4 
//G -2 -3 5 -2 -2
//T -1 -2 -2 5 -1
//- -3 -4 -2 -1 ∗
char str[] = {'A','C','G','T','-'};

int similar[500][500];

char sa[200];
char sb[200];

void init()
{
    scanf("%d",&n);
    scanf("%s",sa+1);
    scanf("%d",&m);
    scanf("%s",sb+1);
    int xxx[][5] = {
        {5,-1,-2,-1,-3},
        {-1,5,-3,-2,-4},
        {-2,-3,5,-2,-2},
        {-1,-2,-2,5,-1},
        {-3,-4,-2,-1,-0x7f7f7f7f},
    };

    int row= 0;
    int col= 0;
    F3(i,0,4) {
        col = 0;
        F3(j,0,4)
        {
            char a = str[i];
            char b = str[j];
            similar[a][b] = xxx[row][col];
            log(row,col,xxx[row][col]);
            col++;
        }
        row++;
    }
}

int f[200][200];



//开始dp
void work() {
    F3(i,0,100)
        F3(j,0,100)
            f[i][j] = -0x7f7f7f7f;
    f[0][0] = 0;
    //边界
    F3(i,1,n){
        f[i][0] = 0;
        F3(j,1,i)
            f[i][0] += similar[sa[j]]['-'];
    }
    F3(i,1,n){
        f[0][i] = 0;
        F3(j,1,i)
            f[0][i] += similar[sb[j]]['-'];
    }

    F3(i,1,n) {
        F3(j,1,m) {
            int a = f[i-1][j] + similar[sa[i]]['-'];
            int b = f[i-1][j-1] + similar[sa[i]][sb[j]];
            int c = f[i][j-1] + similar['-'][sb[j]];
            f[i][j] = max({a,b,c});
        }
    }
}

int main(int argc,char * argv[]){
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    init();
    log(similar['A']['A']);
    log(similar['A']['-']);
    log(similar['-']['T']);
    work();
    printf("%d\n",f[n][m]);
    return 0;
}
