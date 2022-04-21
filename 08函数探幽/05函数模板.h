#include <iostream>

using namespace std;

//函数模板  使用泛型来定义函数参数类型，泛型可以用具体的类型替换

template <class T> //定义一个泛型为T
//template <template T> //定义一个泛型为T
void myswap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}




void test(){
    int i = 10;
    int j = 20;
    myswap(i,j);
    cout << "i :" << i ;
    cout << "\t j :" << j << endl;

    double m = 99.8;
    double n = 12.44;
    myswap(m,n);
    cout << "m :" << m ;
    cout << "\t n :" << n << endl;
}




