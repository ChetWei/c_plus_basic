//
// Created by 魏名安 on 2022/4/30.
//

#ifndef C_PLUS_BASIC_STRING_H
#define C_PLUS_BASIC_STRING_H

#include <iostream>
using std::ostream;
using std::istream;

class String {

private:
    char *str;
    int len; // 字符串长度
    static int num_strings; //已经创建的对象个数
    static const int CINLIM = 80; //输入长度限制
public:
    String(); //默认构造函数
    String(const char *s);

    String(const String &); //复制构造函数
    ~String(); //析构函数

    int length() const {
        return len;
    }

    //重载运算符方法
    String &operator=(const String &s);

    String &operator=(const char *s);

    char &operator[](int i);

    const char &operator[](int i) const;

    // 友元函数重载运算符方法
    friend bool operator<(const String &st, const String &st2);

    friend bool operator>(const String &st, const String &st2);

    friend bool operator==(const String &st, const String &st2);

    friend ostream & operator<<(ostream &ostream, const String &st);

    friend istream & operator>>(istream &istream, String &st);

    //静态方法 可以通过类名直接调用，静态方法里面只能使用静态成员
    static int HowManyInstance();

};

#endif //C_PLUS_BASIC_STRING_H