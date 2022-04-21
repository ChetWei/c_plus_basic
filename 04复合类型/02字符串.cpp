#include <iostream>


using namespace std;
//4.2字符串
//存储在内存中你的连续字节中的一系列字符
//1.来自C语言风格的字符串
//2.基于string类库的方法
void mystring() {

    char a = 65; //单引号表示的是字符常量 'a' 是ASCII编码 65的另外一种写法
    char aa = 'a'; //单引号表示的是字符常量 'a' 是ASCII编码 65的
    cout << a << endl;
    cout << aa << endl;

    // char s = "s";  这是非法的 "s"不是字符常量，它表示的是两个字符 s 和 \0 组成的字符串
    //而且 "s"表示的是字符串所在的内存地址，它表示将一个内存地址赋值给s


    //1.来自C语言风格的字符串
    char cat[4] = {'c', 'a', 't'};
    char dog[4] = {'d', 'o', 'g', '\0'}; //c风格字符串以空字符结尾 '\0' ASCII码为0
    //两个都是char数组，但是只有第二个数组是字符串。在输出过程中空字符结尾；
    // 如果没有，那么会在内存中一步步往下寻找空字符，找到后停止

    cout << cat << endl;
    cout << dog << endl;


    char bird[7] = "hello"; //引号引起字符串，隐式地包含了结尾的空字符，要保证数组长度够长,
    // 如果有多余的长度默认填充为空字符

    char fish[] = "hi"; //自动计算长度

    cout << bird << endl;
    cout << fish << endl;


    //1.拼接字符串常量
//    cout << "hello" "world" << endl ;

    //2.在数组中使用字符串
//    const int Size = 15;
//    char name1[Size];
//    cin >> name1 ;
//    cout << "hi " << name1 << endl ;
//    // strlen() 计算数组中可见元素个数，不计算空字符
//    cout << "name1 length: " <<strlen(name1) << endl;
//    // strlen() 计算整个数组的长度 字节
//    cout << "name1 sizof: " << sizeof name1 << endl ;
//
//    char name2[Size] = "C++owboy \n";
//    cout << "howdy i'm " << name2 ;



    //3.字符串输入
//    char name[20];
//    cout << "enter your name: " << endl;
//    cin >> name; //读取用户输入的字符串
//
//    cout << "hello " << name << endl;

    //4每次读取一行字符的输入
    //面向行的输入  getline()  换行符结束 换行符不会添加到数组里

    char name[20];
    char content[10];
    //读取的字符最长是19个，剩下空间用于存储自动在结尾处添加的空字符
//    cin.getline(name,20);
//    cout << name << endl;


    //面向行的输入  get() 将换行符添加到数组里面
    cin.get(name, 20); //调用后换行符保留在队列中，第二次调用get获得的第一个字符就是换行符
    cin.get(); //消除掉上一行的回车内容
    cin.get(content, 10);

    cout << "name:" << name << endl;
    cout << "content:" << content << endl;
}
