//
// Created by 魏名安 on 2022/5/2.
//

#ifndef C_PLUS_BASIC_FRIEND_IN_EXTEND_H
#define C_PLUS_BASIC_FRIEND_IN_EXTEND_H


#include <iostream>

using namespace std;

class baseA {
private:
    char *lable;
    int rating;

public:
    baseA(const char *l = "null", int r = 0);

    baseA(const baseA &a);

    virtual ~baseA();

    baseA &operator=(const baseA &a);

    //友元函数，不是成员函数
    friend ostream &operator<<(ostream &os, const baseA &a);
};

class extendB : public baseA {
private:
    char *style;
public:
    extendB(const char *s = "none", const char *l = "null", int r = 0);

    extendB(const char *s, const baseA &a);

    extendB(const extendB &b);

    ~extendB();

    extendB & operator=(const extendB &b);

    friend ostream & operator <<(ostream &os , const extendB &b);

};

#endif //C_PLUS_BASIC_FRIEND_IN_EXTEND_H
