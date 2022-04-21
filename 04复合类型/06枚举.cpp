
#include "iostream"

//定义一个枚举结构，里面的值隐式 设置为 0 1 2 ...
enum spectrum {
    red,
    orange,
    yellow,
    green,
    blue,
    violet,
    indigo,
    ultraviolet
};

//显式 定义一个枚举结构
enum bits {
    one = 1,
    two = 2,
    four = 4,
    eight = 8
};

void test() {
    spectrum band; //定义一个枚举变量
    band = blue; // 赋值一个枚举类型
    std::cout << "band:" << band << std::endl;;
//    band++ ; //无效，枚举没有运算

    int color = blue; //枚举量是整形，可以赋值给int类型；
//    band = 3 ; //但是int类型不能自动转换为枚举类型

    color = 3 + band; //有效，band可以转换为int类型


    std::cout << "color:" << color << std::endl;

    bits b ;
    b = eight;
    std::cout << "b:" << b << std::endl;

};