//
// Created by 魏名安 on 2022/4/29.
//

#ifndef C_PLUS_BASIC_MYTIME0_H
#define C_PLUS_BASIC_MYTIME0_H

class Time {
private:
    int hours;
    int minutes;
public:
    Time();

    Time(int h, int m = 0);

    void AddMin(int m);

    void AddHr(int h);

    void Reset(int h = 0, int m = 0);

    Time Sum(const Time &t) const;

    //重载加法运算符
    Time operator+(const Time &t) const;

    void Show() const;
};

#endif //C_PLUS_BASIC_MYTIME0_H
