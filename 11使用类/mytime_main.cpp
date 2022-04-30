
#include <iostream>
#include "mytime0.h"

//使用重载运算符

int main() {
    using std::cout;
    using std::endl;

    Time plannig;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    cout << "planning time = ";
    plannig.Show();

    cout << "coding time = ";
    coding.Show();

    cout << "fixing time = ";
    fixing.Show();

//    total = coding.Sum(fixing);
    total = coding.operator+(fixing); //使用重载的加法运算符
    total = coding + fixing; //直接相加等于上面的效果
    cout << "total time = ";
    total.Show();

    cout << total; //使用Time重载了的 <<
}
