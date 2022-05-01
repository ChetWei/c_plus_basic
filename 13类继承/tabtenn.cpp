//
//created by chetwei on 2022/5/1 
//
#include "tabtenn.h"
#include <iostream>

TableTennisPlayer::TableTennisPlayer(const string &fn, const string &ln, bool ht) {
    firstname = fn;
    lastname = ln;
    hasTable = ht;
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}