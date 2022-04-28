#include <iostream>
#include "stock00.h"

int main(){

    //初始化类对象
    Stock stock1 = {"nasa",12,89.0};
    Stock stock2 = Stock ("nansss",14,67.5); //会创建一个临时对象，复制给stock2
    Stock hot_tip {"nas plus",100,56};
    Stock *s =  new Stock("nas --",100,56) ; // 动态构建

    //声明对象数组
    Stock mystuff[4];
    Stock myStocks[3] = {
            Stock(), //使用默认的构造函数
            Stock{"test",12,20.7}, //使用带参数的构造函数
            Stock{"test2",15,60.88}
    };

    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NASA",20,12.5);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(15,18.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(400,20.00);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(40000,12.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(3000,44.00);
    fluffy_the_cat.show();

    return 0;
}
