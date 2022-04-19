#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//4.3 string类简介
void stringintroduce() {
//    char charr1[20];
//    char charr2[20] = "hello";
//    string str1 ;
//    string str2 = "hi";
//
//    cin >> charr1 ;
//    cout << "charr1:" << charr1 << endl ;
//
//    cin >> str1 ;
//    cout << "str2:" << str1 << endl ;
//
//    strcpy(charr1,charr2); //copy
//    strcat(charr1,charr2); // charr1 + charr2
//
//    int len1 = strlen(charr1); //字符数组长度 c风格
//    int len2 = str1.size(); //string 长度
//
//    cout << "charr1:" << charr1 << endl;
//    cout << "charr1_length:" << len1 << endl;
//    cout << "str1 length:" << len2 << endl;

    //4.3.1 c++ 字符串初始化
    char first_date[] = {"hello wolrd"};
    char second_date[] = {"hi wolrd"};

    string third_data = {"the bread bowl"};
    string forth_data = {"the bread bowl"};


    //4.3.2 c++ 字符串 赋值、拼接、附加
    char charr1[20];
    char charr2[20] = "hello";
    string str1;
    string str2 = "hi";

//    charr1 = charr2 ; 不能将一个数组赋给另一个数组
    str1 = str2;   //可以将一个string对象赋给另一个string对象
    string str3;
    str3 = str1 + str2; //拼接
    str1 += str2 ;      //附加 str2到str1的末尾

    //4.3.3 string对象.size()  获取string对象的长度

    //string类的io
    cin.getline(charr1,20); //获取字符数组的输入
    getline(cin,str1) ; //获取string对象的输入

}
