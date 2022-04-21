#include <iostream>

using namespace std;
const int SIZE = 5;

void display(const string sa[], int n);

void test() {
    string mystrs[SIZE]; //定义一个长度为SIZE的 string

    cout << "enter strs:" << endl;
    for (int i=0;i<SIZE;i++){
        cout << i+1 << ":";
        getline(cin,mystrs[i]) ; //将这一行输入赋值给第 i+1个string
    }

    cout << "strs:" << endl;
    display(mystrs,SIZE); //用来显示的函数
}

//传递的是指向string对象的指针
void display(const string sa[], int n) {
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ":" << sa[i] << endl;
    }
}
