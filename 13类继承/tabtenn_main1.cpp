//
//created by chetwei on 2022/5/1 
//

#include <iostream>
#include "tabtenn1.h"

int main() {
    using std::cout;

    //使用基类
    TableTennisPlayer player1("Tara", "Boomdea", false);
    //使用派生类
    RatedPlayer ratedPlayer1(1140, "Mallory", "Duck", true);

    ratedPlayer1.Name();
    if (ratedPlayer1.HasTable()) {
        cout << ":has a table \n";
    } else {
        cout << ":hasn't a table \n";
    }

    player1.Name();
    if (player1.HasTable()) {
        cout << ":has a table \n";
    } else {
        cout << ":hasn't a table \n";
    }

    cout << "Name: ";
    ratedPlayer1.Name();
    cout << "; Rating: " << ratedPlayer1.Rating() << std::endl;

    RatedPlayer ratedPlayer2(1212, player1);
    cout << "Name: ";
    ratedPlayer2.Name();
    cout << "; Rating: " << ratedPlayer2.Rating() << std::endl;

    //基类指针 指向 派生类对象 ，基类引用 引用 派生类对象
    RatedPlayer ratedPlayer3(345345, player1);
    TableTennisPlayer &rt = ratedPlayer3; //基类引用
    TableTennisPlayer *pt = &ratedPlayer3; //基类指针
    rt.Name();
    pt->Name();

    return 0;
}