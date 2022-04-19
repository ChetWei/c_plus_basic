#include <iostream>

using namespace std;

void test() {

    char ch;
    int count = 0;
    cout << "输入字符，#结束: " << endl;

    cin >> ch;
    while (ch != '#') {
        cout << ch;
        ++count;
        cin >> ch; //cin 会忽略 空格 和 换行符
    }
    cout << endl << count << "读取结束" << endl;

}
