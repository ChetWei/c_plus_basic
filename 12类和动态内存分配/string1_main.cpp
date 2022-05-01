//
//created by chetwei on 2022/4/30 
//
#include <iostream>
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

int main() {
    using std::cout;
    using std::cin;
    using std::endl;
    String name;
    cout << "Hi, what's your name? \n";
    cin >> name; //输入名字

    cout << name << ",please enter up to " << ArSize
         << " short sayings <empty line to quit>:\n";

    String sayings[ArSize]; //使用自己定义的String对象，构造数组
    char temp[MaxLen]; //暂时存储

    int i;
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ":";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0')
            break;
        else
            sayings[i] = temp; //拷贝到
    }
    int total = i;
    if (total > 0) {

        cout << "here are your sayings: \n";
        for (i = 0; i < total; i++) {
            cout << sayings[i][0] << ": " << sayings[i] << endl;
        }
        int shortest = 0;
        int first = 0;
        for (i = 1; i < total; i++) {
            if (sayings[i].length() < sayings[shortest].length())
                shortest = i;
            if (sayings[i] < sayings[first])
                first = i;
        }
        cout << "shortest saying:\n" << sayings[shortest] << endl;
        cout << "first alphabetically:\n" << sayings[first] << endl;
        cout << "this program used " << String::HowManyInstance() << " String Instance";
    } else {
        cout << "No input ! Bye. \n";
    }
    return 0;
}