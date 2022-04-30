//
// Created by chetwei on 2022/4/30.
//

#include <iostream>

using std::cout;

#include "stringbad.h"

void callme1(StringBad & s); //引用
void callme2(StringBad s); //值传递


int main() {

    using std::endl;
    {
        cout << "=======starting an inner block =========\n";
        StringBad headline1("I am headline1");
        StringBad headline2("I am headline2");
        StringBad sports("I am sports");

        cout << "headline1\t" << headline1 << endl;
        cout << "headline2\t" << headline2 << endl;
        cout << "sports\t" << sports << endl;

        callme1(headline1);
        cout << "headline1\t" << headline1 << endl;

        callme2(headline2);
        cout << "headline2\t" << headline2 << endl;

        StringBad sailor = sports;
        //默认复制构造函数是浅复制，sailor  sports  指向同一个内存地址
        //因此调用析构函数的时候对同一个地址进行两次释放，会出现问题
        //这里使用的自定义构造函数是 显示复制构造函数 String(const StringBad &)

        cout << "sailor\t" << sailor << endl;

        StringBad knot;
        knot = headline1;
        //默认的赋值运算符，对于对象来说也是浅复制
        //重写赋值运算符 = 为深度复制
        cout << "knot\t" << knot << endl;
    }
    cout << "=======End of main() =========\n";

}

void callme1(StringBad & s){
    cout << "callme1()" << std::endl;
    cout << s << std::endl;
}

void callme2(StringBad s){
    cout << "callme2()" << std::endl;
    cout << s << std::endl;
}