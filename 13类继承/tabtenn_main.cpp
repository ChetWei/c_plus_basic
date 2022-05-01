//
//created by chetwei on 2022/5/1 
//
#include <iostream>
#include "tabtenn.h"

int main(){
    using std::cout;

    TableTennisPlayer player1("Chuck","Blizzard", true);
    TableTennisPlayer player2("Tara","Boomdea", false);
    player1.Name();
    if(player1.HasTable()){
        cout << ":has a table \n";
    }else{
        cout << ":hasn't a table \n";
    }

    player2.Name();
    if(player2.HasTable()){
        cout << ":has a table \n";
    }else{
        cout << ":hasn't a table \n";
    }

    return 0;
}