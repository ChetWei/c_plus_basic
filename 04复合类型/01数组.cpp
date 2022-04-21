#include <iostream>


using namespace std;

//4.1数组
void myarray() {
    //先声明数组 再 赋值
    int yams[3];
    yams[0] = 7;
    yams[1] = 8;
    yams[2] = 9;

    //声明的时候并赋值
    int yamcosts[3] = {20, 30, 6};
    cout << "sum:" << yams[0] + yams[1] + yams[2] << endl;
    cout << "yamcosts" << yamcosts[0] << yamcosts[1] << yamcosts[2] << endl;
    std::cout << sizeof yams[0] << "bytes \n";
    //sizeof 运算符返回类型或数据对象的长度（单位为字节）

    long array[10] = {0}; //第一个原素初始化为0，后面所有元素都初始化为0
    long arrayn[10] = {1}; //第一个原素初始化为1，后面所有元素都初始化为0
    float balances[10]{}; //可以省略=号，大括号内不包含任何东西，这将把所有元素都设置为0

    //long plifs[] = {25,92,3.0}; 不允许缩窄转换 float -> long
    //char slifs[4] = {'H','i',1122011}; //元素不能超过该类型的取值范围 1122011 超过了char变量的范围



    for (long i: array) {
        cout << "array" << i << endl;
    }

    for (long i: arrayn) {
        cout << "arrayn" << i << endl;
    }

    for (long i: balances) {
        cout << "balances" << i << endl;
    }

    //声明数组的时候没有指定长度，编译器将会计算元素的个数
    //自动计算可能会存在问题
    short things[] = {2, 4, 6, 8};
    cout << sizeof things;
    for (short i: things) {
        cout << i << endl;
    }
}