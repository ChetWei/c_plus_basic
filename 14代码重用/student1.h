//Created by chetwei on 2022/5/2

#include <iostream>
#include <string>
#include <valarray>

//14.2私有继承，继承的时候使用private关键字
//使用多个基类的继承被称为多重继承
class Student : private std::string, private std::valarray<double> {


};