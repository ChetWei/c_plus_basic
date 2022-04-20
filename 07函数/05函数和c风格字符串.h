#include <iostream>

using namespace std;


void test(){
    char ghost[15] = "galloping";
    char *str = "galumphing";
    int n1 = strlen(ghost); // strlen() 传入的是字符串的第一个字符的地址,字符串有内置的结束字符可以不用传递长度就可以知道结束位置
    int n2 = strlen(str);
    int n3 = strlen("galloping");

    cout << "strlen(ghost): " << n1 << endl;
    cout << "strlen(str): " << n2 << endl;
    cout << "strlen(\"galloping\"): " << n3 << endl;

}

char * buildstr(char c,int n ) ;

void testBuildStr(){
    char ch ;
    int times;

    cout << "请输入要生成的字符: " << endl;
    cin >> ch;

    cout << "请输入要生成的字符个数: " << endl;
    cin >> times;

    char * ps = buildstr(ch,times);
    cout << "生成结果: " << ps << endl;

    delete [] ps; //ps 指向的是new分配的内存，要进行释放

}

//返回 C风格字符串的函数 ：函数无法直接返回一个字符串，但是可以返回字符串的地址
char * buildstr(char c,int n ){
    char *pstr = new char [n+1]; //new 一个地址块 长度 +1 用来存储 空字符截止
    pstr[n] = '\0';

    while (n-- > 0){
        pstr[n] = c;
    }

    return pstr; //返回一个指针
}