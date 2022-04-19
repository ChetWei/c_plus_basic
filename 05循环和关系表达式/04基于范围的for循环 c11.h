#include <iostream>

using namespace std;

void test(){
    double prices[5] = {4.99,2.7,9.22,5.66,11.22};
    //基于范围的for循环
    for (double x : prices){
        cout << "x: " << x << endl;
        x = 9.99; //这里的改变并没有影响prices数组内容
    }

    // 基于范围的for循环遍历如何改变数组内容
    for (double &x : prices){
        x = x * 9.99;
    }
    for (double x : prices){
        cout << "x new: " << x << endl;
    }
};
