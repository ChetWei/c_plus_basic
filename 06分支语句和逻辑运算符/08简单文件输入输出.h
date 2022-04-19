

#include <iostream>
#include <fstream>

using namespace std;

// 写入文件
void testWrite(){
    char automobile[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;
    outFile.open("carinfo.txt");

    cout << "输入model名字: " << endl;
    cin.getline(automobile,50);

    cout << "输入model year: " << endl;
    cin >> year;

    cout << "原始价格: " << endl;
    cin >> a_price;

    d_price = 0.9 * a_price;

    //控制台输出
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "model名字:" << automobile << endl;
    cout << "year: " << year << endl;
    cout << "原始价格" << a_price << endl;
    cout << "打折价格" << d_price << endl;

    //输出到文件中
    outFile << fixed;
    outFile.precision(2); //设置精度2位小数点
    outFile.setf(ios_base::showpoint);
    outFile << "model名字:" << automobile << endl;
    outFile << "year: " << year << endl;
    outFile << "原始价格" << a_price << endl;
    outFile << "打折价格" << d_price << endl;
    outFile.close();

}

void testRead(){
    ifstream inFile;
    inFile.open("test.txt");
    if(!inFile.is_open()){
        cout << "文件没有成功打开";
        exit(EXIT_FAILURE); //终止程序
    }

    char line[80];
    inFile.getline(line,80);

    cout << "读取的内容:" << line << endl;

    inFile.close(); //关闭文件
}
