//
// Created by chetwei on 2022/4/30.
//
#include <iostream>

#ifndef C_PLUS_BASIC_STRINGBAD_H
#define C_PLUS_BASIC_STRINGBAD_H

class StringBad {

private:
    char *str; //char指针
    int len;
    static int num_strings; //静态存储类 , 无论创建多少对象，程序都只创建一个静态类变量副本

public:
    StringBad(const char *s);

    StringBad();

    //复制构造函数
    StringBad(const StringBad &st);

    ~StringBad();

    //友元函数
    friend std::ostream &operator<<(std::ostream &os, const StringBad &st);

};


#endif //C_PLUS_BASIC_STRINGBAD_H
