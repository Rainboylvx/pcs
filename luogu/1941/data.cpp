#include <vector>
#include <iostream>
#include <cyaroncpp/cyaron.hpp>
using namespace cyaron;


template<typename... T>
void input_writeln(T&&... args){
    ( (std::cout << args<<" "),...);
    std::cout << "\n";
}

int main(){
    //输出数据
    int n = 6;
    int m = 10;
    int k = 3;
    input_writeln(n,m,3);
    for(int i=1;i<=n;++i){
        int l = RND(1,m/2);
        int h = RND(3,m);
        input_writeln(l,h);
    }
    // for(int i=1;i<=k;++i){
    // }
    std::vector a{1,3,4};
    for (const auto& e : a) {
        int h = RND(3,m);
        int l = RND(1,m/2);
        if( l > h )
            std::swap(l,h);
        input_writeln(e,l,h);
    }
    return 0;
}
