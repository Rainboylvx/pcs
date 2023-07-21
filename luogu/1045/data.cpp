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
    out.println(RND(4,20));

    return 0;
}
