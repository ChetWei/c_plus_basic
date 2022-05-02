//
// Created by 魏名安 on 2022/5/2.
//

#ifndef C_PLUS_BASIC_STUDENT_H
#define C_PLUS_BASIC_STUDENT_H

#include <iostream>
#include <string>
#include <valarray>

using namespace std;

//14.1 包含其他类对象的类

class Student {
private:
    typedef valarray<double> ArrayDb; //可以在类中使用，但不能在类以外的位置使用
    string name; //姓名
    ArrayDb scores; //分数

    ostream &arr_out(ostream &os) const;

public:
    //这里使用了初始化列表语法，方法 :
    Student() : name("null"), scores() {}

    //使用explicit 禁止 = 隐式转换
    explicit Student(const string &s);

    Student(const string &s, int n) : name(s), scores(n) {}

    Student(const string &s, const ArrayDb &a) : name(s), scores(a) {}

    //scores(pd,n)调用 ArrayDb(const double *,int)
    Student(const char *str, const double *pd, int n) : name(str), scores(pd, n) {}

    ~Student() {}

    double Average() const;

    const string &Name() const;

    double &operator[](int i);

    double operator[](int i) const;

    //友元函数
    friend istream &operator>>(istream &is, Student &stu);

    friend istream &getline(istream &is, Student &stu);

    friend ostream &operator<<(ostream &os, const Student &stu);
};


#endif //C_PLUS_BASIC_STUDENT_H
