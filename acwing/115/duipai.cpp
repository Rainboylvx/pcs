#include <cyaroncpp/cyaron.hpp>
#include <string>
#include <iostream>
using namespace cyaron;

//对拍程序
// 对拍 一个a+b问
// 编译出 std1.cpp std2.cpp
// 不停的用第三个参数的lambda 来生成数据
// 对生成的数据 用 std1 std2 来产生out文件
// 对拍100次，不一样就停止
// 默认生成的数据在compare文件夹下
// 生成的数据名为 in
// std1 生成的数据名为 user_out
// std2 生成的数据名为 std_out

void data_generator(cyaron::IO& rndio){
    rndio.input_writeln(cyaron::RND(1,10),cyaron::RND(1,10));
}

int main(){

    // Compare::program("std1.cpp","std2.cpp",
    //         [](cyaron::IO& rndio){ //生成数据的lambda，接收的参数必须是IO &
    //         rndio.input_writeln(cyaron::RND(1,10),cyaron::RND(1,10));
    //         },
    //         100);


    //也可以使用普通函数，但函数的参数一定要对
    // Compare::program("std1.cpp","std2.cpp",data_generator,100);

    //在test123下生成数据
    // Compare::program("std1.cpp","std2.cpp",func,100,"test123");

    //每个生成的数据为一个单独的文件
    // in1 in2 in3....
    // usr_out1 usr_out2 usr_out3 ...
    // std_out1 std_out2 std_out3 ...
    // Compare::program<false>("std1.cpp","std2.cpp",func,100,"test123");

    //使用rnd.cpp这个代码来生成数据,rnd.cpp的写法见下面
    Compare::program("1.cpp","right.cpp","data.cpp",100);
    return 0;
}
