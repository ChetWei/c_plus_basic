#include <iostream>

using namespace std;

//cin 读取char值，与读取其他基本类型一样，cin将忽略空格和换行符

void test() {

    char ch;
    int count = 0; //统计输入的次数
    cout << "输入字符，#结束: " << endl;

    cin >> ch;
    while (ch != '#') {
        cout << ch; //打印
        ++count;
        cin >> ch; //cin 会忽略 空格 和 换行符
    }
    cout << endl << count << "读取结束" << endl;

}
