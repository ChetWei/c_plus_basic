//
// Created by 魏名安 on 2022/5/4.
//

#ifndef C_PLUS_BASIC_A_H
#define C_PLUS_BASIC_A_H

#include <iostream>

using std::string;
using std::cout;

class A {
private:
    string a_name;

public:
    A() {};

    A(const string name) {
        a_name = name;
    };

    A(const char *str) {
        a_name = str;
    };

    ~A();

    //友元函数
    friend std::ostream &operator<<(std::istream &os, A &a);

    void a_say(){
        cout << "hello a" << std::endl;
    }

    void showName() {
        cout << "a_name" << a_name << std::endl;
    }
};


#endif //C_PLUS_BASIC_A_H
