#include "iostream"

using namespace std;

void test() {

    double wages[3] = {10000.0, 20000.0, 30000.0};
    short stacks[3] = {3, 2, 1};

    double *pd = wages; //数组名字默认为第一个元素的地址
    short *ps = &stacks[0]; //将第一个元素的地址赋值给 ps



    cout << "pd[1]: " << *(pd + 1) << endl;
    cout << "ps[0]: " << ps[0] << endl;

    //size of 数组 表示的是数组的长度 3个元素 * 8B类型 = 24
    cout << "size of wages: " << sizeof wages << endl;

    //size of
    cout << "size of wages[0]: " << sizeof wages[0] << endl;

    //size of 指针 表示的是指针的长度  8B
    cout << "size of point pd: " << sizeof pd << endl;
}


void pointAndChar() {

    char flower[10] = "rose";
    const char *bird = "wren"; //将字符串第一个元素的起始地址赋值给指针变量
    char *ps;

    cout << "flower: " << flower << endl;
    cout << "bird: " << bird << endl;

    ps = flower;
    //ps指针的第一个char元素地址, cout 将输出这个字符，如果是其他类型的地址将输出地址
    cout << "*(ps): " << *(ps) << endl;
    // 用cout 来输出char字符的地址
    cout << "ps start addr:" << (int *) ps << endl;

    //输出 ps地址开始一直遇到空字符结束
    cout << "ps: " << ps << endl;

    ps = new char[strlen(flower) + 1]; //开辟一个内存空间， +1 用来存储空字符
    strcpy(ps, flower); //将数组中的内容复制到新分配的空间中去 ps=flower是不行的，因为这样是给变了ps的指向
    cout << "new ps: " << ps << endl;

    delete[] ps; //释放指向通过new开辟的内存
}

//结构体指针
void testStructPoint() {
    //定义结构体
    struct inflatable {
        char name[20];
        double price;
    };

    inflatable *ps = new inflatable; //动态分配一块足够的内存给ps
    cout << "input inflatable name:" << endl;
    cin.get(ps->name, 20); //ps是指针（地址）,通过 ->属性 来访问
    cout << "input inflatable price:" << endl;
    cin >> (*ps).price; //(*ps) 是一个结构对象，通过 .属性 来访问

    cout << "name:" << (*ps).name << endl;
    cout << "price:" << ps->price << endl;

    delete ps; //释放new开辟的内存
}



//返回一个指针指向字符串
char *getname() {
    char temp[80]; //定义一个长度80的字符数组
    cout << "输入名字: ";
    cin >> temp;

    //根据填入字符数组的长度用new来开辟合适的空间
    char *pn = new char[strlen(temp) + 1]; //+1 用来存储空字符
    strcpy(pn,temp);

    return pn;
}

//根据输入的字符长度动态分配内存空间
void testDynamicAllocationArray(){
    char *name;
    //调用方法
    name = getname();
    cout << name << " at " << (int *) name << endl;
    delete [] name; //name 指向了一个字符数组
}


