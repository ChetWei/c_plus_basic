//
// Created by 魏名安 on 2022/5/1.
//

#ifndef C_PLUS_BASIC_BRASS_H
#define C_PLUS_BASIC_BRASS_H

#include <string>

class Brass {
private:
    std::string fullName;
    long acctNum;
    double balance;

public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);

    void Deposit(double amt);

    double Balance() const;


    void Withdraw(double amt);

    void ViewAcc() const;

    virtual ~Brass() {}
};


//继承类
class BrassPlus : public Brass {
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string &s = "NullBody", long an = -1, double bal = 0.0,
              double m1 = 500, double r = 0.11125);

    BrassPlus(const Brass &ba, double m1 = 500, double r = 0.11125);

    //virtual 虚方法的关键字
    //作用:程序将根据引用或指针 所指向的对象类型来选择方法，而不是引用变量的类型
    //如果基类中的方法使用了虚方法声明，那么无论如何都是使用基类中你的方法
    virtual void Withdraw(double amt);

    virtual void ViewAcc() const;

    //添加的新方法
    void ResetMax(double m) { maxLoan = m; }

    void ResetRate(double r) { rate = r; }

    void ResetOwes() { owesBank = 0; }

};


#endif //C_PLUS_BASIC_BRASS_H
