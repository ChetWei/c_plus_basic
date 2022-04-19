#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

struct inflatable hat;
inflatable goose; //c++ 允许在声明结构体变量时省略关键字struct

//同时完成定义结构和创建结构变量
struct perks {
    int key_number;
    char car[12];
} mr_smith, ms_jones; //创建了两个变量


void testStruct() {
    using namespace std;
    //声明并初始化结构体值
    inflatable guest = {
            "golorious gloria",
            1.88,
            29.99
    };

    cout << "guest.name:" << guest.name << endl;
    cout << "guest.volume:" << guest.volume << endl;
    cout << "guest.price:" << guest.price << endl;

    //结构数组
    inflatable gitfts[100]; //定义100个结构体对象

    //定义结构数组并且初始化
    inflatable guests[2] = {
            {"tom",0.5,21.22},
            {"jack",0.6,22.22}
    };

    cout << "name:" << guests[0].name << endl;
}