#include <vector>
#include <iostream>
// #include <cyaroncpp/cyaron.hpp>
#include "base.hpp"
#include "utils/random/tree.hpp"
using namespace __random;


template<typename... T>
void input_writeln(T&&... args){
    ( (std::cout << args<<" "),...);
    std::cout << "\n";
}

int main(){
    //输出数据
    int n = 5;
    int m = RND(3,5);
    input_writeln(n,m);
    for(int i=1;i<=m;++i){
        input_writeln(RND(1,10),RND(1,10),RND(1,10));
    }

    return 0;
}
