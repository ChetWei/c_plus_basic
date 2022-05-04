//
// Created by 魏名安 on 2022/5/4.
//
#include "a.h"
#include <iostream>

using std::string;

#ifndef C_PLUS_BASIC_B_H
#define C_PLUS_BASIC_B_H


//私有继承 将基类的公有方法变成了派生类中的私有方法
//保护继承 基类的公有方法在第二代中变成受保护的

class B : private A {

public:

    B() : A("Null student") {}

    //禁止隐式转换
    explicit B(const string s) : A(s) {};

    explicit B(const char *s) : A(s) {};

    ~B();

    void show() {
        A::a_say(); //使用类名:: (作用域解析)访问 私有继承的类方法
    }

    //转为基类对象
    const A &getA() const {
        return (const A &) *this;
    }

};


#endif //C_PLUS_BASIC_B_H
