#include <iostream>

using namespace std;

//内联函数的作用：
//一般的函数调用都要使用中断计算 跳到对应的程序栈中执行，结束后再回到原来的函数
//内联函数 无需调到另一个位置执行代码，编译器会使用相应的函数代码来替换函数调用
//可以理解为将函数复制到了主程序中，减少了调用的开销，但是如果调用的函数比较长，调用次数多，会造成大量内存占用

//定义一个内联函数，用inline 开头
inline double square(double x){return x*x ;}

void  test(){
    double a ,b;
     a = square(5.0);
     b = square(9.0);

     cout << "a: " << a << endl;
     cout << "b: " << b << endl;

}