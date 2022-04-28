#include <iostream>
#include "stock00.h"

/*
 * 实现 stock00.h里的Stock类相关的接口
 *
 * */

Stock::Stock() {
    std::cout << "默认构造函数" << std::endl;
}


//实现构造函数
Stock::Stock(const std::string &co, long n, double pr) {
    std::cout << "带参数的构造函数" << std::endl;
}

//对象被销毁
Stock::~Stock() {
    std::cout << "bye," << company << "\n";
}


void Stock::acquire(const std::string &co, long n, double pr) {
    company = co; //设置名字
    if (n < 0) {
        std::cout << "买入数量不能为负数 \n";
        shares = 0;
    } else {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price) {
    if (num < 0) {
        std::cout << "数量不能为负数 \n";
    } else {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price) {
    if (num < 0) {
        std::cout << "数量不能为负数 \n";
    } else {
        shares -= num;
        share_val = price;
        set_tot();
    }
}


void Stock::update(double price) {
    share_val = price;
    set_tot();
}

void Stock::show() {

    using std::cout;
    using std::ios_base;

    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    std::cout << "company: " << company
              << "share: " << shares << '\n'
              << "share price: " << share_val << '\n'
              << "total worth: " << total_val << '\n';

    cout.precision(2); //显示三位小数
    cout << "total worth:" << total_val << '\n';
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);

}


void Stock::show2() const{
    std::cout << "const 定义的成员函数，保证函数对象不会被修改" << "\n";
}


const Stock &Stock::topval(const Stock &s) const {
    if(s.total_val > total_val){
        return s; //返回传入的参数对象
    }
    else{
        return *this; //返回调用该方法的对象
    }
}