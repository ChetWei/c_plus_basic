#include <iostream>
#include "mytime0.h"


Time::Time() {
    hours = minutes = 0;
}

Time::Time(int h, int m) {
    hours = h;
    minutes = m;
}

void Time::AddMin(int m) {
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h) {
    hours += h;
}

void Time::Reset(int h, int m) {
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

Time Time::operator+(const Time &t) const {
    Time sum;
    sum.minutes = minutes + t.minutes; // minutes是隐式传递的调用对象的属性
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

//对友元 函数的实现 不加 friend
//友元函数不是成员函数，但是对类的访问权限与成员函数相同
Time operator*(double m, const Time &t) {
    Time result;
    long totalminutes = t.hours * 60 + t.minutes;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

//友元函数
std::ostream & operator<<(std::ostream &os,const Time &t){
    std::cout << "operator<< function: \n" ;
    os << t.hours << "hours, " << t.minutes << " minutes" << std::endl;
    return os; //返回ostream对象的引用
}

void Time::Show() const {
    std::cout << hours << " hours,"
              << minutes << " minutes" << std::endl;
}