#include "iostream"

using namespace std;


void testAddr() {
    int count1 = 6;
    int count2 = 6;
    cout << "count1-val: " << count1 << endl;
    // 变量前加 & 获取该变量的地址 是用16进制表示的  0x16b1d354c
    cout << "count1-addr: " << &count1 << endl;

    cout << "count2-val: " << count2 << endl;
    // 变量前加 & 获取该变量的地址 是用16进制表示的  0x16fbcf548
    cout << "count2-addr: " << &count2 << endl;
};


void testPoint() {
    int updates = 6;
    int *p_updates; //定义一个指向int类型的指针变量
    p_updates = &updates; // 将int变量的地址赋值给指针变量

    //创建指针变量并且赋值,等价与上面的做法
//    int * p_updates = &updates;

    cout << "value updates: " << updates << endl;
    cout << "p_updates: " << p_updates << endl;
    cout << "*p_updates: " << *p_updates << endl;

    *p_updates += 1;
    cout << "value updates: " << updates << endl;
    cout << "*p_updates: " << *p_updates << endl;
}

void testPoint2() {
    long *fellow; //定义一个指针变量

    *fellow = 243333; //fellow指针没有初始化，不知道24333放在了哪里

    cout << "fellow:" << fellow;
}

//用new来开辟内存，在运行阶段分配

void testNew() {
    int nights = 1001;
    int *pt = new int; //通过new分配内存，用指针指向地址
    long *pl = new long; //通过new分配内存，用指针指向地址
    long  long *pll = new long long; //通过new分配内存，用指针指向地址
    double *pd = new double; //

    *pt = 1001; //在新分配的内存中存储值 1001
    *pl = 1000000000000000111;
    *pll = 1000000000000000111;
    *pd = 1000001.0;

    cout << "nights val: " << nights << endl;
    cout << "nights addr" << &nights << endl;

    cout << "pt_value: " << *pt << endl;
    cout << "pt_location: " << pt << endl;

    cout << "size of pt: " << sizeof pt << endl;
    cout << "size of pl: " << sizeof pl << endl;
    cout << "size of pll: " << sizeof pl << endl;
    cout << "size of pd: " << sizeof pd << endl;

    //释放new 开辟的内存空间
    delete pt;
    delete pl;
    delete pll;
    delete pd;
}

//使用new来创建动态数组
void  testNewArray(){
    int *pt = new int [10]; //创建10个元素的数组，返回第一个元素的指针

    pt[0] = 1;
    pt[1] = 3;
    pt[2] = 5;
    pt[3] = 7;

    cout << "pt: " << *pt << endl; //*pt 取的是数组的第一地址
    //指针数组 可以当做 数组来使用 可以用 pt[index] 来访问里面的每一个元素
    cout << "pt[0]: " << pt[0] << endl;
    cout << "pt[1]: " << pt[1] << endl;
    cout << "pt[2]: " << pt[2] << endl;

    pt = pt + 1; //地址递增 这时指向第二个元素,+1 是以int类型的字节数量为一个单位
    cout << "pt: " << *pt << endl;

    delete [] pt ; // 释放整个数组，而不是第一个元素

}