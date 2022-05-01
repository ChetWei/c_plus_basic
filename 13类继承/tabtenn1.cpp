//
//created by chetwei on 2022/5/1 
//
#include "tabtenn1.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) {
    firstname = fn;
    lastname = ln;
    hasTable = ht;
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname << std::endl;
}

//派生类
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tennisPlayer)
        : TableTennisPlayer(tennisPlayer), rating(r) {};


RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht)
        : TableTennisPlayer(fn, ln, ht) {
    rating = r;
}



