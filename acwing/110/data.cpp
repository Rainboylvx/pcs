#include <vector>
#include <iostream>
// #include <cyaroncpp/cyaron.hpp>
#include "base.hpp"
#include "chips/piece.hpp"
#include "chips/range.hpp"
#include "utils/random/tree.hpp"
using namespace __random;


template<typename... T>
void input_writeln(T&&... args){
    ( (std::cout << args<<" "),...);
    std::cout << "\n";
}

int main(){
    //输出数据
    int n = 6,m = 6;
    n = RND(1,20);
    m = RND(1,20);
    out.println(n, m);
    FOR(i,R>n) {
        int a = RND(1,10);
        int b = RND(1,10);
        if( a > b)
            std::swap(a,b);
        out.println(a,b);
    }

    FOR(i,R>m) {
        int a = RND(1,5);
        int b = RND(1,5);
        out.println(a,b);
    }
    return 0;
}
