/*-----------------
* ✍️🤠: Rainboy  | 📧📬 : rainboylvx@qq.com | 💾⌚: 2023-07-31 09:16:59
*----------------*/
#define maxn 1000005
#define maxe 2000005
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int n,m;
/* 定义全局变量 */

std::string token;
struct f_state{
    bool calc; // 是否需要计算时间
    bool err; //  是否出现语法错误
    bool o1; //是否是常数时间
    char i; // 变量i
    int w;  // 不是常数时间时,n^w的值是多少
};

f_state init_state; //初始状态
f_state target_state; //目标状态
f_state g_state; //全局状态

//自己实现的栈
bool in_stack[300]; // 某个变量是否在栈内
struct stack_ {
    f_state a[maxn];
    int idx;
    void clear() { idx = 0;}

    int size() { return idx;}
    f_state & top() { return a[idx];}

    void push( f_state s) {
        in_stack[s.i] = 1;
        a[++idx] = s;
    }
    
    void pop() { 
        in_stack[top().i] = 0;
        idx--; 
    }
} mysta;

void init_all() { //清空所有
    memset(in_stack,0,sizeof(in_stack));
    mysta.clear();
    init_state.calc = 1;
    init_state.err = 0;
    init_state.i = 0;
    init_state.o1 = 1;
    init_state.w = 0;
    g_state = init_state;
    mysta.push(init_state); //加入初始状态
}


//根据数据,计算得到下一个状态
//整个算法的核心
f_state __mynext__(f_state & s,  char i ,string & x, string & y) {
    f_state news;
    news = init_state;
    news.calc = 1;
    news.i = i;
    f_state & top  = mysta.top();
    if( top.err ) { //出现错误
        news.err = 1;
    }
    else if (in_stack[i] ) //变量在出现过
    {
        news.err = 1;
    }
    else if( top.calc == 0) { //上一个是否可以计算的,也就是无法进入的循环
        news.calc = 0;
    }
    else if( std::isdigit(x[0]) && std::isdigit(y[0])) //x,y是一个数字
    {
        int nx = std::stoi(x); //转成数字
        int ny = std::stoi(y); //转成数字
        if( nx > ny) {
            news.calc = 0; //无法进入下面的循环了
        }
        else {
            if( top.o1  == 1 ) //上一个是o1
            {
                news.o1 =  1;
            }
            else {
                news.o1 = 0;
                news.w = top.w;
            }
        }
    }
    else if( std::isdigit(x[0]) && y[0] == 'n') 
    {
        // int nx = std::stoi(x); //转成数字
        if( top.o1  == 1 ) //上一个是o1
        {
            news.o1 =  0;
            news.w = 1;
        }
        else {
            news.o1 = 0;
            news.w = top.w+1;
        }

    }
    else if( x[0] == 'n' && std::isdigit(y[0])) 
    {
        //一种无法进入的循环
        // int ny = std::stoi(y); //转成数字
        news.calc = 0; //设为不可以计算
    }
    else if( x[0] == 'n' && y[0] == 'n') 
    {
        //这种是o1的
        if( top.o1 == 1) {
            news.o1 = 1;
            news.w = 0;
        }
        else {
            news.o1 = 0;
            news.w = top.w;
        }
    }
    return news;
}
void update_target_state(std::string& str) {
    if( str[2] == '1')
    {
        target_state.o1 = true;
    }
    else if( str[2] == 'n') {
        target_state.o1 = false;
        target_state.w = 0;

        int idx = 4;
        while(str[idx] >= '0' && str[idx] <='9')
        {
            target_state.w *=10;
            target_state.w += str[idx] - '0';
            idx++;
        }
    }

}


//更新全局状态
void update_g_state( f_state & s)
{
    if( s.err )
        g_state = s;
    if( g_state.err ) return; //如果g_state 记录error

    // if( !s.calc) return; //s是不需要计算的状态

    if(!s.o1 && s.w > g_state.w)
        g_state = s;
}

void analyze_g_state(){
    if( mysta.size() != 1)
    {
        cout << "ERR\n"; 
    }
    else if( g_state.err)
    {
        cout << "ERR\n"; 
    }
    else if( g_state.o1 && g_state.o1 == target_state.o1)
    {
        cout << "Yes\n";
    }
    else if( g_state.o1==0 && g_state.o1 == target_state.o1
            && g_state.w == target_state.w
            )
        cout << "Yes\n";
    else
        cout << "No\n";
}


int main(){
    int T;
    std::cin >> T;
    while ( T-- ) {
        std::cin >> n; //读取数量
        // cout << n << endl;
        std::cin >> token; // 读取复杂度
        update_target_state(token); //解析目标状态
        init_all(); //初始化

        while(n--) {
            cin >> token;
            // cout << token << endl;
            if( token[0] == 'F') {
                string i,x,y;
                cin >> i >> x >> y;
                f_state t = __mynext__(mysta.top(),i[0],x,y); //求出新的状态
                update_g_state(t); // 更新全局状态
                mysta.push(t); //加入栈
            }
            else if( token[0] == 'E') {
                mysta.pop();
            }
        }
        // 分析 g_state
        analyze_g_state();
    }
    return 0;
}
