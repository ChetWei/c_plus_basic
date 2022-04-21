#include <iostream>

using namespace std;


//用普通的方法声明一个函数
double pam(int);


void test() {
    //声明指向特定类型的函数指针
    double (*pf)(int); // pf指向一个函数  有一个int参数，并且返回double类型
    // (*pf) (int) 是一个指向函数的指针
    // *pf (int) 是一个返回指针的函数

    pf = pam; // 函数的名字就是地址 ，将对应类型的函数指针 指向 这个函数地址

    //通过函数指针来调用函数
    double x = (*pf)(5); // (*pf) 获得函数的内容
    double y = pf(5); //  c++允许像使用函数名一样使用pf

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    //为什么 pf 与 (*pf) 等价？
    //学派一认为：pf是函数指针，*pf是函数，因此将 (*pf)() 用作函数调用
    //学派二认为：函数名是指向该函数的指针，指向函数的指针行为应与函数名相似，，因此将pf()用作函数调用

}

double pam(int x) {
    return x * 0.5;
}

// 函数指针 数组

//定义三个参数和返回值相同的函数
//返回值 为double类型的const指针

const double *f1(const double ar[], int n);

//函数原型中可以省略参数标识符，const double ar[]  等价 const double []
const double *f2(const double [], int n);

//const double ar[] 与 const double *ar 含义相同， const double *ar 可以简化为 const double *
const double *f3(const double *, int n);

void test2() {
    double av[3] = {11.2, 2342.5, 878.55};
    //定义一个函数指针 将 函数名 替换为  (*p1)，并且初始化指向 f1
    const double *(*p1)(const double *, int n) = f1;

    //使用自动类型转换auto来定义函数指针，并初始化
    auto p2 = f2;
    //等价于 const double * (*p2)(const double *,int n) = f2;
    //(*p1)(av,3) 是函数返回值，是一个double类型的指针
    cout << "(*p1)(av,3): " << (*p1)(av, 3) << "\t*(*p1)(av,3): " << *(*p1)(av, 3) << endl;

    cout << "p2(av,3): " << p2(av, 3) << "\t*p2(av,3): " << *p2(av, 3) << endl;

    //使用 函数指针 数组 *pa[3]  []优先级高于 * ,所以*pa[3] 表明pa是一个包含三个指针的数组
    //其中每个指针都指向这样的函数 （返回类型和参数）
    const double *(*pa[3])(const double *, int n) = {f1, f2, f3};
    //使用函数指针数组的时候不能使用auto自动类型转换，auto只适合单值初始化

    //声明了数组pa之后就可以用auto对pa进行自动类型转换了
    auto pb = pa;

    for (int i = 0; i < 3; i++) {
        cout << "pa[i](av,3): " << pa[i](av, 3) << "\t *pa[i](av,3): " << *pa[i](av, 3) << endl;
        cout << "pb[i](av,3): " << pb[i](av, 3) << "\t *pb[i](av,3): " << *pb[i](av, 3) << endl;
    }

    //将整个数组的地址传递给pc ，而不是第一个元素的地址
    //pa为数组，表示地址(第一个元素的地址) = &pa[0] 是一个单个指针的地址
    //&pa 是整个数组（三个指针块的地址），从数字上来说 pa和&pa的值相同，但它们的类型不同
    // pa+1 为数组中下一个元素的地址，而 &pa+1是数组pa后面3*4B=12个字节内存块的地址（假设地址为4B)
    // ** &pa == *pa == pa[0]
    auto pc = &pa;
    cout << "(*pc)[0](av,3): " << (*pc)[0](av, 3) << "\t*(*pc)[0](av,3): " << *(*pc)[0](av, 3) << endl;

    const double *(*(*pd)[3])(const double *, int n) = &pa;
    const double *pdb = (*pd)[1](av, 3); //调用里面的第二个函数进行计算

    cout << "pdb: " << pdb << "\t *pdb: " << *pdb << endl;

    //!!! 使用typedef进行简化，可以用来创建类型别名

    typedef double real ; //可以用real来表示double类型

    typedef const double *(*p_func)(const double *, int); //定义一个函数指针 类型 别名
    p_func pp = f1; // 使用这个别名来简化
    p_func pps[3] = {f1,f2,f3}; //函数指针数组
    p_func (*ppd)[3] = &pps;

}

const double *f1(const double *ar, int n) {
    return ar;
}

const double *f2(const double *ar, int n) {
    return ar + 1;
}

const double *f3(const double *ar, int n) {
    return ar + 2;
}



