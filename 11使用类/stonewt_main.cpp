//
// Created by chetwei on 2022/4/30.
//

//类的自动类型转换和强制类型转换

#include <iostream>

using std::cout;

#include "stonewt.h"


int main() {
    Stonewt incogito = 275; // 使用构造函数初始化
    Stonewt wolfe(285.7); //也是使用构造函数初始化
    Stonewt taft(21, 8);

    incogito.show_stn();
    wolfe.show_stn();
    taft.show_stn();

    incogito = 276.8; //使用构造函数进行转换 incogito(276.8)
    taft = 325;// taft(325)

    double p_wt = wolfe; //隐式转换 等价 double p_wt = double(wolfe) 会调用类里面定义的重载函数

    double p_wt2 = taft; //隐式转换 taft是int ，会走 int(taft)
//    long p_wt3 = taft;// 这里将是不支持的，因为类里面定义了两种类型转换，都没有转为long的
    cout << "p_wt: " << p_wt << std::endl;
    cout << "wolfe int val: " << int(wolfe) << std::endl; //显示强制类型转换 ,会调用类里面定义的int重载函数


    //todo 最好不要使用隐式转换函数
    return 0;
}


