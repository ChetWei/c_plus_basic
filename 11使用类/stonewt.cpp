//
//created by chetwei on 2022/4/30 
//
#include <iostream>

using std::cout;

#include "stonewt.h"

//实现stonewt类里面的函数接口


Stonewt::Stonewt() {
    cout << "Stonewt() 构造函数初始化" << std::endl;
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(double lbs) {
    cout << "Stonewt(double lbs) 构造函数初始化" << std::endl;
    stone = int(lbs) / Lbs_per_stn;
    pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs) {
    cout << "Stonewt(int stn, double lbs) 构造函数初始化" << std::endl;
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn + lbs;
}

Stonewt::~Stonewt() {
    cout << "destroy Stonewt object" << std::endl;
}

void Stonewt::show_stn() const {
    cout <<"stone: " << stone << std::endl;
}

void Stonewt::show_lbs() const {
    cout <<"pounds: " << pounds << std::endl;
}

//转换函数 没有返回类型，没有参数，但必须返回转换后的值
Stonewt::operator int() const {
    return int (pounds + 0.5);
}

//转换函数 没有返回类型，没有参数，但必须返回转换后的值
Stonewt::operator double() const {
    return pounds;
}

//转换函数 没有返回类型，没有参数，但必须返回转换后的值
//Stonewt::operator long() const {
//    return 1000l;
//}
