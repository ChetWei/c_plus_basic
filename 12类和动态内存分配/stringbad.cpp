//
//created by chetwei on 2022/4/30 
//

#include <cstring>
#include "stringbad.h"

using std::cout;

int StringBad::num_strings = 0; //初始化静态变量的值，不能在类声明中初始化静态成员变量


//构造函数 默认的构造函数
StringBad::StringBad() {
    len = 4;
    str = new char[len + 1]; //动态分配 赋值给char指针
    std::strcpy(str, "C++");
    num_strings++;
    cout << "num_strings: " << num_strings << std::endl;
}


//构造函数
StringBad::StringBad(const char *s) {
    len = std::strlen(s);
    str = new char[len + 1]; //使用new开辟的空间，在堆内存中，对象只保留了指向内存空间的指针
    std::strcpy(str,s);
    num_strings++;
    cout << "num_strings: " << num_strings << std::endl;
}


//析构函数
StringBad::~StringBad() {
    cout << str << "  object deleted " << std::endl;
    --num_strings;     //对static变量的操作
    cout << num_strings << " left\n";
    delete[] str;      //释放指针指向的空间
}

//复制构造函数 自定义  深度复制
StringBad::StringBad(const StringBad &st) {
    cout << "deep copy " << std::endl;

    num_strings ++ ;
    len = st.len;
    str = new char[len + 1]; //指针指向一个新开辟的地址
    std::strcpy(str,st.str); //拷贝内容到新的地址
    cout << "num_strings: " << num_strings << std::endl;
}


//重载运算符
std::ostream &operator<<(std::ostream &os, const StringBad &st) {
    os << st.str;
    return os;
}