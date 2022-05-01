//
//created by chetwei on 2022/4/30 
//
#include <cstring
#include "string1.h"

using std::ostream;
using std::iostream;


int String::num_strings = 0; //初始化静态变量

//静态方法
int String::HowManyInstance() {
    return num_strings;
}

//类成员方法
String::String() {
    len = 4;
    str = new char[1];
    str[0] = '\0';
    num_strings++;
}

String::String(const String &s) {
    num_strings++;
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
}

String::String(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
}

String::~String() {
    --num_strings;
    delete[] str;
}

//类成员重载=方法，调用的时候类成员放在前面
String &String::operator=(const String &s) {
    if (this == &s) { //如果是将自己赋值给自己
        return *this;
    }
    delete[] str; //先删除当前对象str已指向的内存
    len = s.len;
    str = new char[len + 1];
    std::strcpy(str, s.str);
    return *this; //返回当前对象
}

//类成员重载=方法，调用的时候类成员放在前面
String &String::operator=(const char *s) {
    delete[] str; //先删除当前对象str已指向的内存
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    return *this; //返回当前对象
}

char &String::operator[](int i) {
    return str[i];
}

const char &String::operator[](int i) const {
    return str[i];
}

//友元函数重载 运算符
bool operator<(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st, const String &st2) {
    return st2 < st;
}

bool operator==(const String &st1, const String &st2) {
    return (std::strcmp(st1.str, st2.str) == 0);
}

ostream& operator<<(ostream &ostream, const String &st) {
    ostream << st.str;
    return ostream;
}

istream& operator>>(istream &istream, String &st) {
    char temp[String::CINLIM];
    istream.get(temp, String::CINLIM);
    if (istream) {
        st = temp;
    }
    while (istream && istream.get() != '\n')
        continue;
    return istream;
}