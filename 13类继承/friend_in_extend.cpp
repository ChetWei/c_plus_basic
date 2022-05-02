//
//created by chetwei on 2022/5/2 
//
#include "friend_in_extend.h"
#include <iostream>

//基类方法的实现
baseA::baseA(const char *l, int r) {
    lable = new char[strlen(l) + 1];
    strcpy(lable, l);
    rating = r;
}

baseA::baseA(const baseA &a) {
    lable = new char[strlen(a.lable) + 1];
    strcpy(lable, a.lable);
    rating = a.rating;
}

baseA::~baseA() {
    delete[] lable;
}

baseA &baseA::operator=(const baseA &a) {
    if (this == &a) {
        return *this;
    }
    delete[] lable;
    lable = new char[strlen(a.lable) + 1];
    strcpy(lable, a.lable);
    rating = a.rating;
    return *this;
}

//A的友元函数
ostream &operator<<(ostream &os, const baseA &a) {
    os << "Label: " << a.lable << endl;
    os << "Rating: " << a.rating << endl;
    return os;
}


//派生类方法的实现
extendB::extendB(const char *s, const char *l, int r) : baseA(l, r) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

extendB::extendB(const char *s, const baseA &a) : baseA(a) {
    style = new char[strlen(s) + 1];
    strcpy(style, s);
}

//这里将b的对象传递给a的初始化方法，将向上转型
extendB::extendB(const extendB &b) : baseA(b){
    style = new char[strlen(b.style) + 1];
    strcpy(style, b.style);
}

extendB::~extendB()  {
    delete [] style; //管理自己通过new分配的成员
}

extendB &extendB::operator=(const extendB &b) {
    if (this == &b) {
        return *this;
    }
    baseA::operator=(b);
    delete[] style;
    style = new char[strlen(b.style) + 1];
    strcpy(style, b.style);
    return *this;
}

//b的友元函数
ostream & operator <<(ostream &os , const extendB &b){
    os << (const baseA &) b; //将b强转为a的类型引用,自然就会使用a的友元
    os << "style: " << b.style << endl;
    return os;
}

int main(){
    using std::cout;
    using std::endl;

    extendB b ("red","tom",4);

    cout << b << endl;

    return 0;
}


