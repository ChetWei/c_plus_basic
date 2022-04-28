//
// Created by 魏名安 on 2022/4/27.
//

#ifndef C_PLUS_BASIC_STOCK00_H
#define C_PLUS_BASIC_STOCK00_H

#include <iostream>

class Stock {
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;

    //内置的私有函数，用来更新 total_val 的值
    void set_tot() {
        total_val = share_val * shares;
    };


public:
    //定义构造函数
    // 构造函数是一种特殊的成员函数，在创建类对象的时候被调用
    // 构造函数的名称和类名称相同,但通过函数重载，可以创建多个同名的构造函数，条件是每个函数的参数列表不同

    Stock(); // 默认构造函数，没有被初始化的对象，将默认使用构造函数来创建

    Stock(const std::string &co, long n, double pr=0.0);

    ~Stock(); // 析构函数 （每个类只有一个，没有返回类型，也没有参数）  当构造函数生成的对象被销毁时候调用

    void acquire(const std::string &co, long n, double pr);

    void buy(long num, double price);

    void sell(long num, double price);

    void update(double price);

    void show();

    void show2() const; //const成员函数，保证函数无法修改调用对象的内容

    const Stock & topval(const Stock &s) const; //返回Stock的引用
};


#endif //C_PLUS_BASIC_STOCK00_H
