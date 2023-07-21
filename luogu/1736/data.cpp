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
    int n = RND(4,10);
    int m = RND(4,10);
    out.print(n,m);
    out.ln();
    for(int i =1;i<=n;i++){
        for(int j =1;j<=m;j++)
        {
            out.print(RND(0,1));
        }
        out.ln();
    }
    return 0;
}
