
#include <iostream>

//union 关键字 共用体
union one4all{
    int int_val;
    long long_val;
    double double_val;
};



void test(){

    //共用体能存储不同的数据类型，但只能同时存储其中的一种类型
    //共用体每次只能存储一个值，存储其他类型的时候会被覆盖

    one4all pail;

    pail.int_val =15;
    std::cout<< "pail.int_val: " << pail.int_val << std::endl;
    std::cout << "pail.double_val: " << pail.double_val << std::endl ;

    pail.double_val = 1.48;
    std::cout<< "pail.int_val: " << pail.int_val << std::endl;
    std::cout << "pail.double_val: " << pail.double_val << std::endl ;

};