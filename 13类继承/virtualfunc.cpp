//
//created by chetwei on 2022/5/2 
//
#include <iostream>

using namespace std;


class A {
public:
    void foo() {
        cout << "A:foo" << endl;
    }

    virtual void fun() {
        cout << "A:fun" << endl;
    }

};

class B : public A {
public:
    void foo() {
        cout << "B:foo" << endl;
    }
    virtual void fun() {
        cout << "B:fun" << endl;
    }
};

int main(void) {
    A a;
    B b;
    A *pa;
    B *pb;

    pa = &a;
    pa->foo(); //A:foo
    pa->fun(); //A:fun
    pa = &b; //向上转型
    pa->foo(); //A:foo  //取决于指针类型
    pa->fun(); //B:fun  //取决于对象类型

    pb = &b;
    pb ->foo(); //B:foo 使用重载的
    pb ->fun(); //B:fun   //取决于对象类型


    return 0;
}