//
// Created by 魏名安 on 2022/4/29.
//

#include <ostream>



#ifndef C_PLUS_BASIC_MYTIME0_H
#define C_PLUS_BASIC_MYTIME0_H

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void AddMin(int m);

    void AddHr(int h);

    void Reset(int h = 0, int m = 0);

    Time Sum(const Time &t) const;

    //重载加法运算符
    Time operator+(const Time &t) const;

    //友元函数（可以访问类的私有成员）
    //虽然operator*() 函数是在类声明中声明的，但它不是成员函数，因此不能使用成员运算符来调用
    //虽然operator*() 函数不是成员函数，但它与成员函数的访问权限相同
    friend Time operator*(double m,const Time &t);

    //返回ostream对象的引用
    friend std::ostream & operator<<(std::ostream &os,const Time &t);

    void Show() const;
};

#endif //C_PLUS_BASIC_MYTIME0_H
