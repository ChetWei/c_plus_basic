
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

