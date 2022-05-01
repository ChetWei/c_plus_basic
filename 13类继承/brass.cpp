//
//created by chetwei on 2022/5/1 
//
#include <iostream>
#include "brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat();

void restore(format f, precis p);


Brass::Brass(const std::string &s, long an, double bal) {
    fullName = s;
    acctNum = an;
    balance = bal;
}

//存款
void Brass::Deposit(double amt) {
    if (amt < 0) {
        cout << "存款金额不能为负数\n";
    } else {
        balance += amt;
    }
}

//取款
void Brass::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    if (amt < 0) {
        cout << "取款金额不能为负数\n";
    } else if (amt <= balance) {
        balance -= amt;
    } else {
        cout << "取款金额：$" << amt << "超过了余额：$" << balance << endl;
    }

    restore(initialState, prec);
}

double Brass::Balance() const {
    return balance;
}

//查看账户
void Brass::ViewAcc() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
    restore(initialState, prec);
}

BrassPlus::BrassPlus(const std::string &s, long an, double bal, double m1, double r) {
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double m1, double r) : Brass(ba) {
    maxLoan = m1;
    owesBank = 0.0;
    rate = r;
}

//重写父类的方法
void BrassPlus::ViewAcc() const {
    format initialState = setFormat();
    precis prec = cout.precision(2);
    Brass::ViewAcc();
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);
    cout << "Loan Rate: " << 100 * rate << "%\n";
    restore(initialState, prec);
}

void BrassPlus::Withdraw(double amt) {
    format initialState = setFormat();
    precis prec = cout.precision(2);

    double bal = Balance();
    if (amt <= bal) {
        Brass::Withdraw(amt);
    } else if (amt <= bal + maxLoan - owesBank) {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Brass::Withdraw(amt);
    } else {
        cout << "credit limit exceeded. Transaction cancelled \n";
        restore(initialState, prec);
    }
}

format setFormat() {
    return cout.setf(std::ios_base::fixed,
                     std::ios_base::floatfield);
}

void restore(format f, precis p) {
    cout.setf(f, std::ios_base::floatfield);
    cout.precision(p);
}