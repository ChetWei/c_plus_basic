//
// Created by chetwei on 2022/5/1.
//

#ifndef C_PLUS_BASIC_01一个基类_H
#define C_PLUS_BASIC_01一个基类_H

#include <string>

using std::string;

class TableTennisPlayer {
private:
    string firstname;
    string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const string &fn = "none",
                      const string &ln = "none", bool ht = false);

    void Name() const;

    bool HasTable() const { return hasTable; };

    void RestTable(bool v) { hasTable = v; };

};


//继承基类的派生类
class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const string &fn = "none",
                const string &ln = "none", bool ht = false);

    RatedPlayer(unsigned int r, const TableTennisPlayer &tennisPlayer);

    unsigned int Rating() const { return rating; }

    void ResetRating(unsigned int r) { rating = r; }
};


#endif //C_PLUS_BASIC_01一个基类_H
