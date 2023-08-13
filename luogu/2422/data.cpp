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
    int n = RND(5,9);
    out.println(n);
    //输出n个点的随机数
    for(int i=1;i<=n;++i){
        out << RND(1,10);
        // out.sp();
    }
    out.ln();
    //输出树 auto tr = tree(n);
    // out.println(tr);

    return 0;
}
