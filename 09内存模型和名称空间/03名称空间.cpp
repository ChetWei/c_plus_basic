#include <iostream>

//using编译指令，导入一个名称空间中的所有的名称
//using声明，声明了指定的名称


using namespace std;

//定义一个名称空间
namespace Jill {
    double bucket(double n) { return 0; }
    double fetch = 9.9;
    double aa = 100;
    struct Hill {
    };
}

double fetch = 10.9; // 定义一个全局变量

int main() {
    using namespace Jill; //using编译指令，使得所有的名称都可用
//    Hill Thrill;
//    double water = bucket(2);

    double fetch = 8.8;
    //当有多个相同名称的变量时
    cout << aa << endl;
    cout << fetch << endl; // 写入到局部变量
    cout << ::fetch << endl; //写入到全局的变量
    cout << Jill::fetch << endl; //写入到指定的名称空间中 using 声明
}