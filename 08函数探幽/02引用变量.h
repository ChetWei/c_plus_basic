#include <iostream>

using namespace std;


/*********1.创建引用变量*****************/
void test1() {
    int rats = 100;
    int &rodents = rats; //将 rodents 作为 rats变量的别名；
    // &不是地址运算符，而是类型标识符的一部分，就像char*是指向char的指针一样，&int指的是指向int的引用
    // 但是rodents和rats都是指向相同的地址，所以引用变量和变量的地址是相同的

    //** 声明引用变量的时候必须进行初始化操作，不能分开
//    int &rodent2;
//    rodent2 = rats;


    int *pt1 = &rodents;
    int *pt2 = &rats;

    cout << "rats= " << rats << endl;
    rodents++;
    cout << "rats= " << rats << endl;
    rats++;
    cout << "rodents= " << rodents << endl;

    cout << "rats address: " << &rats << endl;
    cout << "rodents address: " << &rodents << endl; //这里的&是地址运算符
    cout << "pt1: " << *pt1 << endl;

    cout << "pt1 address: " << pt1 << endl;
    cout << "pt2 address: " << pt2 << endl;

    cout << "can we change the reference ?" << endl;
    //已经引用变量可以修改吗？
    int newb = 200;
    rodents = newb; //将已经拥有的变量进行修改
    cout << "rodents= " << rodents << endl;
    cout << "rats= " << rats << endl;
    cout << "pt1: " << *pt1 << endl;
    cout << "pt1 address: " << pt1 << endl;
    cout << "newb address：" << &newb << endl;

    //改变引用变量，只是将引用变量的地址上的值进行了修改
    //这里 rodents的地址不变，将地址上的值从100修改为200

}

/*********2.在函数中使用引用传递*****************/
void myswap1(int &a, int &b);

void myswap2(int *p, int *q);

void myswap3(int a, int b);

void test2() {
    int wallet1 = 200;
    int wallet2 = 300;
    cout << "---before swap1:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;

    //使用引用变量作为参数，直接将变量传入
    myswap1(wallet1, wallet2);
    cout << "---after swap1:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;


    cout << "---before swap2:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;
    //使用指针变量的参数，传递地址进去
    myswap2(&wallet1, &wallet2);
    cout << "---after swap2:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;

    cout << "---before swap3:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;
    //一般的值传递，可以发现没有交换，只是副本
    myswap3(wallet1, wallet2);
    cout << "---after swap3:";
    cout << "wallet1: $" << wallet1;
    cout << "\twallet2: $" << wallet2 << endl;
}

//使用引用变量作为函数参数
void myswap1(int &a, int &b) {

    cout << "address a: " << &a;
    cout << "\taddress b: " << &b << endl;
    int temp;
    temp = a;
    a = b;
    b = temp;

    cout << "address a: " << &a;
    cout << "\taddress b: " << &b << endl;
    //可以发现改变了原来地址上的值
}

void myswap2(int *p, int *q) {

    int temp;
    temp = *p;
    *p = *q;
    *q = temp;
}

void myswap3(int a, int b) {

    int temp;
    temp = a;
    a = b;
    b = temp;
}


/************3.临时变量、引用参数、和const*************/
//接受常量引用参数
double refcube(const double &ra) {
    return ra * ra * ra;
}

void test3() {
    double side = 3.0;
    double *pd = &side;
    double &rd = side;
    long edge = 5L;
    double lens[3] = {3.0, 4.6, 6.0};

    double c1 = refcube(side);
    double c2 = refcube(*pd);
    double c3 = refcube(rd);
    double c4 = refcube(lens[0]);

    //todo 函数引用参数使用const声明：可以避免修改数据；可以正确生成并使用临时变量
    //实参edge是变量，但是类型不正确，形参 类型转换为 临时变量；
    double c5 = refcube(edge);
    //类型正确，但是没有名称；形参 类型转换为 临时变量
    double c6 = refcube(8.0);
    //类型正确，但是没有名称；形参 类型转换为 临时变量
    double c7 = refcube(side + 2.0);

    //临时变量在调用的时候使用，调用结束后被消失，对临时变量的修改无法影响到实参

}


/************4.将引用用于结构*************/
struct free_throws {
    string name;
    int made;
    float percent;
};

//对结构的引用
void set_pc(free_throws &ft) {
    //修改结构体李的值
    ft.percent = 100.0 * ft.percent;
}

//使用 const 防止修改
void display(const free_throws &ft) {
    cout << "------display--------" << endl;
    cout << "name: " << ft.name << endl;
    cout << "made: " << ft.made << endl;
    cout << "percent: " << ft.percent << endl;
}

//返回一个 free_throws的引用
free_throws &accumulate(free_throws &target, const free_throws &source) {
    target.made += source.made;
    target.percent += source.percent;
    set_pc(target); //修改percent

    //返回第一个参数的引用
    return target;
}

void test4() {

    free_throws one = {"one", 13, 100.0};
    free_throws two = {"two", 16, 90.0};

    free_throws dup;

    display(one);
    set_pc(one); //使用引用来修改结构体的值
    display(one);

    accumulate(one, two);
    display(one);

    //因为accumulate返回的是一个结构体的引用，再次传入给其他函数
    set_pc(accumulate(one, two));

    display(one);
}

//返回引用时候要注意的问题
const free_throws &clone2(free_throws &ft) {
    free_throws newguy;
    newguy = ft; //结构体的赋值是属性拷贝，不是地址
    return newguy; // todo 返回的结构体引用是一个函数里面的临时变量，函数结束后将消失
}

//可以使用指针来解决上面的问题
const free_throws &clone(free_throws &ft) {
    free_throws *pt; //结构体指针
    *pt = ft; //拷贝属性

    return *pt; //返回拷贝内容
    // todo 返回的指针空间使用之后可能会忘记 delete来释放
}

/************5.将引用用于类对象*************/
//参数使用 string 类对象的 引用
//三个函数的功能 返回 s2 + s1 + s2 的结果

//返回一个string对象
string version1(const string &s1, const string &s2);

// 返回一个const的 string 引用
const string &version2(string &s1, const string &s2); //有问题

// 返回一个const的 string 引用
const string &version3(string &s1, const string &s2); //有问题

void test5() {
    string a = "hello";

    //Q:"内容" 是c风格字符串却用作了string 对象引用参数
    //A:string类定义了一种char* 到string的转换功能，使得可以用c风格字符串来初始化string对象；
    //前面讲过 const引用的形参 如果类型不匹配会自动进行类型转换 为临时变量
    string result1 = version1(a,"@@@");
    cout << "reslut1: " << result1 << endl;

    //resutl2就是a的引用
    string result2 = version2(a,"###");
    cout << "result2: " << result2 << endl;

    string result3 = version3(a,"$$$");
    cout << "result3: " << result3 << endl;

}

//返回一个string的新对象，在主函数中接受这个对象
string version1(const string &s1, const string &s2) {
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

//这里直接对传入的s1的引用进行了修改，再返回s1
//会改变s1的原始值
const string &version2(string &s1, const string &s2) {
    s1 = s2 + s1 + s2;
    return s1;
}

//函数返回的是一个string的引用，而不是一个string的对象
const string &version3(string &s1, const string &s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp;  //todo 此时的 string是一个函数内的临时变量，返回对它的引用，不久后这个地址会被释放 不安全
}

/************6.对象、继承、和引用*************/




/************7.何时使用引用参数*************/

//使用引用参数的原因：
// ✅️ 需要修改调用函数中的数据对象
// ✅ 使用传递引用而不是整个数据对象的副本，提高程序运行速度

//使用传递的值但是不修改
// ✅ 数据对象很小，内置数据或小型数据，按值传递
// ✅ 如果对象是数组，则只能使用指针
// ✅ 如果对象较大的结构，使用const指针或const 引用，可以提高程序效率，节省时间空间
// ✅ 如果对象是类对象，使用const引用

//对于修改调用函数中的数据
// ✅️ 数据对象是内置数据类型，使用指针
// ✅️ 数据对象是数组，只能使用指针
// ✅️ 数据对象是结构，使用引用或指针
// ✅️ 数据对象是类对象，使用引用


