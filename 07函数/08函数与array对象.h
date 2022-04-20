#include <iostream>
#include <array>

using namespace std;

//在c++中 类对象是基于结构的
//可以按值将对象传递给函数，也可以传递指向对象的指针

const int SeasonNum = 4;

void show(array<string, SeasonNum> ds);
//这里因为 传递的地址对应的值是const ，所以参数里面必须使用const指针类型
void show_pt(const array<string, SeasonNum> *ps);

void test() {

    const array<string, SeasonNum> seasons = {"spring", "summer", "fall", "winter"};
    cout << "&seasons " << &seasons << endl;
    show(seasons);

    show_pt(&seasons);
}

//对象值传递  副本
void show(std::array<string, SeasonNum> ds) {
    cout << "------show--------" << endl;
    cout << "&ds " << &ds << endl;
    for (int i = 0; i < SeasonNum; i++) {
        cout << ds[i] << endl;
    }
}

//传递指向对象的指针
void show_pt( const std::array<string, SeasonNum> *ps) {
    cout << "------show_pt--------" << endl;
    cout << "ps " << ps << endl;
    for (int i = 0; i < SeasonNum; i++) {
        cout << (*ps)[i] << endl; //ps 是指向 array<string, SeasonNum>对象的指针，因此 (*ps) 是这种对象
        //(*ps)[i] 是该对象的一个元素
    }
}