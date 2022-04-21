#include <iostream>

using namespace std;

//函数模板  使用泛型来定义函数参数类型，泛型可以用具体的类型替换

template<class T>
//定义一个泛型为T
//template <template T> //定义一个泛型为T
void myswap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}


void test() {
    int i = 10;
    int j = 20;
    myswap(i, j);
    cout << "i :" << i;
    cout << "\t j :" << j << endl;

    double m = 99.8;
    double n = 12.44;
    myswap(m, n);
    cout << "m :" << m;
    cout << "\t n :" << n << endl;
}

/**************************1.重载的模板*************************/
template<class T>
void Swap(T &a, T &b); //模板1

template<class T>
void Swap(T *a, T *b, int n); //模板2

void Show(int a[]);

const int Lim = 3;

void test2() {
    int i = 10, j = 20;
    cout << "i,j = " << i << "," << j << endl;
    Swap(i, j);
    cout << "i,j = " << i << "," << j << endl;

    int d1[Lim] = {1, 3, 5};
    int d2[Lim] = {2, 4, 6};
    cout << "original arrays:\n";
    cout << "d1:";
    Show(d1);
    cout << "d2:";
    Show(d2);

    Swap(d1, d2, Lim);
    cout << "d1:";
    Show(d1);
}


template<class T>
void Swap(T &a, T &b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template<class T>
//数组参数 a[]和 *a 是一样的效果
void Swap(T a[], T b[], int n) {
    T temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }

}


void Show(int a[]) {
    for (int i = 0; i < Lim; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}


/**************************3.显示具体化*************************/
//多个匹配的函数原型：编译器选择原型顺序
// 非模板函数 > 显示具体化模板函数 >  常规模板函数

struct job {
    char name[40];
    double salary;
    int floor;
};

//声明函数原型 #1
void Swapnew(job &, job &); //引用job类型参数，省略了参数的名字

template<typename T>
void Swapnew(T &, T &);  //#2

// 显示具体化模板 定义使用 template<> 开头 通过名称指定类型
template<>
void Swapnew<job>(job &, job &); //#3

void test3() {
    double u, v;
    Swapnew(u, v);  //使用模板2

    job a, b;
    Swapnew(a, b);  //选择模板 3，因为具体类型匹配
}

/**************************4.实例化和具体化*************************/
//编译器使用模板为特定类型生成函数定义时，得到的是模板实例
//实例化 是指编译器生成特定函数定义
//具体化 特殊版本的用来生成函数定义的方案，编译器不会生成定义
template<typename T>
void swapnn(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

void use_swap(int &a, int &b) {
    swapnn(a, b); //实例化
}

//显示实例化 explicit instantiation
// 显示实例化只需声明不需要重新定义
//编译器根据已有的模板生成int类型的函数定义
template void swapnn<int>(int &a, int &b);


//显示具体化  explicit specialization
// 在 template后面 加 <>
// 显示具体化要重新实现函数的定义
template<>
void swapnn<job>(job &job1, job &job2);
//template <> void swapnn(int &, int &); //与上面的效果相同


template<>
void swapnn<job>(job &job1, job &job2) {
    //todo 使用显示具体化 重新实现函数定义

}

/**************************5.编译器选择使用哪个函数模板*************************/





/**************************6.模板函数的发展*************************/
int x;
decltype(x) y; //已有变量进行类型的推断

template<class T1, class T2>
void ft(T1 x, T2 y) {
    decltype(x + y) xpy = x + y; //xpy为x+y的类型
}

double x1 = 5.5;
double x2 = 7.9;
double &x3 = x1;
const double *pd;

decltype(x1) w; //x为int 类型
decltype(x3) u = x2;  //u是一个double类型的引用 类型
decltype(pd) v; //v是 const double * 指针 类型

decltype( (x1) ) r = x1; // (()) 为引用类型

//使用decltype来设置函数返回值类型
auto h(int x,float y) -> double ;


template<class T1, class T2>
auto ft2(T1 x, T2 y) -> decltype(x + y){
   return x + y;
}
