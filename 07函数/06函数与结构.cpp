#include <iostream>

using namespace std;
const int Mins_per_hr = 60;

//定义一个结构体
struct travel_time {
    int hours;
    int minis;
};

travel_time sum(travel_time t1, travel_time t2);

void show_time(travel_time t); //传递结构体的值

void show_time_pt(const travel_time *pt); //传递结构体的地址

void test() {
    travel_time day1 = {5, 60};
    travel_time day2 = {4, 120};
    cout << "day1 addr: " << &day1 << endl;
    cout << "day2 addr: " << &day2 << endl;

    travel_time trip = sum(day1, day2);
    cout << "trip original addr:" << &trip << endl;

    show_time(trip); //传递结构体的副本
    show_time_pt(&trip);  //传递结构体的地址
}


//传递的结构体 按值传递 是一个副本
travel_time sum(travel_time t1, travel_time t2) {
    cout << "t1 addr: " << &t1 << endl;
    cout << "t2 addr: " << &t2 << endl;

    travel_time total;
    total.minis = (t1.minis + t2.minis) % Mins_per_hr;
    total.hours = (t1.hours + t2.hours + t1.minis + t2.minis) / Mins_per_hr;

    return total; //返回一个结构体
}

void show_time(travel_time t) {
    cout << "trip addr in show_time :" << &t << endl;
    cout << "t.hours: " << t.hours << endl;
    cout << "t.minis: " << t.minis << endl;
}

//传递结构的地址而不是结构的副本用来节省时间和空间
void show_time_pt(const travel_time *pt) {
    cout << "trip addr in show_time_pt :" << pt << endl;
    cout << "t.hours: " << pt->hours << endl;
    cout << "t.minis: " << pt->minis << endl;
}

