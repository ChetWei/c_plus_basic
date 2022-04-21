#include <iostream>
#include <vector> //类似string类，一种动态数组，在运行阶段设置长度，可以在末尾，中间插入数据。自动使用new和delete来管理内存
#include <array> // 对象的长度固定，效率与数组相同，但是更加方便安全
using namespace std;

//动态数组，运行阶段设置长度，可以在末尾和中间插入新数据，用new delete来管理内存
void testVector(){
    vector<int> vi(2); //创建长度为2的一个vector
    vi[0] = 10;
    cout << vi[0] << endl;
}


//array对象长度固定，使用栈（静态内存分配），而不是自由存储区
//效率与数组相同，但是更加方便更安全
void testArray(){
    array<int,5> ai; //创建长度为5的array

    //创建长度为4的array,并且初始化值
    array<double,4> ad = {1.2,1.4,3.4,5.7};

    cout << "ad[0]: "<< ad[0] << endl;
}

void compareVectorArray(){
    double a1[4] = {1.2,2.4,3.6,4.8};

    cout << "a1[0]: " << a1[0] << endl;

    vector<double> a2(4) ; //4个元素的vector
    a2[0] = 1.0/3.0;
    a2[1] = 1.0/5.0;
    a2[2] = 1.0/7.0;
    a2[3] = 1.0/9.0;

    cout << "a2[0]: " << a2[0] << endl;

    array<double,4> a3 = {3.14,2.72,1.62,1.41};
    array<double,4> a4;
    a4 = a3;

    cout << "a3[0]: " << a3[0] << endl;
    cout << "a4[0]: " << a4[0] << endl;

//    a1[-2] = 20.2;  危险的操作，越界操作 ，不会报错
    a2.at(-2) = 20.2 ;  //会捕获到非法索引，导致程序中断
}

//数组、vector、array 对象 都可以用标准数组表示发来访问各个元素
//array对象和数组 存储在相同的内存区域  栈中
//vector 对象存储在另一个区域 自由存储区或堆
// array对象赋值给另外一个array对象，对于数组必须逐个元素复制数据

// 数组的危险操作
// a1[-2] = 20.2;  等价于 *(a1 -2) = 20.2
//找到a1的指向地方，向前移动两个double元素，c和c++都不会检查这种越界行为

//vector 和 array 对象的 标准数组操作方法 也不会对越界操作进行限制
// 可以使用  vector和array的 at() 来防止越界操作
 // a2.at(1) = 2.3  等价于 a2[1] = 2.3
//如果使用  a2.at(-2)  在运行期间会捕获到非法索引，导致程序中断