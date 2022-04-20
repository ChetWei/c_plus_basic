
#include <iostream>

using namespace std;


const int ArSize = 8;

int sum_arr(int arr[], int n); //声明函数原型
int sum_arr2(const int *begin, const int *end);
int nochange_arr(const int arr[]);


void test() {
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << "cookies: " << cookies << endl;
    cout << "sizeof cookies: " << sizeof cookies << endl;  //sizeof 数组  返回的是数组元素的个数 * 4B = 32个字节

    int sum = sum_arr(cookies, ArSize); //调用函数

    cout << "sum: " << sum << endl;
}

void test2() {
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    cout << "cookies: " << cookies << endl;
    cout << "sizeof cookies: " << sizeof cookies << endl;  //sizeof 数组  返回的是数组元素的个数 * 4B = 32个字节
    //数组名字 + int值，相对于取指定位置元素的地址
    int sum = sum_arr2(cookies, cookies+ArSize); //调用函数

    cout << "sum: " << sum << endl;
}

//测试不可修改数组
void testNoChange() {
    int cookies[ArSize] = {1, 2, 4, 8, 16, 32, 64, 128};
    nochange_arr(cookies);
}

//将数组作为函数的参数，实际上传递是地址值

int sum_arr(int arr[], int n) {
    int total = 0;
    cout << "arr: " << arr << endl;
    cout << "size of arr: " << sizeof arr << endl; //这里的arr是一个指针，那么size of 指针 得到的是指针变量的长度 n个字节
    //所以这里将数组的长度作为参数传入，因为无法用sizeof来获得
    for (int i = 0; i < n; i++) {
        total += arr[i];
    }
    return total;
}

//使用指针变量来接受数组有一样的效果
//另外使用数组结尾的后一个位置， 两个位置决定了数组的区间
int sum_arr2(const int *begin, const int *end) {
    const int *pt;
    int total;
    //判断是否到达末尾的条件,指针（地址）是否相同
    for (pt = begin; pt != end; pt++) {
        cout << "pt: " << pt << endl;
        total += total + *pt;
    }
    return total;
}

//使用const 声明防止数组在方法中被修改
//函数的参数里面声明了const不是要求传入的实参一定要是const，只是防止方法内的修改
int nochange_arr(const int arr[]) {
    cout << "arr[0]: " << arr[0] << endl;
//    arr[0] = 100; //这里修改将会报错
    cout << "arr[0]: " << arr[0] << endl;

    return 0;
}


// 指针和const的关系
void test3(){
    //1、指针指向常量对象，防止使用指针来修改所指向的值
    // 指向const的指针
    int age = 39;
    //这里pt 指向一个 const int 因此不能用pt来修改它的值
    //要注意的是pt的声明，不表示 age就是一个常量，只是对pt指针而言，这个值是一个常量
    //可以用age修改值，但是不能通过 pt来修改
    const int *pt = &age ;
//    *pt = 100; //这将是不允许的

    const float g_moon = 1.63;
    //将一个const常量的地址赋值给一个非const常量的指针，也是不允许的
    //这意味着无法通过 g_moon 本身修改值，但是可以通过指针修改，  荒谬
//    float *pm = &g_moon;




    //2、将指针本身声明为常量，防止改变指针指向的位置
    // const 指针
    int * const ps = &age; //这里的ps指针 只能指向 age的地址

    //3.指向const对象的const指针
    double t = 2.33;
    //ptt只能指向t，而且ptt不能用来修改t的值
    const double * const ptt = &t;

}
